
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // TODO: Your code here
    // Remember to set gl_Position (correctly) or you will get a black screen...
    FragPos = vec3(model * vec4(position, 1.0));
    Normal = inverse(transpose(mat3(model)))*normal;
    gl_Position = projection * view  * vec4(FragPos, 1.0);
} 
