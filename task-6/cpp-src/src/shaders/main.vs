#version 410 core

// in vec3 normal;
layout (location = 0) in vec3 vPosition;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 TexCoord;

uniform mat4 transform;

varying vec3 v_normal;

void main()
{
    vec4 position = transform * vec4(vPosition, 1.0);
    gl_Position = position;

    v_normal = normal;
    TexCoord = aTexCoord;
}