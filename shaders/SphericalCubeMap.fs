

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
	shading s = blinPhong2(fsin.normal, fsin.viewPos, l,uv,dx,dy);
	uv = SampleSphericalMap(normalize (fsin.position.xyz));
	// uv = sphereMap(normalize(fsin.position.xyz), vec3(0), fsin.position.xyz);
	// uv = texco_refl(fsin.normal, vec3(0)).xy;
	// if (gl_FrontFacing) {
		color = vec4(
					(
					// mt.ambient.rgb + mt.emission.rgb 
					// +
					// BicubicHermiteTextureSample(texture1, fsin.uv1,dx,dy).rgb
					// *
					// s.specular * mt.specular.rgb
					// *
					// BicubicHermiteTextureSample(texture2, fsin.uv1,dx,dy).rgb
					// +
					// s.diffuse * mt.diffuse.rgb
					// *
//	BicubicHermiteTextureSample
//	BicubicLagrangeTextureSample
//	texture_bicubic
//	textureGrad
//	texcubic
//	SampleTextureCatmullRom

					textures(texture1, uv,dx/4,dy/4).rgb
					),
					mt.diffuse.a);
	// }
	// else {
		// color = vec4(1, 0, 1, 1);
	// }


}







