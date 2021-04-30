#version 330 core

// input data (comes from vertex shader)
in vec3 position;

// output data
out vec4 fragColor;

void main() {
        fragColor = vec4(position.x + position.y, position.y + position.z, position.z + position.x, 1.0f);
} 
