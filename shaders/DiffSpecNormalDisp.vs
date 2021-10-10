



void main(void){
	// Calculate normal in view-space
	// vs_out.N = mat3(mt_modelView) * inNormal;
	mat3 normalMatrix = mat3(transpose(inverse(mt_model)));
	vec3 normal 	= normalize(vec3( normalMatrix * inNormal		));
	vec3 tangent 	= normalize(vec3( normalMatrix * inTangent		));
	vec3 bitangent 	= normalize(vec3( normalMatrix * inBiTangent	));
	
	vs_out.normal 		= normal ;
	vs_out.tangent 		= tangent ;
	vs_out.bitangent 	= bitangent;
	
	mat3 local2WorldTranspose = (mat3(    tangent,	bitangent, normal));
	vec3 worldNormal = normalize(local2WorldTranspose*inNormal );
	vec3 viewNormal = normalize(mat3(mt_modelView)*worldNormal);
	
	mat3 normalMatrix2 = mat3(((mt_modelView)));
	vs_out.normalV = 	normalize(vec3( mat3(mt_modelView) * vec3(inNormal	)));
	vs_out.tangentV = 	normalize(vec3( normalMatrix2 * vec3(inTangent	)));
	vs_out.bitangentV = normalize(vec3( normalMatrix2 * vec3(inBiTangent)));
	
	vec4 P = mt_model * inPosition;
	
	vec3 T = normalize(mat3(mt_model) * tangent);
    vec3 B = normalize(mat3(mt_model) * bitangent);
    vec3 N = normalize(mat3(mt_model) * normal);
    mat3 TBN = transpose(mat3(T, B, N));
	
    // vs_out.TangentLightPos = TBN * lightPos;
    vs_out.TangentViewPos  = TBN * viewPos;
    vs_out.TangentFragPos  = TBN * P.xyz;
	
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
	
	// Calculate the clip-space position of each vertex
	gl_Position = mt_modelViewProjection * inPosition;
}
