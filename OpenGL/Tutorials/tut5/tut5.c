#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glew.h>
#include<GLFW/glfw3.h>

// CGLM includes
#include<cglm/cglm.h>
#include<cglm/cam.h>
#include<cglm/vec3.h>
#include<cglm/mat4.h>

#include"loadShaders.h"
#include"loadBMP.h"

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

        // enable depth checking so that things further away are drawn behind things that are closer (or not drawn at all)
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        // load shader program
        GLuint programID = loadShaders("vertexShader.glsl", "fragmentShader.glsl");

        // create projection matrix
        mat4 projection;
        glm_perspective(M_PI/4, screenWidth / screenHeight, 0.1f, 100.0f, projection);

        // create camera matrix
        mat4 camera;
        vec3 eye = {4.0f, 3.0f, 3.0f};
        vec3 center = {0.0f, 0.0f, 0.0f};
        vec3 up = {0.0f, 1.0f, 0.0f};

        glm_lookat(eye, center, up, camera);

        // create model translation matrix (identity for this tutorial)
        mat4 translation = GLM_MAT4_IDENTITY_INIT;

        // overall adjustment matrix
        mat4 pvm;
        mat4* matrixArray[3] = {&projection, &camera, &translation};
        glm_mat4_mulN(matrixArray, 3, pvm);

        // get GL ID for adjustment matrix
        GLuint pvmID = glGetUniformLocation(programID, "PVM");

        // create 3 vertices
        static const GLfloat vertex_data[] = {
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            -1.0f,-1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            -1.0f,-1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f,-1.0f,
            1.0f,-1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f,-1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f,-1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f, 1.0f, 1.0f,
            -1.0f, 1.0f, 1.0f,
            1.0f,-1.0f, 1.0f
        };

        // create a Vertex Array Object (VAO)
        GLuint vertexArrayID;
        glGenVertexArrays(1, &vertexArrayID);
        glBindVertexArray(vertexArrayID);
        
        // create buffer for the cube
        GLuint vertexBuffer;
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

        // Colour data for the triangle
        static const GLfloat textureData[] = {
                0.000059f, 1.0f-0.000004f,
                0.000103f, 1.0f-0.336048f,
                0.335973f, 1.0f-0.335903f,
                1.000023f, 1.0f-0.000013f,
                0.667979f, 1.0f-0.335851f,
                0.999958f, 1.0f-0.336064f,
                0.667979f, 1.0f-0.335851f,
                0.336024f, 1.0f-0.671877f,
                0.667969f, 1.0f-0.671889f,
                1.000023f, 1.0f-0.000013f,
                0.668104f, 1.0f-0.000013f,
                0.667979f, 1.0f-0.335851f,
                0.000059f, 1.0f-0.000004f,
                0.335973f, 1.0f-0.335903f,
                0.336098f, 1.0f-0.000071f,
                0.667979f, 1.0f-0.335851f,
                0.335973f, 1.0f-0.335903f,
                0.336024f, 1.0f-0.671877f,
                1.000004f, 1.0f-0.671847f,
                0.999958f, 1.0f-0.336064f,
                0.667979f, 1.0f-0.335851f,
                0.668104f, 1.0f-0.000013f,
                0.335973f, 1.0f-0.335903f,
                0.667979f, 1.0f-0.335851f,
                0.335973f, 1.0f-0.335903f,
                0.668104f, 1.0f-0.000013f,
                0.336098f, 1.0f-0.000071f,
                0.000103f, 1.0f-0.336048f,
                0.000004f, 1.0f-0.671870f,
                0.336024f, 1.0f-0.671877f,
                0.000103f, 1.0f-0.336048f,
                0.336024f, 1.0f-0.671877f,
                0.335973f, 1.0f-0.335903f,
                0.667969f, 1.0f-0.671889f,
                1.000004f, 1.0f-0.671847f,
                0.667979f, 1.0f-0.335851f
        };

        // get texture from BMP
        GLuint texture = loadBMP("uvtemplate.bmp");

        // get a new uniform sampler for the texture
        GLuint textureID = glGetUniformLocation(programID, "textureSampler");

        // generate, bind and load texture buffer
        GLuint textureBuffer;
        glGenBuffers(1, &textureBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(textureData), textureData, GL_STATIC_DRAW);

        // while the window is open and the escape key is not pressed
        while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0) {
                // clear the colour buffer and depth buffer
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                // apply the shader program
                glUseProgram(programID);

                // send adjustment matrix to shaders
                glUniformMatrix4fv(pvmID, 1, GL_FALSE, pvm[0]);

                // Bind texture
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, texture);
                glUniform1i(textureID, 0);

                // send the vertices to shaders
                glEnableVertexAttribArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

                // send the texture to shaders
                glEnableVertexAttribArray(1);
                glBindBuffer(GL_ARRAY_BUFFER, textureBuffer);
                glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

                // draw!
                glDrawArrays(GL_TRIANGLES, 0, 36);  // 36 vertices in a cube made of triangles
                
                glDisableVertexAttribArray(0);
                glDisableVertexAttribArray(1);
                
                // swap buffers
                glfwSwapBuffers(window);
                glfwPollEvents();
        }

        // clean up
        glDeleteBuffers(1, &vertexBuffer);
        glDeleteBuffers(1, &textureBuffer);
        glDeleteVertexArrays(1, &vertexArrayID);
        glDeleteTextures(1, &texture);
        glDeleteProgram(programID);

        glfwTerminate();

}
