#include"loadBMP.h"

GLuint loadBMP(char* path) {
        char header[54];
        int dataPos;
        int width;
        int height;
        int imageSize;
        char* data;

        FILE* file = fopen(path, "rb");
        if (!file) {
                perror("file opening error");
                exit(0);
        }

        if (fread(header, 1, 54, file) != 54) {
                perror("BMP file header is incorrect");
                exit(0);
        }

        if (header[0] != 'B' || header[1] != 'M') {
                perror("BMP file header is incorrect");
                exit(0);
        }

        dataPos = header[0x0A];
        imageSize = header[0x22];
        width = header[0x12];
        height = header[0x26];

        data = (char*)calloc(imageSize, sizeof(char));
        
        fread(data, 1, imageSize, file);
        fclose(file);

        GLuint textureID;
        glGenTextures(1, &textureID);

        glBindTexture(GL_TEXTURE_2D, textureID);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        free(data);

        return textureID;
}
