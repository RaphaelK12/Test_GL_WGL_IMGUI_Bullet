
out VS_OUT{
	vec4 position;
	vec4 position_M;
	vec4 position_V;
	vec4 position_P;
	vec4 position_MV;
	vec4 position_MVP;

	vec3 normal;	// normal
	vec3 tangent;	// tangent
	vec3 bitangent;	// bitangent
	
	vec3 normalV;	// normal
	vec3 tangentV;	// tangent
	vec3 bitangentV;	// bitangent

	vec3 TangentViewPos;	
	vec3 TangentFragPos;	

	vec3 lightDir;	// Light
	vec3 viewPos;	// Light
	vec2 uv1;		// first uv
	
	// rarely used, not necessary
	vec2 uv2;		// Second uv possible not used
	vec4 color1;		// vertex color 
	vec4 color2;	// vertex color 
} vs_out;


// Per-vertex inputs
layout (location = 0) in vec4 inPosition;
layout (location = 1) in vec3 inNormal;
layout (location = 2) in vec3 inTangent;
layout (location = 3) in vec3 inBiTangent;
layout (location = 4) in vec2 inUv1;
layout (location = 5) in vec4 inColor1;

layout (location = 6) in vec2 inUv2;
layout (location = 7) in vec2 inUv3;
layout (location = 8) in vec4 inColor2;
layout (location = 9) in vec4 inColor3;

// Matrices we'll need
uniform mat4 mt_model;
uniform mat4 mt_view;
uniform mat4 mt_projection;
uniform mat4 mt_modelView;
uniform mat4 mt_modelViewProjection;










