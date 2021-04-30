#include<stdio.h>
#include<stdlib.h>

#include<GL/glew.h>
#include<GLFW/glfw3.h>

// CGLM includes
#include<cglm/cglm.h>
#include<cglm/cam.h>
#include<cglm/vec3.h>
#include<cglm/mat4.h>


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

        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);

        return programID;
}

int main() {
        float screenWidth = 1920.0f;
        float screenHeight = 1080.0f;
        glewExperimental = 1;

        // initialize GLFW
        if (!glfwInit()) {
                perror("glfw initialization error");
                exit(1);
        }

        // startup settings
        glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialising
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // this line and the one below get us OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // tells macos to be quiet about being outdated
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // sets core profile (as opposed to compatibility)

        // open a window and set up context
        GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "Tutorial 1", NULL, NULL);

        if (!window) {
                glfwTerminate();
                perror("window creation error");
                exit(1);
        }

        glfwMakeContextCurrent(window);

        if (glewInit() != GLEW_OK) {
                perror("glew initialization error");
                glfwTerminate();
                exit(1);
        }

        // input settings
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

        // default background colour
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        // load shader program
        GLuint programID = loadShaders("vertexShader.glsl", "fragmentShader.glsl");

        // create projection matrix
        mat4 projection;
        glm_perspective(3.1415926/4, screenWidth / screenHeight, 0.1f, 100.0f, projection);

        // create camera matrix
        mat4 camera;
        vec3 eye = {4.0f, 3.0f, 3.0f};
        vec3 center = {0.0f, 0.0f, 0.0f};
        vec3 up = {0.0f, 1.0f, 0.0f};

        glm_lookat(eye, center, up, camera);

        // create model translation matrix (identity for this tutorial)
        mat4 translation = GLM_MAT4_IDENTITY_INIT;

        // create a Vertex Array Object (VAO)
        GLuint vertexArrayID;
        glGenVertexArrays(1, &vertexArrayID);
        glBindVertexArray(vertexArrayID);

        // overall adjustment matrix
        mat4 pvm;
        mat4* matrixArray[3] = {&projection, &camera, &translation};
        glm_mat4_mulN(matrixArray, 3, pvm);

        for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                        printf("%f, ", pvm[i][j]);
                }
                printf("\n");
        }

        // get GL ID for adjustment matrix
        GLuint pvmID = glGetUniformLocation(programID, "PVM");

        // create 3 vertices
        static const GLfloat vertex_data[] = {
                -1.0f, -1.0f, 0.0f,
                1.0f, -1.0f, 0.0f,
                0.0f, 1.0f, 0.0f,
        };

        // create buffer for the triangle
        GLuint vertexBuffer;
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

        // while the window is open and the enter key is not pressed
        while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0) {
                // clear the screen
                glClear(GL_COLOR_BUFFER_BIT);

                // apply the shader program
                glUseProgram(programID);

                // apply adjustment matrix
                glUniformMatrix4fv(pvmID, 1, GL_FALSE, pvm[0]);

                // draw the triangle
                glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
                glEnableVertexAttribArray(0);
                glDrawArrays(GL_TRIANGLES, 0, 3); // draw triangles from vertex 0 to vertex 3
                glDisableVertexAttribArray(0);

                // swap buffers
                glfwSwapBuffers(window);
                glfwPollEvents();
        }

        // clean up

        glDeleteBuffers(1, &vertexBuffer);
        glDeleteVertexArrays(1, &vertexArrayID);
        glDeleteProgram(programID);

        glfwTerminate();

}
