

// vec3 getSky(vec2 uv){
    // float atmosphere = sqrt(1.0-uv.y);
    // vec3 skyColor = vec3(0.2,0.4,0.8);
    
    // float scatter = pow(iMouse.y / iResolution.y,1.0 / 15.0);
    // scatter = 1.0 - clamp(scatter,0.8,1.0);
    
    // vec3 scatterColor = mix(vec3(1.0),vec3(1.0,0.3,0.0) * 1.5,scatter);
    // return mix(skyColor,vec3(scatterColor),atmosphere / 1.3);
    
// }

// vec3 getSun(vec2 uv){
	// float sun = 1.0 - distance(uv,iMouse.xy / iResolution.y);
    // sun = clamp(sun,0.0,1.0);
    
    // float glow = sun;
    // glow = clamp(glow,0.0,1.0);
    
    // sun = pow(sun,100.0);
    // sun *= 100.0;
    // sun = clamp(sun,0.0,1.0);
    
    // glow = pow(glow,6.0) * 1.0;
    // glow = pow(glow,(uv.y));
    // glow = clamp(glow,0.0,1.0);
    
    // sun *= pow(dot(uv.y, uv.y), 1.0 / 1.65);
    
    // glow *= pow(dot(uv.y, uv.y), 1.0 / 2.0);
    
    // sun += glow;
    
    // vec3 sunColor = vec3(1.0,0.6,0.05) * sun;
    
    // return vec3(sunColor);
// }

// void mainImage( out vec4 fragColor, in vec2 fragCoord ){
	// vec2 uv = fragCoord.xy / iResolution.y;
    
    // vec3 sky = getSky(uv);
    // vec3 sun = getSun(uv);
    
	// fragColor = vec4(sky + sun,1.0);
// }

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
	shading s = blinPhong2(fsin.normal, fsin.viewPos, l, uv,dx,dy );
	float t = time.w/2;
	uv = SampleSphericalMap(normalize (fsin.position.xyz));
	vec3 sun = max(pow(dot(normalize(vec3(0.0,sin(t),cos(t))), normalize(fsin.position.xyz))*10-9,vec3(300,400,600)),0);
	vec3 cl = vec3(0.1,0.1,0.6);
	cl += dot(normalize(vec3(0.0,sin(t),cos(t))), normalize(fsin.position.xyz))*0.4+0.6;
	cl = pow(vec3(pow(cl,2)*0.75+0.1),vec3(1,0.7,0.4))*vec3(0.7,0.8,1);
	cl *= pow(dot(vec3(0.0,0,-1), normalize(fsin.position.xyz))*0.4+0.7, vec3(0.7,0.55,0.5));
	cl += sun;
	// uv = sphereMap(normalize(fsin.position.xyz), vec3(0), fsin.position.xyz);
	// uv = texco_refl(fsin.normal, vec3(0)).xy;
	// if (gl_FrontFacing) {
		color = vec4(
					(
					cl.rgb
					// mt.ambient.rgb + mt.emission.rgb 
					// +
					// BicubicHermiteTextureSample(texture1, fsin.uv1,dx,dy).rgb
					// *
					// s.specular * mt.specular.rgb
					// *
					// texture(texture2, fsin.uv1).rgb
					// +
					// s.diffuse * mt.diffuse.rgb
					// *
					// textureGrad(texture1, uv,ddx,ddy).rgb
					),
					mt.diffuse.a);
	// }
	// else {
		// color = vec4(1, 0, 1, 1);
	// }


}







