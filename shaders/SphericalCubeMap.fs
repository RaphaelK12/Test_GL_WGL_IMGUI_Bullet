#version 410 core
// Input Built-in Variables
// in vec4 gl_FragCoord;
// in bool gl_FrontFacing;
// in vec2 gl_PointCoord;
struct material {
	vec4 diffuse;		
	vec4 color1;		
	vec4 color2;		
	vec4 color3;		

	vec4 ambient;		
	vec4 emission;		
	vec4 translucenci;	
	vec4 sadowsColor;	

	vec4 specular;		
	vec4 reflex;		
	vec4 shinines;		
};
struct light {
	vec3 direction;
	vec3 color;
	float power;
	vec3 specPower;
};
struct shading {
	vec3 diffuse;
	vec3 specular;
	float rim;
	float distance;
};
in VS_OUT{
	// Vertex positions
	vec4 position;		// position in local space
	vec4 position_M;	// position in global space
	vec4 position_V;	// position in view space
	vec4 position_P;	// position in projection space
	vec4 position_MV;	// position in model view space
	vec4 position_MVP;	// position in model view projection space
	
	vec3 normal;	// normal
	vec3 tangent;	// tangent
	vec3 bitangent;	// bitangent
	
	vec3 lightDir;	// Light
	vec3 viewPos;	// Light
	vec2 uv1;		// first uv
	vec2 uv2;		// Second uv possible not used
	vec4 color1;		// vertex color 
	vec4 color2;	// vertex color 
} fs_in;
uniform material mt;

#define c_onePixel  (1.0 / c_textureSize)
#define c_twoPixels  (2.0 / c_textureSize)

float c_x0 = -1.0;
float c_x1 =  0.0;
float c_x2 =  1.0;
float c_x3 =  2.0;


// w0, w1, w2, and w3 are the four cubic B-spline basis functions
float w0(float a){
    return (1.0/6.0)*(a*(a*(-a + 3.0) - 3.0) + 1.0);
}

float w1(float a){
    return (1.0/6.0)*(a*a*(3.0*a - 6.0) + 4.0);
}

float w2(float a){
    return (1.0/6.0)*(a*(a*(-3.0*a + 3.0) + 3.0) + 1.0);
}

float w3(float a){
    return (1.0/6.0)*(a*a*a);
}

// g0 and g1 are the two amplitude functions
float g0(float a){
    return w0(a) + w1(a);
}

float g1(float a){
    return w2(a) + w3(a);
}

// h0 and h1 are the two offset functions
float h0(float a){
    return -1.0 + w1(a) / (w0(a) + w1(a));
}

float h1(float a){
    return 1.0 + w3(a) / (w2(a) + w3(a));
}

vec4 texture_bicubic(sampler2D tex, vec2 uv,vec2 dx,vec2 dy){
	vec4 texelSize = vec4(1/vec2(textureSize(tex,0)),vec2(textureSize(tex,0)));
	uv = uv*texelSize.zw + 0.5;
	vec2 iuv = floor( uv );
	vec2 fuv = fract( uv );

    float g0x = g0(fuv.x);
    float g1x = g1(fuv.x);
    float h0x = h0(fuv.x);
    float h1x = h1(fuv.x);
    float h0y = h0(fuv.y);
    float h1y = h1(fuv.y);

	vec2 p0 = (vec2(iuv.x + h0x, iuv.y + h0y) - 0.5) * texelSize.xy;
	vec2 p1 = (vec2(iuv.x + h1x, iuv.y + h0y) - 0.5) * texelSize.xy;
	vec2 p2 = (vec2(iuv.x + h0x, iuv.y + h1y) - 0.5) * texelSize.xy;
	vec2 p3 = (vec2(iuv.x + h1x, iuv.y + h1y) - 0.5) * texelSize.xy;
	
    return g0(fuv.y) * (g0x * textureGrad(tex, p0,dx,dy)  +
                        g1x * textureGrad(tex, p1,dx,dy)) +
           g1(fuv.y) * (g0x * textureGrad(tex, p2,dx,dy)  +
                        g1x * textureGrad(tex, p3,dx,dy));
}

