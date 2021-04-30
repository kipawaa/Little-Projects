#version 330 core

// input data
layout(location = 0) in vec3 vertexPosition;

layout(location = 1) in vec3 colour;

uniform mat4 PVM; // get our matrix

// output data (goes to fragment shader)
out vec3 fragColour;

void main() {
        gl_Position = PVM * vec4(vertexPosition, 1.0);
        fragColour = colour;
}
