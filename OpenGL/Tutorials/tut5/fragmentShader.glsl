#version 330 core

// input data (comes from vertex shader)
in vec2 UV;

// output data
out vec3 colour;

// get texture sampler
uniform sampler2D textureSampler;

void main() {
        colour = texture(textureSampler, UV).rgb;
} 
