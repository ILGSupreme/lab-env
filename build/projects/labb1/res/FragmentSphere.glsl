#version 440 core
in vec2 outuv;
in vec3 Position_worldspace;
in vec3 Normal_cameraspace;
in vec3 EyeDirection_cameraspace;
in vec3 Lightdirection_cameraspace;
in vec3 Lightdirection_cameraspace2;

out vec4 color;

uniform sampler2D myTextureSampler;
uniform vec3 LightPosition_worldspace;
uniform vec3 ambient_light;
uniform vec3 diffuse_light;
uniform vec3 specular_light;
uniform vec3 target_color;

void main(void)
{
	vec3 colortest;
	vec3 LightColor = vec3(1,1,1);

	float LightPower = 1.0f;
	vec3 MaterialDiffuseColor = texture(myTextureSampler,outuv).rgb;
	vec3 MaterialAmbientColor = ambient_light * MaterialDiffuseColor;
	vec3 MaterialSpecularColor = specular_light;

	// Distance to the light
	float distance = length( LightPosition_worldspace - Position_worldspace );

	// Normal of the computed fragment, in camera space
	vec3 n = normalize( Normal_cameraspace );
	// Direction of the light (from the fragment to the light)
	vec3 l = normalize( Lightdirection_cameraspace );
	// Cosine of the angle between the normal and the light direction, 
	// clamped above 0
	//  - light is at the vertical of the triangle -> 1
	//  - light is perpendicular to the triangle -> 0
	//  - light is behind the triangle -> 0
	float cosTheta = clamp( dot( n,l ), 0,1 );
	
	// Eye vector (towards the camera)
	vec3 E = normalize(EyeDirection_cameraspace);
	// Direction in which the triangle reflects the light
	vec3 R = reflect(-l,n);
	// Cosine of the angle between the Eye vector and the Reflect vector,
	// clamped to 0
	//  - Looking into the reflection -> 1
	//  - Looking elsewhere -> < 1
	float cosAlpha = clamp( dot( E,R ), 0,1 );
	
	colortest = 
		// Ambient : simulates indirect lighting
		MaterialAmbientColor +
		// Diffuse : "color" of the object
		MaterialDiffuseColor * LightColor * LightPower * diffuse_light * cosTheta /1 +
		// Specular : reflective highlight, like a mirror
		MaterialSpecularColor * LightColor * LightPower * pow(cosAlpha,50) /1;
	
	if(target_color.x == 0)
	{
	  color = vec4(0.5,0.1,0.1,1);
	}
	else
	{
	  color = vec4(colortest,1);
	}
}