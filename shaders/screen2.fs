

uniform vec4 values = vec4(1);

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
	float sz = 0.00113;
	// color = blinPhong_2(fsin.normal, fsin.lightDir, viewPos, 
	// specular_power, specular_albedo,	diffuse_albedo,	fsin.color1);
	// shading s = blinPhong1(fsin.normal, viewPos, l);
	uv.y = 1-uv.y;
	// vec3 col = vec3(1-length(uv*vec2(1,0.6)-vec2(0.5, 0.25))*5);
	// col = smoothstep(0, 1, smoothstep(0, 1, smoothstep(0, 1, col)));
	// vec3 col = vec3(rand(uv))-0.5;
	vec3 col = (gold_noise((uv)+1.5,(time.xyz))); //random rgb value
	// vec3 col = vec3(rand2(uv*1+0.5,1+time.w*10).x); //random rgb value
	// vec2 p1 = (10,10);
	// vec2 p2 = (90,80);
		color = vec4(
					// (mt.ambient.rgb + mt.emission.rgb +
					// s.diffuse * mt.diffuse.rgb +
					// s.specular * mt.specular.rgb)
					// *
					// vec3(angle_to_point(vec2(sin(time.w/1), cos(time.w/1))*0.25+0.5, uv)*F_1_2PI+0.5)
					// vec3(cos(pDistance(vec2(sin(time.w/1), cos(time.w/1))*50+50, vec2(50), uv*100)*2)*0.5+0.5)
					// vec3(gl_FragCoord.xy/696,0) //
					// vec3(uv,0)
					// vec3(closestToLine(vec2( sin(time.w/1), cos(time.w/1) ), vec2(1), uv),0)
					col // add random value to hide branding on lower variance colors
					// /226
					// +
					// pow(texture(texture1, uv).rgb,1/1.2)
					
					// vec3(cos(distance(uv, vec2(0.5))*32*(sintime.w+2)))
					
					// vec3(smoothstep(values.x, values.y, distance(uv, vec2(0.5))*8))
					
					// vec3(smoothstep( vec2(0),vec2(1), fract(uv*32)),0)
					
					// vec3(dy, 0)
					
					// vec3(
					// texture(texture1, fsin.uv1+vec2(-sz,-sz)).rgb+
					// texture(texture1, fsin.uv1+vec2(-sz,0  )).rgb+
					// texture(texture1, fsin.uv1+vec2(-sz,sz )).rgb+
					
					// texture(texture1, fsin.uv1+vec2(sz,-sz)).rgb+
					// texture(texture1, fsin.uv1+vec2(sz,0  )).rgb+
					// texture(texture1, fsin.uv1+vec2(sz,sz )).rgb+
					
					// texture(texture1, fsin.uv1+vec2(0,-sz)).rgb+
					// texture(texture1, fsin.uv1+vec2(0,0  )).rgb+
					// texture(texture1, fsin.uv1+vec2(0,sz )).rgb)/vec3(9)
					
		,
		1);


}
