#version 330 core
out vec4 FragColor;

in vec3 fragPosition;

void main()
{
    FragColor = vec4((sin(fragPosition.x * 15.0) / 2.0) + 0.5, 0.55, 0.5, 1.0);
};