vec3 CubicLagrange (vec3 A, vec3 B, vec3 C, vec3 D, float t){
    return
        A * 
        (
            (t - c_x1) / (c_x0 - c_x1) * 
            (t - c_x2) / (c_x0 - c_x2) *
            (t - c_x3) / (c_x0 - c_x3)
        ) +
        B * 
        (
            (t - c_x0) / (c_x1 - c_x0) * 
            (t - c_x2) / (c_x1 - c_x2) *
            (t - c_x3) / (c_x1 - c_x3)
        ) +
        C * 
        (
            (t - c_x0) / (c_x2 - c_x0) * 
            (t - c_x1) / (c_x2 - c_x1) *
            (t - c_x3) / (c_x2 - c_x3)
        ) +       
        D * 
        (
            (t - c_x0) / (c_x3 - c_x0) * 
            (t - c_x1) / (c_x3 - c_x1) *
            (t - c_x2) / (c_x3 - c_x2)
        );
}

vec3 BicubicLagrangeTextureSample (sampler2D tex, vec2 uv, vec2 dx,vec2 dy){
	vec2 c_textureSize = vec2(textureSize(tex,0));
    vec2 pixel = uv * c_textureSize + 0.5;
    
    vec2 frac = fract(pixel);
    pixel = floor(pixel) / c_textureSize - vec2(c_onePixel/2.0);
    
    vec3 C00 = textureGrad(tex, pixel + vec2(-c_onePixel.x ,-c_onePixel.y),dx,dy).rgb;
    vec3 C10 = textureGrad(tex, pixel + vec2( 0.0        ,-c_onePixel.y),dx,dy).rgb;
    vec3 C20 = textureGrad(tex, pixel + vec2( c_onePixel.x ,-c_onePixel.y),dx,dy).rgb;
    vec3 C30 = textureGrad(tex, pixel + vec2( c_twoPixels.x,-c_onePixel.y),dx,dy).rgb;

    vec3 C01 = textureGrad(tex, pixel + vec2(-c_onePixel.x , 0.0),dx,dy).rgb;
    vec3 C11 = textureGrad(tex, pixel + vec2( 0.0        , 0.0),dx,dy).rgb;
    vec3 C21 = textureGrad(tex, pixel + vec2( c_onePixel.x , 0.0),dx,dy).rgb;
    vec3 C31 = textureGrad(tex, pixel + vec2( c_twoPixels.x, 0.0),dx,dy).rgb;    

    vec3 C02 = textureGrad(tex, pixel + vec2(-c_onePixel.x , c_onePixel.y),dx,dy).rgb;
    vec3 C12 = textureGrad(tex, pixel + vec2( 0.0        , c_onePixel.y),dx,dy).rgb;
    vec3 C22 = textureGrad(tex, pixel + vec2( c_onePixel.x , c_onePixel.y),dx,dy).rgb;
    vec3 C32 = textureGrad(tex, pixel + vec2( c_twoPixels.x, c_onePixel.y),dx,dy).rgb;    

    vec3 C03 = textureGrad(tex, pixel + vec2(-c_onePixel.x , c_twoPixels.y),dx,dy).rgb;
    vec3 C13 = textureGrad(tex, pixel + vec2( 0.0        , c_twoPixels.y),dx,dy).rgb;
    vec3 C23 = textureGrad(tex, pixel + vec2( c_onePixel.x , c_twoPixels.y),dx,dy).rgb;
    vec3 C33 = textureGrad(tex, pixel + vec2( c_twoPixels.x, c_twoPixels.y),dx,dy).rgb;    
    
    vec3 CP0X = CubicLagrange(C00, C10, C20, C30, frac.x);
    vec3 CP1X = CubicLagrange(C01, C11, C21, C31, frac.x);
    vec3 CP2X = CubicLagrange(C02, C12, C22, C32, frac.x);
    vec3 CP3X = CubicLagrange(C03, C13, C23, C33, frac.x);
    
    return CubicLagrange(CP0X, CP1X, CP2X, CP3X, frac.y);
}

vec3 CubicHermite (vec3 A, vec3 B, vec3 C, vec3 D, float t){
	float t2 = t*t;
    float t3 = t*t*t;
    vec3 a = -A/2.0 + (3.0*B)/2.0 - (3.0*C)/2.0 + D/2.0;
    vec3 b = A - (5.0*B)/2.0 + 2.0*C - D / 2.0;
    vec3 c = -A/2.0 + C/2.0;
   	vec3 d = B;
    
    return a*t3 + b*t2 + c*t + d;
}

