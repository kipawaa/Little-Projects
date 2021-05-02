#include"loadBMP.h"

GLuint loadBMP(char* filename) {
        char header[54]; // BMP header info
        int dataPos; // position where BMP pixel data starts
        int width; // width of the BMP
        int height; // height of the BMP
        int imageSize; // total size of BMP
        char* data; // actual pixel data

        // open BMP file
        FILE* image = fopen(filename, "r");
        if (!image) {
                perror("error opening BMP");
                exit(1);
        }

        // attempt to read BMP header
        if (fread(header, 1, 54, image) != 54) {
                perror("error reading BMP header");
                exit(1);
        }

        // make sure file is a BMP file
        if (header[0] != 'B' || header[1] != 'M') {
                perror("file is not BMP");
                exit(1);
        }

        // read file metadata
        dataPos = (int)header[0x0A];
        width = (int)header[0x12];
        height = (int)header[0x16];
        imageSize = (int)header[0x22];

        // if BMP is incorrectly formatted we can guess the following info because it is standardized
        if (dataPos == 0) dataPos = 54;
        if (imageSize == 0) imageSize = 3 * width * height; // RGB for each pixel
        
        // read image data
        data = (char *)calloc(imageSize, sizeof(char));
        fread(data, 1, imageSize, image);

        // close the file now that we're done reading
        fclose(image);

        // create texture ID
        GLuint textureID;
        glGenTextures(1, &textureID);

        // bind texture ID to openGL texture
        glBindTexture(GL_TEXTURE_2D, textureID);

        // copy data into openGL memory
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

        // makes opengl sampling from the image a bit cleaner or something like that
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        // free our version of file data now that OpenGL has it
        free(data);

        return textureID;
}
