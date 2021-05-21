#version 410 core
// #version 450 core
// Input Built-in Variables
// in vec4 gl_FragCoord; // fragment coordinate in screen space from 0 to screen
// in bool gl_FrontFacing;
// in vec2 gl_PointCoord;

// Output
layout (location = 0) out vec4 color;
// Input from vertex shader
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
	vec2 uv1;		// first uv
	vec2 uv2;		// Second uv possible not used
	vec4 color1;		// vertex color 
	vec4 color2;	// vertex color 
} fs_in;
uniform sampler2D texture1;
// Material properties
uniform vec3 viewPos = vec3(5,5,0);
uniform vec4 diffuse_albedo = vec4(0.5, 0.2, 0.7, 1);
uniform vec3 specular_albedo = vec3(0.7);
uniform float specular_power = 128.0; // 200

uniform vec4 time;
uniform int frame;
uniform vec4 sintime;
uniform vec4 costime;
uniform vec2 screenSize;

vec3 lightColor = vec3(1.0, 1.0, 1.0);
float lightPower = 18.0; // 40

struct material{
	vec4 diffuse;		// color passed to program
	vec4 color1;		// color passed to program
	vec4 color2;		// color passed to program
	vec4 color3;		// color passed to program
	
	vec4 ambient;		// color passed to program
	vec4 emission;		// color passed to program
	vec4 translucenci;	// color passed to program
	vec4 sadowsColor;	// color passed to program
	
	vec4 specular;		// color passed to program
	vec4 reflex;		// color passed to program
	vec4 shinines;		// color passed to program
};

uniform material mt;

struct light{
	vec3 direction;
	vec3 color;
	float power;
	vec3 specPower;
};
struct shading{
	vec3 diffuse;
	vec3 specular;
	float rim;
	float distance;
};

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


vec4 blinPhong_1( in vec3 n, in vec3 l, in vec3 v, 
				in float spec_power, in vec3 spec_albedo,
				in vec4 diff_albedo, in vec4 color){
	vec3 N = normalize(n);	// Normalize the incoming N, L and V vectors
	vec3 L = normalize(l);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	vec4 diffuse = max(dot(N, L), 0.0) * diff_albedo; // Compute the diffuse component for each fragment
	vec3 specular = pow(max(dot(N, H), 0.0), spec_power) * spec_albedo; // Compute the specular component for each fragment
	return diffuse + vec4(specular, 0);	// Write final color to the framebuffer
}
vec4 blinPhong_2( in vec3 n, in vec3 l, in vec3 v, 
				in float spec_power, in vec3 spec_albedo,
				in vec4 diff_albedo, in vec4 color){
  vec3 normal = normalize(n);
  vec3 lightDir = l;
  float distance = length(lightDir);
  distance = distance * distance;
  lightDir = normalize(lightDir);
  float lambertian = max(dot(lightDir, normal), 0.0);
  float specular = 0.0;
  // if (lambertian > 0.0) {
    vec3 viewDir = normalize(v);
     // this is blinn phong
     vec3 halfDir = normalize(lightDir + viewDir);
     specular = pow(max(dot(halfDir, normal), 0.0), specular_power);
  // }
  vec3 colorLinear = diff_albedo.rgb * lambertian * lightColor * lightPower / distance +
                     spec_albedo * specular * lightColor * lightPower / distance;
  return vec4(colorLinear.rgb, diff_albedo.a);				
}
vec4 blinPhong_3( in vec3 n, in vec3 l, in vec3 v, // this is phong, good specular in angular
				in float spec_power, in vec3 spec_albedo,
				in vec4 diff_albedo, in vec4 color){
	vec3 normal = normalize(n);
	vec3 lightDir = l;
	float distance = length(lightDir);
	distance = distance * distance;
	lightDir = normalize(lightDir);
	float lambertian = max(dot(lightDir, normal), 0.0);
	float specular = 0.0;
	// if (lambertian > 0.0) {
		vec3 viewDir = normalize(v);
		 vec3 reflectDir = reflect(-lightDir, normal);
		 float specAngle = max(dot(reflectDir, viewDir), 0.0);
		 specular = pow(specAngle, specular_power/4.0);
	// }
	vec3 colorLinear = lambertian * diff_albedo.rgb * lightColor * lightPower / distance +
					 spec_albedo * specular * lightColor * lightPower / distance;
	return vec4(colorLinear.rgb, diff_albedo.a);				
}

