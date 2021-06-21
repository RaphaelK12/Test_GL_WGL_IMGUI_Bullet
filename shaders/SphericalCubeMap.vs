

vec3 light_pos = vec3(0, 0, 2);

void main(void){
	// Calculate view-space coordinate
	vec4 P = mt_model * inPosition;

	// Calculate normal in view-space
	// vs_out.N = mat3(mt_modelView) * inNormal;
	mat3 normalMatrix = mat3(transpose(inverse(mt_model)));
	vs_out.normal = normalize(vec3( normalMatrix * inNormal));
	vs_out.tangent = normalize(vec3( normalMatrix * inTangent));
	vs_out.bitangent = normalize(vec3( normalMatrix * inBiTangent));


	vs_out.position		= inPosition; // local
	vs_out.position_M	= mt_model * inPosition; // global
	vs_out.position_V	= mt_view * inPosition; // global
	vs_out.position_P	= mt_projection * inPosition;
	vs_out.position_MV	= mt_modelView * inPosition;  // global view
	vs_out.position_MVP = mt_modelViewProjection * inPosition; // global projection
	vs_out.uv1=inUv1;
	vs_out.color1=inColor1;
	// Calculate light vector
	vs_out.lightDir = light_pos - P.xyz;
	vs_out.viewPos = viewPos - P.xyz;
	
	mat4 view = mat4(mat3(mt_view));
	// view[3].x = 0;
	// view[3].y = 0;
	// view[3].z = 0;
	// view[3].w = 1;
	// Calculate the clip-space position of each vertex
	gl_Position = (mt_projection * view * vec4(inPosition.xyz,1.0)).xyww;
}
