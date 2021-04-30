#version 330 core

// input data (comes from vertex shader)
in vec3 fragColour;

// output data
out vec3 colour;

void main() {
        colour = fragColour;
} 
