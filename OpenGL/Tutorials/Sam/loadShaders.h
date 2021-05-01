#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>

/*
   loads the first vertex shader named <vertexShaderFileName> and fragment shader named
   <fragmentShaderFileName> in the current directory and returns the program ID
*/
GLuint loadShaders(char* vertexShaderFileName, char* fragmentShaderFileName);