vec3 BicubicHermiteTextureSample (sampler2D tex, vec2 uv, vec2 dx,vec2 dy){
	vec2 c_textureSize = vec2(textureSize(tex,0));
	
    vec2 pixel = uv * c_textureSize + 0.5;
    
    vec2 frac = fract(pixel);
    pixel = floor(pixel) / c_textureSize - vec2(c_onePixel/2.0);
    
    vec3 C00 = textureGrad(tex, pixel + vec2(-c_onePixel.x ,-c_onePixel.y),dx,dy).rgb;
    vec3 C10 = textureGrad(tex, pixel + vec2( 0.0        ,-c_onePixel.y),dx,dy).rgb;
    vec3 C20 = textureGrad(tex, pixel + vec2( c_onePixel.x ,-c_onePixel.y),dx,dy).rgb;
    vec3 C30 = textureGrad(tex, pixel + vec2( c_twoPixels.x,-c_onePixel.y),dx,dy).rgb;
    
    vec3 C01 = textureGrad(tex, pixel + vec2(-c_onePixel.x , 0.0),dx,dy).rgb;
    vec3 C11 = textureGrad(tex, pixel + vec2( 0.0        , 0.0),dx,dy).rgb;
    vec3 C21 = textureGrad(tex, pixel + vec2( c_onePixel.x , 0.0),dx,dy).rgb;
    vec3 C31 = textureGrad(tex, pixel + vec2( c_twoPixels.x, 0.0),dx,dy).rgb;    
    
    vec3 C02 = textureGrad(tex, pixel + vec2(-c_onePixel.x , c_onePixel.y),dx,dy).rgb;
    vec3 C12 = textureGrad(tex, pixel + vec2( 0.0        , c_onePixel.y),dx,dy).rgb;
    vec3 C22 = textureGrad(tex, pixel + vec2( c_onePixel.x , c_onePixel.y),dx,dy).rgb;
    vec3 C32 = textureGrad(tex, pixel + vec2( c_twoPixels.x, c_onePixel.y),dx,dy).rgb;    
    
    vec3 C03 = textureGrad(tex, pixel + vec2(-c_onePixel.x , c_twoPixels.y),dx,dy).rgb;
    vec3 C13 = textureGrad(tex, pixel + vec2( 0.0        , c_twoPixels.y),dx,dy).rgb;
    vec3 C23 = textureGrad(tex, pixel + vec2( c_onePixel.x , c_twoPixels.y),dx,dy).rgb;
    vec3 C33 = textureGrad(tex, pixel + vec2( c_twoPixels.x, c_twoPixels.y),dx,dy).rgb;    
    
    vec3 CP0X = CubicHermite(C00, C10, C20, C30, frac.x);
    vec3 CP1X = CubicHermite(C01, C11, C21, C31, frac.x);
    vec3 CP2X = CubicHermite(C02, C12, C22, C32, frac.x);
    vec3 CP3X = CubicHermite(C03, C13, C23, C33, frac.x);
    
    return CubicHermite(CP0X, CP1X, CP2X, CP3X, frac.y);
}

vec4 texcubic(sampler2D tex, vec2 uv, vec2 dx, vec2 dy){
    vec2 textureResolution = vec2(textureSize(tex,0));	
	uv = uv*textureResolution + 0.5;
	vec2 iuv = floor( uv );
	vec2 fuv = fract( uv );
	uv = iuv + smoothstep( 0.0, 1.0,fuv); // fuv*fuv*fuv*(fuv*(fuv*6.0-15.0)+10.0);;
	uv = (uv - 0.5)/textureResolution;
	return textureGrad( tex, uv ,dx,dy);
}

vec4 sampleLevel0( sampler2D tex, vec2 uv, vec2 dx, vec2 dy){
    return textureGrad( tex, uv ,dx,dy);
}

