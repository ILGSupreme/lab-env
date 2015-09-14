#version 440 core	
in vec4 position;
in vec2 UV;
out VS_OUT
{
	vec4 color;
	vec2 _UV;
}vs_out;
       
void main(void)	
{
	vs_out.color = position+vec4(0.25,0,3,1);			
	vs_out._UV = UV;                    
	gl_Position = position;
}