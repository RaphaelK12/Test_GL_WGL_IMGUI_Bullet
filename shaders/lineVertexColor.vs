


vec3 light_pos = vec3(5, 0, 0);

void main(void){
	// Calculate view-space coordinate
	vec4 P = mt_model * inPosition;

	// Calculate normal in view-space
	// vs_out.N = mat3(mt_modelView) * inNormal;
	mat3 normalMatrix = mat3(transpose(inverse(mt_model)));
	vs_out.normal = normalize(vec3( normalMatrix * inNormal));

	// Calculate light vector
	vs_out.lightDir = light_pos - P.xyz;

	vs_out.position		= inPosition; // local
	vs_out.position_M	= mt_model * inPosition; // global
	vs_out.position_V	= mt_view * inPosition; // global
	vs_out.position_P	= mt_projection * inPosition;
	vs_out.position_MV	= mt_modelView * inPosition;  // global view
	vs_out.position_MVP = mt_modelViewProjection * inPosition; // global projection
	vs_out.uv1=inUv1;
	vs_out.color1=inColor1;

	// Calculate the clip-space position of each vertex
	gl_Position = mt_modelViewProjection * inPosition;
}