// note: entirely stolen from https://gist.github.com/TheRealMJP/c83b8c0f46b63f3a88a5986f4fa982b1
//
// Samples a texture with Catmull-Rom filtering, using 9 texture fetches instead of 16.
// See http://vec3.ca/bicubic-filtering-in-fewer-taps/ for more details
vec4 SampleTextureCatmullRom( sampler2D tex, vec2 uv, vec2 dx, vec2 dy ){
	vec2 textureResolution = vec2(textureSize(tex,0));	

    // We're going to sample a a 4x4 grid of texels surrounding the target UV coordinate. We'll do this by rounding
    // down the sample location to get the exact center of our "starting" texel. The starting texel will be at
    // location [1, 1] in the grid, where [0, 0] is the top left corner.
    vec2 samplePos = uv * textureResolution;
    vec2 texPos1 = floor(samplePos - 0.5) + 0.5;

    // Compute the fractional offset from our starting texel to our original sample location, which we'll
    // feed into the Catmull-Rom spline function to get our filter weights.
    vec2 f = samplePos - texPos1;

    // Compute the Catmull-Rom weights using the fractional offset that we calculated earlier.
    // These equations are pre-expanded based on our knowledge of where the texels will be located,
    // which lets us avoid having to evaluate a piece-wise function.
    vec2 w0 = f * ( -0.5 + f * (1.0 - 0.5*f));
    vec2 w1 = 1.0 + f * f * (-2.5 + 1.5*f);
    vec2 w2 = f * ( 0.5 + f * (2.0 - 1.5*f) );
    vec2 w3 = f * f * (-0.5 + 0.5 * f);
    
    // Work out weighting factors and sampling offsets that will let us use bilinear filtering to
    // simultaneously evaluate the middle 2 samples from the 4x4 grid.
    vec2 w12 = w1 + w2;
    vec2 offset12 = w2 / w12;

    // Compute the final UV coordinates we'll use for sampling the texture
    vec2 texPos0 = texPos1 - vec2(1.0);
    vec2 texPos3 = texPos1 + vec2(2.0);
    vec2 texPos12 = texPos1 + offset12;

    texPos0 /= textureResolution;
    texPos3 /= textureResolution;
    texPos12 /= textureResolution;

    vec4 result = vec4(0.0);
    result += sampleLevel0(tex, vec2(texPos0.x,  texPos0.y),  dx,  dy) * w0.x * w0.y;
    result += sampleLevel0(tex, vec2(texPos12.x, texPos0.y),  dx,  dy) * w12.x * w0.y;
    result += sampleLevel0(tex, vec2(texPos3.x,  texPos0.y),  dx,  dy) * w3.x * w0.y;

    result += sampleLevel0(tex, vec2(texPos0.x,  texPos12.y),  dx,  dy) * w0.x * w12.y;
    result += sampleLevel0(tex, vec2(texPos12.x, texPos12.y),  dx,  dy) * w12.x * w12.y;
    result += sampleLevel0(tex, vec2(texPos3.x,  texPos12.y),  dx,  dy) * w3.x * w12.y;

    result += sampleLevel0(tex, vec2(texPos0.x,  texPos3.y),  dx,  dy) * w0.x * w3.y;
    result += sampleLevel0(tex, vec2(texPos12.x, texPos3.y),  dx,  dy) * w12.x * w3.y;
    result += sampleLevel0(tex, vec2(texPos3.x,  texPos3.y),  dx,  dy) * w3.x * w3.y;

    return result;
}


float saturate(float value) {
	return clamp(value, 0.0, 1.0);
}
vec2 saturate(vec2 value) {
	return clamp(value, 0.0, 1.0);
}
vec3 saturate(vec3 value) {
	return clamp(value, 0.0, 1.0);
}
vec4 saturate(vec4 value) {
	return clamp(value, 0.0, 1.0);
}
vec3 pow(in float p, in vec3 v) {
	return pow(vec3(p), v);
}
vec3 pow(in vec3 p, in float v) {
	return pow(p, vec3(v));
}
vec3 unpackNormal(vec3 n, float scale){
	vec3 r=n*2-1;
	return normalize(r*vec3(scale,scale,1));
}
vec3 getNormalFromMap(vec3 n, sampler2D tex, vec2 coord, vec3 WorldPos, vec2 dx,vec2 dy){
    vec3 tangentNormal = unpackNormal(BicubicHermiteTextureSample(tex, coord,dx,dy).xyz, 0.5) ;
    vec3 N   = normalize(n);
    vec3 T  = normalize(fs_in.tangent);
    vec3 B  = -normalize(cross(N, T));
    mat3 TBN = mat3(T, B, N);
    return normalize(TBN * tangentNormal);
}
vec2 SampleSphericalMap(vec3 v){
	const vec2 invAtan = vec2(0.15915494309189533, 0.31830988618); // vec2 invAtan vec2(1/(2*PI),1/PI);
	// const vec2 invAtan = vec2(0.159155, 0.3183);
	vec2 uv = vec2(atan(v.x, v.y), asin(-v.z));
	uv *= invAtan;
	uv += 0.5;
	return uv;
}
vec2 sphereMap(vec3 n, vec3 v, vec3 pos ){	
	vec3 I = normalize( v-pos );
	vec3 R = reflect( I, normalize(n));
	float M = 2. * sqrt( pow( R.x, 2. ) + pow( R.y, 2. ) + pow( R.z + 1., 2. ) );
	vec2 uv = R.xy / M + .5;
	return uv;
}
vec3 texco_refl(vec3 vn, vec3 view){
 	return view - 2.0 * dot(vn, view) * vn;
}

