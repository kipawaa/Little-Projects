#include<math.h>

#include<GL/glew.h>
#include<GLFW/glfw3.h>

#include<cglm/cglm.h>
#include<cglm/vec3.h>
#include<cglm/mat4.h>

void updateMatricesFromControls(GLFWwindow* window, mat4* projection, mat4* camera, mat4* model, float deltaTime);
