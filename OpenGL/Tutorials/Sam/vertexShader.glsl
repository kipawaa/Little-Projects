#version 330 core

// input data
layout(location = 0) in vec3 vertexPosition;

uniform mat4 PVM; // get our matrix

// output data (goes to fragment shader)
out vec3 position;

void main() {
        gl_Position = PVM * vec4(vertexPosition, 1.0);
        position = vertexPosition;
}