// Output
layout(location = 0) out vec4 color;
layout(location = 1) out vec4 nr;
// Input from vertex shader

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;
// Material properties
uniform vec4 diffuse_albedo = vec4(0.5, 0.2, 0.7, 1);
uniform vec3 specular_albedo = vec3(0.7);
uniform float specular_power = 128.0; // 200

vec3 lightColor = vec3(1.0, 1.0, 1.0);
float lightPower = 18.0; // 40
vec3 light_pos = vec3(5, 0, 0);

// Ray intersect depth map using relaxed cone stepping.    
// Depth value stored in alpha channel (black at object surface)    
// and relaxed cone ratio stored in blue channel.    
void ray_intersect_relaxedcone(sampler2D relief_map, inout vec3 ray_pos, inout vec3 ray_dir){
	const int cone_steps = 15;
	const int binary_steps = 6;
	ray_dir /= ray_dir.z;  // Scale ray_dir    
	float ray_ratio = length(ray_dir.xy);
	vec3 pos = ray_pos;
	for (int i = 0; i < cone_steps; i++) {
		vec4 tex = texture(relief_map, pos.xy);
		float cone_ratio = tex.z;
		float height = saturate(tex.w - pos.z);
		float d = cone_ratio * height / (ray_ratio + cone_ratio);
		pos += ray_dir * d;
	}
	// Binary search initial range and initial position       
	vec3     bs_range = 0.5 * ray_dir * pos.z;
	vec3 bs_position = ray_pos + bs_range;
	for (int i = 0; i < binary_steps; i++) {
		vec4 tex = texture(relief_map, bs_position.xy);
		bs_range *= 0.5;
		if (bs_position.z < tex.w)
			// If outside       
			bs_position += bs_range;
		// Move forward    
		else
			bs_position -= bs_range;
		// Move backward   
	}
}
vec4 depth2relaxedcone(vec2 TexCoord, sampler2D ReliefSampler, vec3 Offset) {
	const int search_steps = 128;
	vec3 src = vec3(TexCoord, 0);
	// Source texel   
	vec3 dst = src + Offset;
	// Destination texel   
	dst.z = texture(ReliefSampler, dst.xy).w;
	// Set dest. depth    
	vec3 vec = dst - src;
	// Ray direction   
	vec /= vec.z;
	// Scale ray direction so that vec.z = 1.0   
	vec *= 1.0 - dst.z;
	// Scale again    
	vec3 step_fwd = vec / search_steps;
	// Length of a forward step    
	// Search until a new point outside the surface    
	vec3 ray_pos = dst + step_fwd;
	for (int i = 1; i < search_steps; i++) {
		float current_depth = texture(ReliefSampler, ray_pos.xy).w;
		if (current_depth <= ray_pos.z)
			ray_pos += step_fwd;
	}   
	// Original texel depth    
	float src_texel_depth = texture(ReliefSampler, TexCoord).w;
	// Compute the cone ratio    
	float cone_ratio = (ray_pos.z >= src_texel_depth) ? 1.0 : length(ray_pos.xy - TexCoord) / (src_texel_depth - ray_pos.z);
	// Check for minimum value with previous pass result    
	float best_ratio = texture(ReliefSampler, TexCoord).x;
	if (cone_ratio > best_ratio)
		cone_ratio = best_ratio;
	return vec4(cone_ratio, cone_ratio, cone_ratio, cone_ratio);
}