shading lambert( in vec3 n, in vec3 v, in light l){
	shading s;
	vec3 N = normalize(n);	// Normalize the incoming N, L and V vectors
	vec3 L = normalize(l.direction);
	s.diffuse = l.color * max(dot(N, L), 0.0)*l.power; // Compute the diffuse component for each fragment
	s.specular = vec3(0); // Compute the specular component for each fragment
	s.rim = 0;
	return s;	// Write final color to the framebuffer
}
shading blinPhong1( in vec3 n, in vec3 v, in light l){
	shading s;
	vec3 N = normalize(n);	// Normalize the incoming N, L and V vectors
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	s.diffuse = l.color * max(dot(N, L), 0.0); // Compute the diffuse component for each fragment
	s.specular = l.color* pow(vec3(max(dot(N, H), 0.0)), l.specPower); // Compute the specular component for each fragment
	s.rim = 0;
	return s;	// Write final color to the framebuffer
}
shading blinPhong2( in vec3 n, in vec3 v, in light l){
	shading s;
	vec3 N = normalize(n);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V);
	float distance = length(l.direction);
	s.distance = distance * distance;
	s.diffuse = l.color * max(dot(L, N), 0.0)* l.power/ s.distance;
	s.specular = l.color* pow(vec3(max(dot(H, N), 0.0)) , l.specPower) * l.power / s.distance;
	s.rim = 0;
	return s;
}
shading blinPhong3( in vec3 n, in vec3 v, in light l){
	shading s;
	vec3 N = normalize(n);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	float distance = length(l.direction);
	float specAngle = max(dot(reflect(-L, N), V), 0.0);
	s.distance = distance * distance;
	s.diffuse = l.color* max(dot(L, N), 0.0) * l.power / s.distance;
	s.specular = l.color* pow(vec3(specAngle) , l.specPower/4.0) * l.power / s.distance;
	s.rim = 0;
	return s;				
}
float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233)+sintime.xy*11)) * (43758.5453+sintime.x*10));
}
float rand2(vec2 co, float seed){
	float a = 12.9898+fract(seed/1234.112);
	float b = 78.233+fract(seed/1512.112);
	float c = 43758.5453;
	float dt= dot(co.xy ,vec2(a,b));
	float sn= mod(dt,3.14);
	return fract(sin(sn) * c);
}

const float PHI 	  	= 1.61803398874989484820459;				// Φ = Golden Ratio
const float F_PI      	= 3.14159265358979323846;					/* pi */
const float F_2PI     	= 6.2831853071795864769252867666;			/* 2*pi */
const float F_4PI     	= 12.566370614359172953850573533118;		/* 2*pi */
const float F_1_PI    	= 0.318309886183790671538;					/* 1/pi */
const float F_1_2PI    	= 0.159154943091895335768;					/* 1/(2*pi) */
const float F_PI_2    	= 1.57079632679489661923;					/* pi/2 */
const float F_PI_4    	= 0.78539816339744830962;					/* pi/4 */
const float F_SQRT2   	= 1.4142135623730950488016887242;			/* sqrt(2) */
const float F_SQRT3   	= 1.73205080756887729352;					/* sqrt(3) */
const float F_SQRT1_2 	= 0.7071067811865475244008443621048490;		/* 1/sqrt(2) */
const float F_SQRT1_3 	= 0.57735026918962576450;					/* 1/sqrt(3) */
const float F_E       	= 2.7182818284590452353602874714;			/* e euler */
const float F_LOG2E   	= 1.4426950408889634074;					/* log_2 e */
const float F_LOG10E  	= 0.43429448190325182765;					/* log_10 e */
const float F_LN2     	= 0.6931471805599453094172321215;			/* log_e 2 */
const float F_LN10    	= 2.30258509299404568402;					/* log_e 10 */

