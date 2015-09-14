#version 440 core

uniform sampler2D myTextureSampler;

in GS_OUT
{
	vec4 color;
	vec2 UV;
}fs_in;
out vec4 color;
void main(void)
{
	color = texture(myTextureSampler,fs_in.UV);
}