shading lambert(in vec3 n, in vec3 v, in light l) {
	shading s;
	vec3 N = normalize(n);	// Normalize the incoming N, L and V vectors
	vec3 L = normalize(l.direction);
	s.diffuse = l.color * saturate(dot(N, L)) ; // Compute the diffuse component for each fragment
	s.specular = vec3(0); // Compute the specular component for each fragment
	s.rim = 0;
	return s;	// Write final color to the framebuffer
}
shading blinPhong1(in vec3 n, in vec3 v, in light l, vec2 dx,vec2 dy) {
	shading s;
	vec3 N = normalize(n);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V);
	float distance = length(l.direction);
	s.distance = distance * distance;
	float diff = dot(L, N);
	s.diffuse = l.color * saturate(diff);

	s.specular = l.color * pow(vec3(saturate(dot(H, N))), l.specPower)
	* smoothstep(0, 1, saturate(diff + 0.01) * 4)
		;
	s.rim = 0;
	return s;
}
shading blinPhong2(in vec3 n, in vec3 v, in light l, vec2 dx,vec2 dy) {
	shading s;
	vec3 N = normalize(n);
	// vec3 n1 = unpackNormal(texture(texture3, fs_in.uv1).rgb);
	N =  getNormalFromMap(n, texture3, fs_in.uv1, fs_in.position_M.xyz,dx,dy);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	float distance = length(l.direction);
	s.distance = distance * distance;
	float diff = dot(L, N);
	s.diffuse = l.color * saturate(diff);

	vec3 rf = normalize(reflect(-L, N));
	s.specular = l.color * vec3(pow(saturate(dot(rf, V)), l.specPower))
	* smoothstep(0, 1, saturate(diff + 0.01) * 4)
	;
	// s.specular=N;
	s.rim = 0;
	return s;	
}
shading blinPhong3(in vec3 n, in vec3 v, in light l, vec2 dx,vec2 dy) {
	shading s;
	vec3 N = normalize(n);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	float distance = length(l.direction);
	s.distance = distance * distance;
	float diff = dot(L, N);
	s.diffuse = l.color * saturate(diff);

	float specAngle = saturate(dot(reflect(-L, N), V));
	s.specular = l.color * pow(vec3(specAngle), l.specPower )
	* smoothstep(0, 1, saturate(diff + 0.01) * 4)
	;
	s.rim = 0;
	return s;
}
void main(void) {
	vec2 dx = dFdx(fs_in.uv1);
	vec2 dy = dFdy(fs_in.uv1);
	light l;
	l.direction = fs_in.lightDir;
	l.color = lightColor;
	l.power = lightPower;
	l.specPower = mt.shinines.rgb;
	// color = blinPhong_2(fs_in.normal, fs_in.lightDir, viewPos, 
	// specular_power, specular_albedo,	diffuse_albedo,	fs_in.color1);
	shading s = blinPhong2(fs_in.normal, fs_in.viewPos, l,dx,dy);
	vec2 uv;
	uv = SampleSphericalMap(normalize (fs_in.position.xyz));
	// uv = sphereMap(normalize(fs_in.position.xyz), vec3(0), fs_in.position.xyz);
	// uv = texco_refl(fs_in.normal, vec3(0)).xy;
	// if (gl_FrontFacing) {
		color = vec4(
					(
					// mt.ambient.rgb + mt.emission.rgb 
					// +
					// BicubicHermiteTextureSample(texture1, fs_in.uv1,dx,dy).rgb
					// *
					// s.specular * mt.specular.rgb
					// *
					// BicubicHermiteTextureSample(texture2, fs_in.uv1,dx,dy).rgb
					// +
					// s.diffuse * mt.diffuse.rgb
					// *
//	BicubicHermiteTextureSample
//	BicubicLagrangeTextureSample
//	texture_bicubic
//	textureGrad
//	texcubic
//	SampleTextureCatmullRom

					texture_bicubic(texture1, uv,dx/4,dy/4).rgb
					),
					mt.diffuse.a);
	// }
	// else {
		// color = vec4(1, 0, 1, 1);
	// }


}







