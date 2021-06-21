

void main(void){
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
	shading s = blinPhong1(fsin.normal, viewPos, l, uv,dx,dy);
	color = vec4(
					fsin.color1
					// (mt.ambient.rgb + mt.emission.rgb +
					// s.diffuse * mt.diffuse.rgb +
					// s.specular * mt.specular.rgb) 
					// * 
					// texture(texture1, fsin.uv1).rgb + vec3(0.1)
					// ,
	// mt.diffuse.a
	);
		
		
		
		
		


}
