#version 440 core	
in vec3 position;
in vec2 UV;
in vec3 normal;

uniform mat4 MVP;
uniform mat4 v;
uniform mat4 m;
uniform vec3 LightPosition_worldspace;

out vec2 outuv;
out vec3 Position_worldspace;
out vec3 Normal_cameraspace;
out vec3 EyeDirection_cameraspace;
out vec3 Lightdirection_cameraspace;
out vec3 Lightdirection_cameraspace2;

           
void main(void)
{
	outuv = UV;        
	gl_Position = MVP * vec4(position,1);

	Position_worldspace = (m * vec4(position,1)).xyz;

	vec3 vertexPosition_cameraspace = (v * m * vec4(position,1)).xyz;

	EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;

	vec3 LightPosition_cameraspace = (v * vec4(LightPosition_worldspace,1)).xyz;

	Lightdirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;

	///LIGHT 2

	vec3 LightPosition_cameraspace2 = (v * vec4(0,0,-100,1)).xyz;

	Lightdirection_cameraspace2 = Lightdirection_cameraspace2 + EyeDirection_cameraspace;

	///LIGHT 2

	mat4 normal_transposed = transpose(inverse(m));

	Normal_cameraspace =( v * m * vec4(normal,0)).xyz;
}