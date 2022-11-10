
#version 330 core
out vec4 color;

in vec2 UV;
uniform sampler2D myTextureSampler;

void main()
{
    // TODO: pub with your code...
  color = vec4(texture(myTextureSampler, UV).rgb,1.0f);
}
