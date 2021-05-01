#include"controls.h"

// get window size
int screenWidth;
int screenHeight;

// position
vec3 position = {0, 0, 0};
vec3 delta;

// view angles
float horizontalAngle = M_PI;
float verticalAngle = 0.0f;

// FOV
float FOV = M_PI / 4.0f;

// movement and mouse sensitivity
float speed = 5.0f;
float mouseSpeed = 0.05f;

// mouse position
double mousePosition[2];

void updateMatricesFromControls(GLFWwindow* window, mat4* projection, mat4* camera, mat4* model, float deltaTime) {
        // get window size
        glfwGetWindowSize(window, &screenWidth, &screenHeight);
        
        // get new mouse position
        glfwGetCursorPos(window, &mousePosition[0], &mousePosition[1]);

        // update viewing angle based on mouse movements
        horizontalAngle += mouseSpeed * deltaTime * (screenWidth/2 - mousePosition[0]);
        verticalAngle += mouseSpeed * deltaTime * (screenHeight/2 - mousePosition[1]);

        // reset mouse position to the center of the screen
        glfwSetCursorPos(window, screenWidth/2, screenHeight/2);

        // compute view viewDirection vector
        vec3 viewDirection = {cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle), cos(verticalAngle) * cos(horizontalAngle)};

        // compute right viewDirection vector
        vec3 right = {sin(horizontalAngle - M_PI / 2.0f), 0, cos(horizontalAngle - M_PI / 2.0f)};
        
        // compute up vector
        vec3 up;
        glm_vec3_cross(right, viewDirection, up);
        
        // update position
        // forwards
        if (glfwGetKey(window, GLFW_KEY_UP) || glfwGetKey(window, GLFW_KEY_W)) {
                glm_vec3_scale(viewDirection, deltaTime * speed, delta);
                glm_vec3_add(position, delta, position);
        }

        // backwards
        if (glfwGetKey(window, GLFW_KEY_DOWN) || glfwGetKey(window, GLFW_KEY_S)) {
                glm_vec3_scale(viewDirection, deltaTime * speed, delta);
                glm_vec3_sub(position, delta, position);
        }

        // move right
        if (glfwGetKey(window, GLFW_KEY_RIGHT) || glfwGetKey(window, GLFW_KEY_D)) {
                glm_vec3_scale(right, deltaTime * speed, delta);
                glm_vec3_add(position, delta, position);
        }

        // move left
        if (glfwGetKey(window, GLFW_KEY_LEFT) || glfwGetKey(window, GLFW_KEY_A)) {
                glm_vec3_scale(right, deltaTime * speed, delta);
                glm_vec3_sub(position, delta, position);
        }

        // move up using spacebar
        if (glfwGetKey(window, GLFW_KEY_SPACE)) {
                glm_vec3_scale(up, deltaTime * speed, delta);
                glm_vec3_add(position, delta, position);
        }

        // move down using shift
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT)) {
                glm_vec3_scale(up, deltaTime * speed, delta);
                glm_vec3_sub(position, delta, position);
        }

        // make viewDirection relative to position
        glm_vec3_add(position, viewDirection, viewDirection);

        // update matrices
        // update camera matrix
        glm_lookat(position, viewDirection, up, *(camera));

        // update projection matrix
        glm_perspective(FOV, (float)screenWidth / (float)screenHeight, 0.1f, 100.0f, *(projection));

        // update model matrix
        glm_mat4_identity(*(model));

}
