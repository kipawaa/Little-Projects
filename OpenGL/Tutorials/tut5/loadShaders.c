#include"loadShaders.h"

GLuint loadShaders(char* vertexShaderPath, char* fragmentShaderPath) {
        // read vertex shader from file
        FILE* vertexShaderFile = fopen(vertexShaderPath, "r");
        char vertexShader[1024] = {'\0'};
        if (!vertexShaderFile) {
                perror("vertex shader not found");
                exit(1);
        }

        fread(vertexShader, sizeof(char), sizeof(vertexShader), vertexShaderFile);

        // close vertex shader file
        fclose(vertexShaderFile);

        // compile vertex shader
        char const* vertexSourcePointer = vertexShader;
        GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShaderID, 1, &vertexSourcePointer, NULL);
        glCompileShader(vertexShaderID);

        // check the shaders' compile status
        // check vertex shader
        GLint success = GL_FALSE; // default to failure, the program will change it if things work properly
        GLint logLength = 0;
        glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
        if (!success) {
                // get the size of the error log
                glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &logLength);
                logLength += 512;
                // get the error log itself
                GLchar errorMessage[logLength];
                glGetShaderInfoLog(vertexShaderID, logLength, NULL, errorMessage);
                
                // print the errors
                perror("vertex shader compilation error");
                printf("shader info log: %s\n", errorMessage);
        }        

        // read fragment shader from file
        FILE* fragmentShaderFile = fopen(fragmentShaderPath, "r");
        char fragmentShader[1024] = {'\0'};
        if (!fragmentShaderFile) {
                perror("fragment shader not found");
                exit(1);
        }

        fread(fragmentShader, sizeof(char), sizeof(fragmentShader), fragmentShaderFile);

        // close fragment shader file
        fclose(fragmentShaderFile);

        // compile fragment shader
        GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
        char const* fragmentSourcePointer = fragmentShader;
        glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer, NULL);
        glCompileShader(fragmentShaderID);

        // check fragment shader
        glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
        if (!success) {
                glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &logLength);
                GLchar errorMessage[logLength];
                glGetShaderInfoLog(fragmentShaderID, logLength, NULL, errorMessage);
                perror("fragment shader compilation error");
                printf("shader info log: %s\n", errorMessage);
        }


        // link the shaders
        GLuint programID = glCreateProgram();
        glAttachShader(programID, vertexShaderID);
        glAttachShader(programID, fragmentShaderID);
        glLinkProgram(programID);

        // check program link
        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success) {
                glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &logLength);
                GLchar errorMessage[logLength+1];
                glGetProgramInfoLog(programID, logLength, NULL, errorMessage);
                perror("program linking error");
                printf("%s\n", errorMessage);
        }

        // clean up??? no explanation here, need to research
        glDetachShader(programID, vertexShaderID);
        glDetachShader(programID, fragmentShaderID);

        return programID;
}
