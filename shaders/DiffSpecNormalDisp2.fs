


// the signature
subroutine vec4 colorRedGreenBlue ();
subroutine vec4 colorSecondary ();
 
// a special uniform variable to control which option will be used
layout (location = 1) subroutine uniform colorRedGreenBlue PrimaryColor;
layout (location = 2) subroutine uniform colorSecondary SecondaryColor;

// location = 0
layout (index = 6) subroutine (colorRedGreenBlue ) vec4 ColorBlack(){	return vec4(0.0, 0.0, 0.0, 1.0);} 
layout (index = 7) subroutine (colorRedGreenBlue ) vec4 ColorWhite(){	return vec4(1.0, 1.0, 1.0, 1.0);} 
layout (index = 8) subroutine (colorRedGreenBlue ) vec4 ColorRed()	{	return vec4(1.0, 0.0, 0.0, 1.0);}  
layout (index = 9) subroutine (colorRedGreenBlue ) vec4 ColorGreen(){	return vec4(0.0, 1.0, 0.0, 1.0);}
layout (index = 10) subroutine (colorRedGreenBlue ) vec4 ColorBlue()	{	return vec4(0.0, 0.0, 1.0, 1.0);}
	
// location = 1	
layout (index = 11) subroutine (colorSecondary ) vec4 ColorBlak()	{	return vec4(0.0, 0.0, 0.0, 1.0);}
layout (index = 12) subroutine (colorSecondary ) vec4 ColorGray()	{	return vec4(0.5, 0.5, 0.5, 1.0);}
layout (index = 13) subroutine (colorSecondary ) vec4 ColorCyan()	{	return vec4(0.0, 1.0, 1.0, 1.0);}
layout (index = 14) subroutine (colorSecondary ) vec4 ColorYellow()	{	return vec4(1.0, 1.0, 0.0, 1.0);}  
layout (index = 15) subroutine (colorSecondary ) vec4 ColorMagenta()	{	return vec4(1.0, 0.0, 1.0, 1.0);}

void main(void) {
	vec2 dx = dFdx(fsin.uv1);
	vec2 dy = dFdy(fsin.uv1);
	vec2 uv = fsin.uv1;
	vec3 R ;
	light l;
	l.direction = fsin.lightDir;
	l.color = lightColor;
	l.power = lightPower;
	l.specPower = mt.shinines.rgb;
	// color = blinPhong_2(fsin.normal, fsin.lightDir, viewPos, 
	// specular_power, specular_albedo,	diffuse_albedo,	fsin.color1);
	
	vec3 viewDir = normalize(fsin.TangentViewPos - fsin.TangentFragPos);
		// vec3 viewDir = normalize( viewPos- fsin.position_M.xyz);

	vec2 offsetDir = -(viewDir.xy)*0.04/viewDir.z;
    vec2 texCoords= fsin.uv1;       
    // texCoords =  ParallaxMapping(fsin.uv1,  viewDir);       
    // texCoords =  cone_step(fsin.uv1,  viewDir, texture2);       
    // texCoords =  fsin.uv1 + offsetDir * relief(fsin.uv1,  offsetDir, texture2);       
    // if(texCoords.x > 1.0 || texCoords.y > 1.0 || texCoords.x < 0.0 || texCoords.y < 0.0)        discard;
		// texCoords+=rand(fsin.uv1)/500;
	vec3 N =  getNormalFromMap(fsin.normal, fsin.tangent, texture3, texCoords, fsin.position_M.xyz,dx,dy);
	shading s = blinPhong2(fsin.normal, fsin.viewPos, l, texCoords,dx,dy);
	vec3 I = normalize( viewPos-fsin.position_M.xyz );
    //  R = reflect(normalize(I), fsin.normal);
	// uv = SampleSphericalMap(R);
	// uv = sphereMap(fsin.normal, viewPos, fsin.position_M.xyz);
	// uv = reflect(normalize(I),fsin.normalV).xy*0.5+0.5;
	// uv.x = dot(fsin.tangent, fsin.normalV);
	// uv.x = dot(fsin.bitangent, fsin.normalV);
	// uv = uv*0.5+0.5;
	vec3 ref = texco_refl(fsin.normal, normalize( viewPos-fsin.position_M.xyz));
	uv = ref.xy/3+0.5;
	
	
	
	vec3 r = reflect(-normalize(viewPos -fsin.position_M.xyz), normalize(fsin.normal) )*0.5+0.5;
	vec4 cl = PrimaryColor ();
	vec4 ck = SecondaryColor ();
	// uv.y *= ref.z;
	// if (gl_FrontFacing) {
		color = 
		// cl+ck;
		// vec4 cc = 
		vec4(
					(
					// mt.ambient.rgb + mt.emission.rgb 
					// +
					// textureGrad(texture1, texCoords,dx,dy).rgb
					// *					
					// vec3(normalize(-fsin.normalV).xy*0.5+0.5,0)
					// textureGrad(texture4, uv,0).rgb
					// r
					// fsin.normal*0.5+0.5
					// *
					// textureGrad(texture2, texCoords,dx,dy).rrr
					// +
					s.specular * mt.specular.rgb
					*
					textures(texture2, texCoords,dx,dy).rrr
					+
					s.diffuse * mt.diffuse.rgb
					*
// texcubic textureGrad BicubicLagrangeTextureSample BicubicHermiteTextureSample 
// texture_bicubic SampleTextureCatmullRom
					textures(texture1, texCoords,dx,dy).rgb
					),
					mt.diffuse.a);
	// }	else {		color = vec4(1, 0, 1, 1);	}


}







