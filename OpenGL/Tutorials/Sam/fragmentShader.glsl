#version 330 core

// input data (comes from vertex shader)
in vec3 position;

// output data
out vec3 colour;

void main() {
        colour = abs(vec3(position.x , position.y , position.z ));
} 
