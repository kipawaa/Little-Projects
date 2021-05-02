#version 330 core

// input data
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexUV;

// output data (goes to fragment shader)
out vec2 UV;

// uniforms
uniform mat4 PVM;

void main() {
        gl_Position = PVM * vec4(vertexPosition, 1.0);
        UV = vertexUV;
}
