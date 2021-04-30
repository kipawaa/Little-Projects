#version 330 core

// input data (comes from vertex shader)
in vec3 position;

// output data
out vec4 FragColor;

void main() {
        FragColor = vec4(position.x, position.y, position.z, 1.0f);
} 
