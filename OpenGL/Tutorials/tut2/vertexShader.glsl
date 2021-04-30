#version 330 core

// input data
layout (location = 0) in vec3 vertexPosition;

// output data (goes to fragment shader)
out vec3 position;

void main() {
        gl_Position = vec4(vertexPosition.x, vertexPosition.y, vertexPosition.z, 1.0);
        position = vertexPosition;
}