float gold_noise(vec2 xy, float seed){
    return fract(tan(distance(xy * PHI, xy) * seed)*xy.x );
}
vec3 gold_noise(vec2 xy, vec3 seed){
	
	return vec3(gold_noise(xy*1000, fract(seed.x )+1),
                gold_noise(xy*1000, fract(seed.y )+2),
                gold_noise(xy*1000, fract(seed.z )+3)
				);
}
vec3 gold_noise2(vec2 xy, vec3 seed){
	return vec3(rand2(xy, (seed.x ) ),
                rand2(xy, (seed.y ) ),
                rand2(xy, (seed.z ) )
				);
}


vec3 mod7(vec3 x) {
  return x - floor(x * (1.0 / 7.0)) * 7.0;
}
vec4 mod7(vec4 x) {
  return x - floor(x * (1.0 / 7.0)) * 7.0;
}
vec2 mod289(vec2 x) {
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
vec3 mod289(vec3 x) {
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
vec4 mod289(vec4 x) {
  return x - floor(x * (1.0 / 289.0)) * 289.0;
}
vec3 permutep(vec3 x) {
  return mod289((34.0 * x + 1.0) * x);
}
vec4 permutep(vec4 x) {
  return mod289((34.0 * x + 1.0) * x);
}
vec3 permute(vec3 x) {
  return mod289(((x*34.0)+1.0)*x);
}
vec4 permute(vec4 x){
  return mod289(((x*34.0)+1.0)*x);
}
vec4 taylorInvSqrt(vec4 r){
  return 1.79284291400159 - 0.85373472095314 * r;
}
vec2 fade(vec2 t) {
  return t*t*t*(t*(t*6.0-15.0)+10.0);
}

float cnoise(vec2 P){
  vec4 Pi = floor(P.xyxy) + vec4(0.0, 0.0, 1.0, 1.0);
  vec4 Pf = fract(P.xyxy) - vec4(0.0, 0.0, 1.0, 1.0);
  Pi = mod289(Pi); // To avoid truncation effects in permutation
  vec4 ix = Pi.xzxz;
  vec4 iy = Pi.yyww;
  vec4 fx = Pf.xzxz;
  vec4 fy = Pf.yyww;

  vec4 i = permute(permute(ix) + iy);

  vec4 gx = fract(i * (1.0 / 41.0)) * 2.0 - 1.0 ;
  vec4 gy = abs(gx) - 0.5 ;
  vec4 tx = floor(gx + 0.5);
  gx = gx - tx;

  vec2 g00 = vec2(gx.x,gy.x);
  vec2 g10 = vec2(gx.y,gy.y);
  vec2 g01 = vec2(gx.z,gy.z);
  vec2 g11 = vec2(gx.w,gy.w);

  vec4 norm = taylorInvSqrt(vec4(dot(g00, g00), dot(g01, g01), dot(g10, g10), dot(g11, g11)));
  g00 *= norm.x;  
  g01 *= norm.y;  
  g10 *= norm.z;  
  g11 *= norm.w;  

  float n00 = dot(g00, vec2(fx.x, fy.x));
  float n10 = dot(g10, vec2(fx.y, fy.y));
  float n01 = dot(g01, vec2(fx.z, fy.z));
  float n11 = dot(g11, vec2(fx.w, fy.w));

  vec2 fade_xy = fade(Pf.xy);
  vec2 n_x = mix(vec2(n00, n01), vec2(n10, n11), fade_xy.x);
  float n_xy = mix(n_x.x, n_x.y, fade_xy.y);
  return 2.3 * n_xy;
}
float pnoise(vec2 P, vec2 rep){
  vec4 Pi = floor(P.xyxy) + vec4(0.0, 0.0, 1.0, 1.0);
  vec4 Pf = fract(P.xyxy) - vec4(0.0, 0.0, 1.0, 1.0);
  Pi = mod(Pi, rep.xyxy); // To create noise with explicit period
  Pi = mod289(Pi);        // To avoid truncation effects in permutation
  vec4 ix = Pi.xzxz;
  vec4 iy = Pi.yyww;
  vec4 fx = Pf.xzxz;
  vec4 fy = Pf.yyww;

  vec4 i = permute(permute(ix) + iy);

  vec4 gx = fract(i * (1.0 / 41.0)) * 2.0 - 1.0 ;
  vec4 gy = abs(gx) - 0.5 ;
  vec4 tx = floor(gx + 0.5);
  gx = gx - tx;

  vec2 g00 = vec2(gx.x,gy.x);
  vec2 g10 = vec2(gx.y,gy.y);
  vec2 g01 = vec2(gx.z,gy.z);
  vec2 g11 = vec2(gx.w,gy.w);

  vec4 norm = taylorInvSqrt(vec4(dot(g00, g00), dot(g01, g01), dot(g10, g10), dot(g11, g11)));
  g00 *= norm.x;  
  g01 *= norm.y;  
  g10 *= norm.z;  
  g11 *= norm.w;  

  float n00 = dot(g00, vec2(fx.x, fy.x));
  float n10 = dot(g10, vec2(fx.y, fy.y));
  float n01 = dot(g01, vec2(fx.z, fy.z));
  float n11 = dot(g11, vec2(fx.w, fy.w));

  vec2 fade_xy = fade(Pf.xy);
  vec2 n_x = mix(vec2(n00, n01), vec2(n10, n11), fade_xy.x);
  float n_xy = mix(n_x.x, n_x.y, fade_xy.y);
  return 2.3 * n_xy;
}
float snoise(vec2 v)  {
  const vec4 C = vec4(0.211324865405187,  // (3.0-sqrt(3.0))/6.0
                      0.366025403784439,  // 0.5*(sqrt(3.0)-1.0)
                     -0.577350269189626,  // -1.0 + 2.0 * C.x
                      0.024390243902439); // 1.0 / 41.0
// First corner
  vec2 i  = floor(v + dot(v, C.yy) );
  vec2 x0 = v -   i + dot(i, C.xx);

// Other corners
  vec2 i1;
  //i1.x = step( x0.y, x0.x ); // x0.x > x0.y ? 1.0 : 0.0
  //i1.y = 1.0 - i1.x;
  i1 = (x0.x > x0.y) ? vec2(1.0, 0.0) : vec2(0.0, 1.0);
  // x0 = x0 - 0.0 + 0.0 * C.xx ;
  // x1 = x0 - i1 + 1.0 * C.xx ;
  // x2 = x0 - 1.0 + 2.0 * C.xx ;
  vec4 x12 = x0.xyxy + C.xxzz;
  x12.xy -= i1;

// Permutations
  i = mod289(i); // Avoid truncation effects in permutation
  vec3 p = permute( permute( i.y + vec3(0.0, i1.y, 1.0 ))
		+ i.x + vec3(0.0, i1.x, 1.0 ));

  vec3 m = max(0.5 - vec3(dot(x0,x0), dot(x12.xy,x12.xy), dot(x12.zw,x12.zw)), 0.0);
  m = m*m ;
  m = m*m ;

// Gradients: 41 points uniformly over a line, mapped onto a diamond.
// The ring size 17*17 = 289 is close to a multiple of 41 (41*7 = 287)

  vec3 x = 2.0 * fract(p * C.www) - 1.0;
  vec3 h = abs(x) - 0.5;
  vec3 ox = floor(x + 0.5);
  vec3 a0 = x - ox;

// Normalise gradients implicitly by scaling m
// Approximation of: m *= inversesqrt( a0*a0 + h*h );
  m *= 1.79284291400159 - 0.85373472095314 * ( a0*a0 + h*h );

// Compute final noise value at P
  vec3 g;
  g.x  = a0.x  * x0.x  + h.x  * x0.y;
  g.yz = a0.yz * x12.xz + h.yz * x12.yw;
  return 130.0 * dot(m, g);
}
vec2 cellular2x2(vec2 P) {
	float K = 0.142857142857; // 1/7
	float K2 = 0.0714285714285; // K/2
	float jitter = 0.8; // jitter 1.0 makes F1 wrong more often
	vec2 Pi = mod289(floor(P));
 	vec2 Pf = fract(P);
	vec4 Pfx = Pf.x + vec4(-0.5, -1.5, -0.5, -1.5);
	vec4 Pfy = Pf.y + vec4(-0.5, -0.5, -1.5, -1.5);
	vec4 p = permutep(Pi.x + vec4(0.0, 1.0, 0.0, 1.0));
	p = permutep(p + Pi.y + vec4(0.0, 0.0, 1.0, 1.0));
	vec4 ox = mod7(p)*K+K2;
	vec4 oy = mod7(floor(p*K))*K+K2;
	vec4 dx = Pfx + jitter*ox;
	vec4 dy = Pfy + jitter*oy;
	vec4 d = dx * dx + dy * dy; // d11, d12, d21 and d22, squared
	// Sort out the two smallest distances
#if 0
	// Cheat and pick only F1
	d.xy = min(d.xy, d.zw);
	d.x = min(d.x, d.y);
	return vec2(sqrt(d.x)); // F1 duplicated, F2 not computed
#else
	// Do it right and find both F1 and F2
	d.xy = (d.x < d.y) ? d.xy : d.yx; // Swap if smaller
	d.xz = (d.x < d.z) ? d.xz : d.zx;
	d.xw = (d.x < d.w) ? d.xw : d.wx;
	d.y = min(d.y, d.z);
	d.y = min(d.y, d.w);
	return sqrt(d.xy);
#endif
}
vec2 cellular(vec2 P) {
	float K = 0.142857142857; // 1/7
	float Ko = 0.428571428571; // 3/7
	float jitter = 1.0; // Less gives more regular pattern
	vec2 Pi = mod289(floor(P));
 	vec2 Pf = fract(P);
	vec3 oi = vec3(-1.0, 0.0, 1.0);
	vec3 of = vec3(-0.5, 0.5, 1.5);
	vec3 px = permute(Pi.x + oi);
	vec3 p = permute(px.x + Pi.y + oi); // p11, p12, p13
	vec3 ox = fract(p*K) - Ko;
	vec3 oy = mod7(floor(p*K))*K - Ko;
	vec3 dx = Pf.x + 0.5 + jitter*ox;
	vec3 dy = Pf.y - of + jitter*oy;
	vec3 d1 = dx * dx + dy * dy; // d11, d12 and d13, squared
	p = permute(px.y + Pi.y + oi); // p21, p22, p23
	ox = fract(p*K) - Ko;
	oy = mod7(floor(p*K))*K - Ko;
	dx = Pf.x - 0.5 + jitter*ox;
	dy = Pf.y - of + jitter*oy;
	vec3 d2 = dx * dx + dy * dy; // d21, d22 and d23, squared
	p = permute(px.z + Pi.y + oi); // p31, p32, p33
	ox = fract(p*K) - Ko;
	oy = mod7(floor(p*K))*K - Ko;
	dx = Pf.x - 1.5 + jitter*ox;
	dy = Pf.y - of + jitter*oy;
	vec3 d3 = dx * dx + dy * dy; // d31, d32 and d33, squared
	// Sort out the two smallest distances (F1, F2)
	vec3 d1a = min(d1, d2);
	d2 = max(d1, d2); // Swap to keep candidates for F2
	d2 = min(d2, d3); // neither F1 nor F2 are now in d3
	d1 = min(d1a, d2); // F1 is now in d1
	d2 = max(d1a, d2); // Swap to keep candidates for F2
	d1.xy = (d1.x < d1.y) ? d1.xy : d1.yx; // Swap if smaller
	d1.xz = (d1.x < d1.z) ? d1.xz : d1.zx; // F1 is in d1.x
	d1.yz = min(d1.yz, d2.yz); // F2 is now not in d2.yz
	d1.y = min(d1.y, d1.z); // nor in  d1.z
	d1.y = min(d1.y, d2.x); // F2 is in d1.y, we're done.
	return sqrt(d1.xy);
}
float cross( vec2 v,  vec2 val) {
	return (v.x * val.y) - (v.y * val.x);
}
float sqr( vec2 v) {
	return v.x * v.x + v.y * v.y;
}
vec2 closestToLine( vec2 point,  vec2 lineStart,  vec2 lineEnd) {
	vec2 dr = lineEnd - lineStart;
	float  dt = dot(point - lineStart, dr);
	float  len_s = sqr(dr);
	float  param = -1;
	if (len_s != 0) //in case of 0 length line
		param = dt / len_s;
	vec2  pointProjection;
	if (param < 0) {
		pointProjection = lineStart;
	}
	else if (param > 1) {
		pointProjection = lineEnd;
	}
	else {
		pointProjection = lineStart + param * dr;
	}
	return pointProjection;
}

float DistanceToInfiniteLine( vec2 base,  vec2 rclDirect,  vec2 point) {
	vec2 dir = rclDirect-base;
	return abs((cross(dir, base - point))) / length(dir);
}
float pDistance( vec2 l1, vec2 l2, vec2 point ) {
	vec2 dr = l2 - l1;
	float  dt = dot(point - l1, dr);
	float  len_sq = sqr(dr);
	float  param = -1;
	if (len_sq != 0) //in case of 0 length line
		param = dt / len_sq;
	vec2  xy;
	if (param < 0) {
		xy = l1;
	}
	else if (param > 1) {
		xy = l2;
	}
	else {
		xy = l1 + param * dr;
	}
	vec2  dxy = point - xy;
	return (length(dxy));
}
 float angle_to( vec2 v,  vec2 p_vec2) {
	return atan(cross(v, p_vec2), dot(v, p_vec2));
}
 float angle_to_point(vec2 v,  vec2 p_vec2) {
	return atan(v.y - p_vec2.y, v.x - p_vec2.x);
}
float lineDistance(vec2 a, vec2 b, vec2 p) {
    vec2 pa = p-a;
    vec2 ba = b-a;
	float t = clamp(dot(pa,ba)/dot(ba,ba), 0.0, 1.0);
    return length(pa-ba*t);
}
void main(void){
	float sz = 0.00113;
	light l;
	l.direction=fs_in.lightDir;
	l.color=lightColor;
	l.power = lightPower;
	l.specPower = mt.shinines.rgb;
	// color = blinPhong_2(fs_in.normal, fs_in.lightDir, viewPos, 
	// specular_power, specular_albedo,	diffuse_albedo,	fs_in.color1);
	shading s = blinPhong1(fs_in.normal, viewPos, l);
	vec2 uv = fs_in.uv1;
	uv.y = 1-uv.y;
	// vec3 col = vec3(1-length(uv*vec2(1,0.6)-vec2(0.5, 0.25))*5);
	// col = smoothstep(0, 1, smoothstep(0, 1, smoothstep(0, 1, col)));
	// vec3 col = vec3(rand(uv))-0.5;
	vec3 col = (gold_noise2(uv+1.5,(time.xyz))); //random rgb value
	// vec3 col = vec3(rand2(uv*1+0.5,1+time.w*10).x); //random rgb value
	// vec2 p1 = (10,10);
	// vec2 p2 = (90,80);
	if(gl_FrontFacing){
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
					/226
					+
					pow(texture(texture1, uv).rgb,1/1.2)
					
					// vec3(
					// texture(texture1, fs_in.uv1+vec2(-sz,-sz)).rgb+
					// texture(texture1, fs_in.uv1+vec2(-sz,0  )).rgb+
					// texture(texture1, fs_in.uv1+vec2(-sz,sz )).rgb+
					
					// texture(texture1, fs_in.uv1+vec2(sz,-sz)).rgb+
					// texture(texture1, fs_in.uv1+vec2(sz,0  )).rgb+
					// texture(texture1, fs_in.uv1+vec2(sz,sz )).rgb+
					
					// texture(texture1, fs_in.uv1+vec2(0,-sz)).rgb+
					// texture(texture1, fs_in.uv1+vec2(0,0  )).rgb+
					// texture(texture1, fs_in.uv1+vec2(0,sz )).rgb)/vec3(9)
					
		,
		mt.diffuse.a);
	}
	else{
		color = vec4(1,0,1,1);
	}
		
		
		
		
		


}
