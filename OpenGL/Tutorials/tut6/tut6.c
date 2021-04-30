#include"tut6.h"

int main() {
        float screenWidth = 1920.0f;
        float screenHeight = 1080.0f;

        float lastTime;
        float currentTime = glfwGetTime();

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
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        
        glfwPollEvents();

        // default background colour
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        // enable depth checking so that things further away are drawn behind things that are closer (or not drawn at all)
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        // load shader program
        GLuint programID = loadShaders("vertexShader.glsl", "fragmentShader.glsl");

        // create projection matrix
        mat4 projection;
        glm_perspective(M_PI/4.0f, screenWidth / screenHeight, 0.1f, 100.0f, projection);

        // create camera matrix
        mat4 camera;
        vec3 eye = {0.0f, 0.0f, 3.0f};
        vec3 center = {0.0f, 0.0f, 0.0f};
        vec3 up = {0.0f, 1.0f, 0.0f};

        glm_lookat(eye, center, up, camera);

        // create model translation matrix (identity for this tutorial)
        mat4 model = GLM_MAT4_IDENTITY_INIT;

        // create a Vertex Array Object (VAO)
        GLuint vertexArrayID;
        glGenVertexArrays(1, &vertexArrayID);
        glBindVertexArray(vertexArrayID);

        // overall adjustment matrix
        mat4 pvm;
        mat4* matrixArray[3] = {&projection, &camera, &model};
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

        // create buffer for the cube
        GLuint vertexBuffer;
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data, GL_STATIC_DRAW);

        // Colour data for the triangle
        static const GLfloat colourData[] = {
            0.583f,  0.771f,  0.014f,
            0.609f,  0.115f,  0.436f,
            0.327f,  0.483f,  0.844f,
            0.822f,  0.569f,  0.201f,
            0.435f,  0.602f,  0.223f,
            0.310f,  0.747f,  0.185f,
            0.597f,  0.770f,  0.761f,
            0.559f,  0.436f,  0.730f,
            0.359f,  0.583f,  0.152f,
            0.483f,  0.596f,  0.789f,
            0.559f,  0.861f,  0.639f,
            0.195f,  0.548f,  0.859f,
            0.014f,  0.184f,  0.576f,
            0.771f,  0.328f,  0.970f,
            0.406f,  0.615f,  0.116f,
            0.676f,  0.977f,  0.133f,
            0.971f,  0.572f,  0.833f,
            0.140f,  0.616f,  0.489f,
            0.997f,  0.513f,  0.064f,
            0.945f,  0.719f,  0.592f,
            0.543f,  0.021f,  0.978f,
            0.279f,  0.317f,  0.505f,
            0.167f,  0.620f,  0.077f,
            0.347f,  0.857f,  0.137f,
            0.055f,  0.953f,  0.042f,
            0.714f,  0.505f,  0.345f,
            0.783f,  0.290f,  0.734f,
            0.722f,  0.645f,  0.174f,
            0.302f,  0.455f,  0.848f,
            0.225f,  0.587f,  0.040f,
            0.517f,  0.713f,  0.338f,
            0.053f,  0.959f,  0.120f,
            0.393f,  0.621f,  0.362f,
            0.673f,  0.211f,  0.457f,
            0.820f,  0.883f,  0.371f,
            0.982f,  0.099f,  0.879f
        };

        GLuint colourBuffer;
        glGenBuffers(1, &colourBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colourData), colourData, GL_STATIC_DRAW);

        // while the window is open and the enter key is not pressed
        while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0) {
                // update timing
                lastTime = currentTime;
                currentTime = glfwGetTime();
                updateMatricesFromControls(window, &projection, &camera, &model, currentTime - lastTime);
                glm_mat4_mulN(matrixArray, 3, pvm);

                // clear the colour buffer and depth buffer
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                // apply the shader program
                glUseProgram(programID);

                // apply adjustment matrix
                glUniformMatrix4fv(pvmID, 1, GL_FALSE, pvm[0]);

                // draw the cube
                glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
                glEnableVertexAttribArray(0);
                glDrawArrays(GL_TRIANGLES, 0, 36);  // 36 vertices in a cube made of triangles
                glDisableVertexAttribArray(0);

                // add the colours
                glEnableVertexAttribArray(1);
                glBindBuffer(GL_ARRAY_BUFFER, colourBuffer);
                glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

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
