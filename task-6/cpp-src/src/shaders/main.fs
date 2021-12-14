#version 410 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

varying vec3 v_normal;

vec3 lightDirection = vec3(0, 0.5, -1);
float intensity = 1.;
vec3 color = vec3(1.0, 0.4, 0.3);

void main()
{
   vec3 normal = normalize(v_normal);
   float light = dot(normal, -lightDirection) / 2.0 + 0.5 + 0.1;

   FragColor = texture(ourTexture, TexCoord);
   FragColor *= light * intensity;

   // gl_FragColor = vec4(color, 1.0);
}