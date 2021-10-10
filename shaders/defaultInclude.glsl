#version 430 
// defaultInclude.glsl

// Input Built-in Variables
// in vec4 gl_FragCoord;
// in bool gl_FrontFacing;
// in vec2 gl_PointCoord;


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


// constants
const float PHI = 1.61803398874989484820459;					// Φ = Golden Ratio
const float F_PI = 3.14159265358979323846;						/* pi */
const float F_2PI = 6.2831853071795864769252867666;				/* 2*pi */
const float F_4PI = 12.566370614359172953850573533118;			/* 2*pi */
const float F_1_PI = 0.318309886183790671538;					/* 1/pi */
const float F_1_2PI = 0.159154943091895335768;					/* 1/(2*pi) */
const float F_PI_2 = 1.57079632679489661923;					/* pi/2 */
const float F_PI_4 = 0.78539816339744830962;					/* pi/4 */
const float F_SQRT2 = 1.4142135623730950488016887242;			/* sqrt(2) */
const float F_SQRT3 = 1.73205080756887729352;					/* sqrt(3) */
const float F_SQRT1_2 = 0.7071067811865475244008443621048490;	/* 1/sqrt(2) */
const float F_SQRT1_3 = 0.57735026918962576450;					/* 1/sqrt(3) */
const float F_E = 2.7182818284590452353602874714;				/* e euler */
const float F_LOG2E = 1.4426950408889634074;					/* log_2 e */
const float F_LOG10E = 0.43429448190325182765;					/* log_10 e */
const float F_LN2 = 0.6931471805599453094172321215;				/* log_e 2 */
const float F_LN10 = 2.30258509299404568402;					/* log_e 10 */

const float c_x0 = -1.0;
const float c_x1 =  0.0;
const float c_x2 =  1.0;
const float c_x3 =  2.0;

// uniforms
uniform int frame;
uniform vec4 time;
uniform vec4 sintime;
uniform vec4 costime;
uniform vec2 screenSize;

uniform vec3 viewPos;
uniform vec3 lightColor = vec3(1.0, 1.0, 1.0);
uniform float lightPower = 18.0; // 40
uniform vec3 light_pos = vec3(1, 0, 0);
// uniform vec3 light_pos = vec3(0, 0, 2);

// Material properties
uniform material mt;

uniform vec4 diffuse_albedo = vec4(0.5, 0.2, 0.7, 1);
uniform vec3 specular_albedo = vec3(0.7);
uniform float specular_power = 128.0; // 200



// functions

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

float cross(vec2 v, vec2 val) {
	return (v.x * val.y) - (v.y * val.x);
}
float sqr(vec2 v) {
	return v.x * v.x + v.y * v.y;
}


// w0, w1, w2, and w3 are the four cubic B-spline basis functions
float w0(float a) {
	return (1.0 / 6.0) * (a * (a * (-a + 3.0) - 3.0) + 1.0);
}

float w1(float a) {
	return (1.0 / 6.0) * (a * a * (3.0 * a - 6.0) + 4.0);
}

float w2(float a) {
	return (1.0 / 6.0) * (a * (a * (-3.0 * a + 3.0) + 3.0) + 1.0);
}

float w3(float a) {
	return (1.0 / 6.0) * (a * a * a);
}

// g0 and g1 are the two amplitude functions
float g0(float a) {
	return w0(a) + w1(a);
}

float g1(float a) {
	return w2(a) + w3(a);
}

// h0 and h1 are the two offset functions
float h0(float a) {
	return -1.0 + w1(a) / (w0(a) + w1(a));
}

float h1(float a) {
	return 1.0 + w3(a) / (w2(a) + w3(a));
}


vec4 CubicLagrange(vec4 A, vec4 B, vec4 C, vec4 D, float t) {
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

vec4 CubicHermite(vec4 A, vec4 B, vec4 C, vec4 D, float t) {
	float t2 = t * t;
	float t3 = t * t * t;
	vec4 a = -A / 2.0 + (3.0 * B) / 2.0 - (3.0 * C) / 2.0 + D / 2.0;
	vec4 b = A - (5.0 * B) / 2.0 + 2.0 * C - D / 2.0;
	vec4 c = -A / 2.0 + C / 2.0;
	vec4 d = B;

	return a * t3 + b * t2 + c * t + d;
}

// https://newbedev.com/efficient-bicubic-filtering-code-in-glsl
// I decided to take a minute to dig my old Perforce activities and found the missing cubic() function; enjoy! :)
vec4 cubic1(float v){
    vec4 n = vec4(1.0, 2.0, 3.0, 4.0) - v;
    vec4 s = n * n * n;
    float x = s.x;
    float y = s.y - 4.0 * s.x;
    float z = s.z - 4.0 * s.y + 6.0 * s.x;
    float w = 6.0 - x - y - z;
    return vec4(x, y, z, w);
}

// The missing function cubic() in JAre's answer could look like this:
vec4 cubic2(float v){
    float x2 = v * v;
    float x3 = x2 * v;
    vec4 w;
    w.x =   -x3 + 3*x2 - 3*v + 1;
    w.y =  3*x3 - 6*x2       + 4;
    w.z = -3*x3 + 3*x2 + 3*v + 1;
    w.w =  x3;
    return w / 6.0;
}

// bernstein polynomial form, usefull to cubic bezier
vec4 cubic3(float t){
    float t2 = t * t;
    float t3 = t2 * t;
    vec4 w;
    w.x =   -t3 + 3*t2 - 3*t + 1;
    w.y =  3*t3 - 6*t2 + 3*t     ;
    w.z = -3*t3 + 3*t2 ;
    w.w =  t3;
    return w ;
	// return p0*w.x + p1*w.y + p2*w.z + p3*w.w 
}

// derivative velocity P'
vec4 cubic_d_v(float t){
    float t2 = t  * t;
    float t3 = t2 * t;
    vec4 w;
    w.x = -3 * t2 + 6  * t - 3		;
    w.y =  9 * t2 - 12 * t + 3		;
    w.z = -9 * t2 + 6  * t 			;
    w.w =  3 * t2;
    return w ;
	// return p0*w.x + p1*w.y + p2*w.z + p3*w.w 
}
// derivative aceleration P''
vec4 cubic_d_a(float t){
    float t2 = t  * t;
    float t3 = t2 * t;
    vec4 w;
    w.x = -6  * t  + 6 		;
    w.y =  18 * t  - 12   	;
    w.z = -18 * t  + 6 	 	;
    w.w =  6  * t2			;
    return w ;
	// return p0*w.x + p1*w.y + p2*w.z + p3*w.w 
}
// derivative jerk P'''
vec4 cubic_d_j(vec4 p0, vec4 p1, vec4 p2, vec4 p3){	
	return	(p0 * -6  )+
			(p1 *  18 )+
			(p2 * -18 )+
			(p3 *  6  );
}

// -b+-Vb2-4ac/2a

vec2 bascara( float a, float b, float c){
	float p0, p1, p2, p3;
	a = -3 * p0 +9  * p1 -9 * p2 + 3 * p3;
	b =  6 * p0 -12 * p1 +6 * p2;
	c = -3 * p0 +3  * p1;
	
	return vec2(
	(-b+sqrt(b*b-4*a*c))/2*a,
	(-b-sqrt(b*b-4*a*c))/2*a);
}

vec4 cubic_d_d(float t){
	vec4 p0, p1, p2, p3;
    float t2 = t * t;
    return t2*(-3 * p0 +9   * p1 -9 * p2 + 3 * p3)+
		   t *( 6 * p0 -12  * p1 +6 * p2) +
			   -3 * p0 +3   * p1;
}






// For t between 0 and 1 you get an interpolation between 0 and 1
// smoothstep implementation
float cubicSpline (float t) {
    // original function: 3t² - 2t³
    return (t * t) * (3.0 - 2.0*t);
}

// Interpolating arbitrary values: (t between 0 and 1, again)
float cubicSpline (float begin, float end, float t) {
    return begin + (cubicSpline(t) * (end-begin));
}

vec3 unpackNormal(vec3 n, vec3 scale){
	vec3 r=n*2-1;
	return normalize(mix(vec3(0,0,1.0),r,scale));
}


vec2 SampleSphericalMap(vec3 v) {
	const vec2 invAtan = vec2(0.15915494309189533, 0.31830988618); // vec2 invAtan vec2(1/(2*PI),1/PI);
	// const vec2 invAtan = vec2(0.159155, 0.3183);
	vec2 uv = vec2(atan(v.x, v.y), asin(-v.z));
	uv *= invAtan;
	uv += 0.5;
	return uv;
}

vec2 sphereMap(vec3 n, vec3 v, vec3 pos) {
	vec3 I = normalize(v - pos);
	vec3 R = reflect(I, normalize(n));
	float M = 2. * sqrt(pow(R.x, 2.) + pow(R.y, 2.) + pow(R.z + 1., 2.));
	vec2 uv = R.xy / M + .5;
	return uv;
}

vec3 texco_refl(vec3 vn, vec3 view) {
	return view - 2.0 * dot(vn, view) * vn;
}



float rand(vec2 co) {
	return fract(sin(dot(co.xy, vec2(12.9898, 78.233) + sintime.xy * 11)) * (43758.5453 + sintime.x * 10));
}

float rand2(vec2 co, float seed) {
	float a = 12.9898 + fract(seed / 1234.112);
	float b = 78.233 + fract(seed / 1512.112);
	float c = 43758.5453;
	float dt = dot(co.xy, vec2(a, b));
	float sn = mod(dt, 3.14);
	return fract(sin(sn) * c);
}

float gold_noise(vec2 xy, float seed) {
	return fract(tan(distance(xy * PHI, xy) * seed) * xy.x);
}

vec3 gold_noise(vec2 xy, vec3 seed) {
	return vec3(gold_noise(xy * 1000, fract(seed.x) + 1),
				gold_noise(xy * 1000, fract(seed.y) + 2),
				gold_noise(xy * 1000, fract(seed.z) + 3)
	);
}

vec3 gold_noise2(vec2 xy, vec3 seed) {
	return vec3(rand2(xy, (seed.x)),
				rand2(xy, (seed.y)),
				rand2(xy, (seed.z))
	);
}


vec2 random2( vec2 p ) {
    return fract(sin(vec2(dot(p,vec2(127.1,311.7)),dot(p,vec2(269.5,183.3))))*43758.5453);
}

float  rn(float xx){         
    float x0=floor(xx);
    float x1=x0+1;
    float v0 = fract(sin (x0*.014686)*31718.927+x0);
    float v1 = fract(sin (x1*.014686)*31718.927+x1);          

    return (v0*(1-fract(xx))+v1*(fract(xx)))*2-1*sin(xx);
}




//to 1d functions

//get a scalar random value from a 3d value
float rand3dTo1d(vec3 value, vec3 dotDir){
	const vec3 dotDir2 = vec3(12.9898, 78.233, 37.719);
	//make value smaller to avoid artefacts
	vec3 smallValue = sin(value);
	//get scalar value from 3d vector
	float random = dot(smallValue, dotDir);
	//make value more random by making it bigger and then taking the factional part
	random = fract(sin(random) * 143758.5453);
	return random;
}

float rand2dTo1d(vec2 value, vec2 dotDir){
	const vec2 dotDir2 = vec2(12.9898, 78.233);
	vec2 smallValue = sin(value);
	float random = dot(smallValue, dotDir);
	random = fract(sin(random) * 143758.5453);
	return random;
}

float rand1dTo1d(float value, float mutator){
	const float mutator2 = 0.546;
	float random = fract(sin(value + mutator) * 143758.5453);
	return random;
}

//to 2d functions
vec2 rand3dTo2d(vec3 value){
	return vec2(
		rand3dTo1d(value, vec3(12.989, 78.233, 37.719)),
		rand3dTo1d(value, vec3(39.346, 11.135, 83.155))
	);
}

vec2 rand2dTo2d(vec2 value){
	return vec2(
		rand2dTo1d(value, vec2(12.989, 78.233)),
		rand2dTo1d(value, vec2(39.346, 11.135))
	);
}

vec2 rand1dTo2d(float value){
	return vec2(
		rand1dTo1d(value, 3.9812),
		rand1dTo1d(value, 7.1536)
	);
}

//to 3d functions
vec3 rand3dTo3d(vec3 value){
	return vec3(
		rand3dTo1d(value, vec3(12.989, 78.233, 37.719)),
		rand3dTo1d(value, vec3(39.346, 11.135, 83.155)),
		rand3dTo1d(value, vec3(73.156, 52.235, 09.151))
	);
}

vec3 rand2dTo3d(vec2 value){
	return vec3(
		rand2dTo1d(value, vec2(12.989, 78.233)),
		rand2dTo1d(value, vec2(39.346, 11.135)),
		rand2dTo1d(value, vec2(73.156, 52.235))
	);
}

vec3 rand1dTo3d(float value){
	return vec3(
		rand1dTo1d(value, 3.9812),
		rand1dTo1d(value, 7.1536),
		rand1dTo1d(value, 5.7241)
	);
}



// #define TRANSFORM_TEX(tex,name) (tex.xy * name##_ST.xy + name##_ST.zw)
vec4 triplanarMap(sampler2D _MainTex,vec3 normal, vec3 worldPos, vec3 scale, float sharpnes){
	//calculate UV coordinates for three projections
	worldPos *= scale;
	vec2 uv_front = (worldPos.xy);
	vec2 uv_side = 	(worldPos.zy);
	vec2 uv_top = 	(worldPos.xz);

	//read texture at uv position of the three projections
	vec4 col_front = 	texture(_MainTex, uv_front);
	vec4 col_side = 	texture(_MainTex, uv_side);
	vec4 col_top = 		texture(_MainTex, uv_top);

	//generate weights from world normals
	vec3 weights = normal;
	//show texture on both sides of the object (positive and negative)
	weights = abs(weights);
	//make the transition sharper
	weights = pow(weights, sharpnes);
	//make it so the sum of all components is 1, normalize
	weights = weights / (weights.x + weights.y + weights.z);

	//combine weights with projected colors
	col_front *= weights.z;
	col_side *= weights.x;
	col_top *= weights.y;

	//combine the projected colors
	vec4 col = col_front + col_side + col_top;

	return col;
}





vec3 hashRandom( uvec3 x ){
	const uint k = 1103515245;  // GLIB C
	//const uint k = 134775813U;   // Delphi and Turbo Pascal
	//const uint k = 20170906U;    // Today's date (use three days ago's dateif you want a prime)
	//const uint k = 1664525U;     // Numerical Recipes
    x = ((x>>8U)^x.yzx)*k;
    x = ((x>>8U)^x.yzx)*k;
    x = ((x>>8U)^x.yzx)*k;

    return vec3(x)*(1.0/float(0xffffffff));
}

uint hashInt1D( uint x ){
	x += x >> 11;
	x ^= x << 7;
	x += x >> 15;
	x ^= x << 5;
	x += x >> 12;
	x ^= x << 9;
	return x;
}

uint hashInt2D( uint x, uint y ){
	x += x >> 11;
	x ^= x << 7;
	x += y;
	x ^= x << 6;
	x += x >> 15;
	x ^= x << 5;
	x += x >> 12;
	x ^= x << 9;
	return x;
}

uint hashInt3D( uint x, uint y, uint z ){
	x += x >> 11;
	x ^= x << 7;
	x += y;
	x ^= x << 3;
	x += z ^ ( x >> 14 );
	x ^= x << 6;
	x += x >> 15;
	x ^= x << 5;
	x += x >> 12;
	x ^= x << 9;
	return x;
}

uint hash( uint x ) {
    x += ( x << 10 );
    x ^= ( x >>  6 );
    x += ( x <<  3 );
    x ^= ( x >> 11 );
    x += ( x << 15 );
    return x;
}

// Now for the bit-twiddling random() function.  Let's keep it simple and stick with one input for now:
float random( float f ) {
    const uint mantissaMask = 0x007FFFFFu;
    const uint one          = 0x3F800000u;
   
    uint h = hash( floatBitsToUint( f ) );
    h &= mantissaMask;
    h |= one;
    
    float  r2 = uintBitsToFloat( h );
    return r2 - 1.0;
}


/*

// Thomas Wang's hash
uint HashThomasWang(uint key){
	key += ~(key << 15);
	key ^= (key >> 10);
	key += (key << 3);
	key ^= (key >> 6);
	key += ~(key << 11);
	key ^= (key >> 16);
	return key;
}

uint btHashString(uint v){
	uint InitialFNV = 2166136261;
	uint FNVMultiple = 16777619;	
	uint hash = InitialFNV; // Fowler / Noll / Vo (FNV) Hash 
	hash = hash ^ v; // xor  the low 8 bits 
	hash = hash * FNVMultiple; // multiply by the magic number 
	m_hash = hash;
}

struct Plane{
	vec3 normal;
	float dist;  // distance below origin - the D from plane equasion Ax+By+Cz+D=0
};


vec3 PlaneLineIntersection( Plane plane,  vec3 p0,  vec3 p1){
	// returns the point where the line p0-p1 intersects the plane n&d
	vec3 dif;
	dif = p1 - p0;
	float dn = dot(plane.normal, dif);
	float t = -(plane.dist + dot(plane.normal, p0)) / dn;
	return p0 + (dif * t);
}

float DistanceBetweenLines( vec3 ustart,  vec3 udir,  vec3 vstart,  vec3 vdir, out vec3 upoint, out vec3 vpoint){
	vec3 cp;
	cp = normalize(cross(udir, vdir));

	float distu = -dot(cp, ustart);
	float distv = -dot(cp, vstart);
	float dist = (float)abs(distu - distv);
	if (upoint)
	{
		Plane plane;
		plane.normal = normalize(cross(vdir, cp));
		plane.dist = -dot(plane.normal, vstart);
		upoint = PlaneLineIntersection(plane, ustart, ustart + udir);
	}
	if (vpoint)
	{
		Plane plane;
		plane.normal = normalize(cross(udir, cp));
		plane.dist = -dot(plane.normal, ustart);
		vpoint = PlaneLineIntersection(plane, vstart, vstart + vdir);
	}
	return dist;
}

int NextPow2(int v){
	int n = 1;
	while (n < v)
		n *= 2;
	return n;
}
int PrevPow2(int v){
	int n = 1;
	while (n < v)
		n *= 2;
	return n / 2;
}
int closestPow2(int n){
	int n = 1;
	while (n < v)
		n *= 2;
	int p = n / 2;
	return (v - p) < (n - v)? p : n;
}

*/

vec3 voronoi( in vec2 x, in float u_time) {
    vec2 n = floor(x);
    vec2 f = fract(x);

    // first pass: regular voronoi
    vec2 mg, mr;
    float md = 8.0;
    for (int j= -1; j <= 1; j++) {
        for (int i= -1; i <= 1; i++) {
            vec2 g = vec2(float(i),float(j));
            vec2 o = random2( n + g );
            o = 0.5 + 0.5*sin( u_time + 6.2831*o );
            vec2 r = g + o - f;
            float d = dot(r,r);

            if( d<md ) {
                md = d;
                mr = r;
                mg = g;
            }
        }
    }

    // second pass: distance to borders
    md = 8.0;
    for (int j= -2; j <= 2; j++) {
        for (int i= -2; i <= 2; i++) {
            vec2 g = mg + vec2(float(i),float(j));
            vec2 o = random2( n + g );
            o = 0.5 + 0.5*sin( u_time + 6.2831*o );

            vec2 r = g + o - f;

            if ( dot(mr-r,mr-r)>0.00001 ) {
                md = min(md, dot( 0.5*(mr+r), normalize(r-mr) ));
            }
        }
    }
    return vec3(md, mr);
}

vec3 voronoi2( in vec2 x, in float u_time, in float rnd ) {
    vec2 n = floor(x);
    vec2 f = fract(x);

    // first pass: regular voronoi
    vec2 mg, mr;
    float md = 8.0;
    for (int j=-1; j<=1; j++ ) {
        for (int i=-1; i<=1; i++ ) {
            vec2 g = vec2(float(i),float(j));
            vec2 o = random2( n + g )*rnd;
            o = 0.5 + 0.5*sin( u_time + 6.2831*o );
            vec2 r = g + o - f;
            float d = dot(r,r);

            if( d<md ) {
                md = d;
                mr = r;
                mg = g;
            }
        }
    }

    // second pass: distance to borders
    md = 8.0;
    for (int j=-2; j<=2; j++ ) {
        for (int i=-2; i<=2; i++ ) {
            vec2 g = mg + vec2(float(i),float(j));
            vec2 o = random2(n + g)*rnd;
            o = 0.5 + 0.5*sin( u_time + 6.2831*o );

            vec2 r = g + o - f;

            if( dot(mr-r,mr-r)>0.00001 ){
            	md = min( md, dot( 0.5*(mr+r), normalize(r-mr) ) );
			}
        }
    }
    return vec3( md, mr );
}

vec4 permute4(vec4 x) {
  return mod((34.0 * x + 1.0) * x, 289.0);
}

vec2 cellular_2x2(vec2 P) {
	const float K = 0.142857142857; // 1/7
	const float K2 = 0.0714285714285; // K/2
	const float jitter = 0.8; // jitter 1.0 makes F1 wrong more often
	vec2 Pi = mod(floor(P), 289.0);
 	vec2 Pf = fract(P);
	vec4 Pfx = Pf.x + vec4(-0.5, -1.5, -0.5, -1.5);
	vec4 Pfy = Pf.y + vec4(-0.5, -0.5, -1.5, -1.5);
	vec4 p = permute4(Pi.x + vec4(0.0, 1.0, 0.0, 1.0));
	p = permute4(p + Pi.y + vec4(0.0, 0.0, 1.0, 1.0));
	vec4 ox = mod(p, 7.0)*K+K2;
	vec4 oy = mod(floor(p*K),7.0)*K+K2;
	vec4 dx = Pfx + jitter*ox;
	vec4 dy = Pfy + jitter*oy;
	vec4 d = dx * dx + dy * dy; // d11, d12, d21 and d22, squared
	// Sort out the two smallest distances
#if 0
	// Cheat and pick only F1
	d.xy = min(d.xy, d.zw);
	d.x = min(d.x, d.y);
	return d.xx; // F1 duplicated, F2 not computed
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
	return mod289(((x * 34.0) + 1.0) * x);
}

vec4 permute(vec4 x) {
	return mod289(((x * 34.0) + 1.0) * x);
}

vec4 taylorInvSqrt(vec4 r) {
	return 1.79284291400159 - 0.85373472095314 * r;
}

vec2 fade(vec2 t) {
	return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}


float cnoise(vec2 P) {
	vec4 Pi = floor(P.xyxy) + vec4(0.0, 0.0, 1.0, 1.0);
	vec4 Pf = fract(P.xyxy) - vec4(0.0, 0.0, 1.0, 1.0);
	Pi = mod289(Pi); // To avoid truncation effects in permutation
	vec4 ix = Pi.xzxz;
	vec4 iy = Pi.yyww;
	vec4 fx = Pf.xzxz;
	vec4 fy = Pf.yyww;

	vec4 i = permute(permute(ix) + iy);

	vec4 gx = fract(i * (1.0 / 41.0)) * 2.0 - 1.0;
	vec4 gy = abs(gx) - 0.5;
	vec4 tx = floor(gx + 0.5);
	gx = gx - tx;

	vec2 g00 = vec2(gx.x, gy.x);
	vec2 g10 = vec2(gx.y, gy.y);
	vec2 g01 = vec2(gx.z, gy.z);
	vec2 g11 = vec2(gx.w, gy.w);

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

float pnoise(vec2 P, vec2 rep) {
	vec4 Pi = floor(P.xyxy) + vec4(0.0, 0.0, 1.0, 1.0);
	vec4 Pf = fract(P.xyxy) - vec4(0.0, 0.0, 1.0, 1.0);
	Pi = mod(Pi, rep.xyxy); // To create noise with explicit period
	Pi = mod289(Pi);        // To avoid truncation effects in permutation
	vec4 ix = Pi.xzxz;
	vec4 iy = Pi.yyww;
	vec4 fx = Pf.xzxz;
	vec4 fy = Pf.yyww;

	vec4 i = permute(permute(ix) + iy);

	vec4 gx = fract(i * (1.0 / 41.0)) * 2.0 - 1.0;
	vec4 gy = abs(gx) - 0.5;
	vec4 tx = floor(gx + 0.5);
	gx = gx - tx;

	vec2 g00 = vec2(gx.x, gy.x);
	vec2 g10 = vec2(gx.y, gy.y);
	vec2 g01 = vec2(gx.z, gy.z);
	vec2 g11 = vec2(gx.w, gy.w);

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

float snoise(vec2 v) {
	const vec4 C = vec4(0.211324865405187,  // (3.0-sqrt(3.0))/6.0
						0.366025403784439,  // 0.5*(sqrt(3.0)-1.0)
						-0.577350269189626,  // -1.0 + 2.0 * C.x
						0.024390243902439); // 1.0 / 41.0
  // First corner
	vec2 i = floor(v + dot(v, C.yy));
	vec2 x0 = v - i + dot(i, C.xx);

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
	vec3 p = permute(permute(i.y + vec3(0.0, i1.y, 1.0))
					 + i.x + vec3(0.0, i1.x, 1.0));

	vec3 m = max(0.5 - vec3(dot(x0, x0), dot(x12.xy, x12.xy), dot(x12.zw, x12.zw)), 0.0);
	m = m * m;
	m = m * m;

	// Gradients: 41 points uniformly over a line, mapped onto a diamond.
	// The ring size 17*17 = 289 is close to a multiple of 41 (41*7 = 287)

	vec3 x = 2.0 * fract(p * C.www) - 1.0;
	vec3 h = abs(x) - 0.5;
	vec3 ox = floor(x + 0.5);
	vec3 a0 = x - ox;

	// Normalise gradients implicitly by scaling m
	// Approximation of: m *= inversesqrt( a0*a0 + h*h );
	m *= 1.79284291400159 - 0.85373472095314 * (a0 * a0 + h * h);

	// Compute final noise value at P
	vec3 g;
	g.x = a0.x * x0.x + h.x * x0.y;
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
	vec4 ox = mod7(p) * K + K2;
	vec4 oy = mod7(floor(p * K)) * K + K2;
	vec4 dx = Pfx + jitter * ox;
	vec4 dy = Pfy + jitter * oy;
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
	vec3 ox = fract(p * K) - Ko;
	vec3 oy = mod7(floor(p * K)) * K - Ko;
	vec3 dx = Pf.x + 0.5 + jitter * ox;
	vec3 dy = Pf.y - of + jitter * oy;
	vec3 d1 = dx * dx + dy * dy; // d11, d12 and d13, squared
	p = permute(px.y + Pi.y + oi); // p21, p22, p23
	ox = fract(p * K) - Ko;
	oy = mod7(floor(p * K)) * K - Ko;
	dx = Pf.x - 0.5 + jitter * ox;
	dy = Pf.y - of + jitter * oy;
	vec3 d2 = dx * dx + dy * dy; // d21, d22 and d23, squared
	p = permute(px.z + Pi.y + oi); // p31, p32, p33
	ox = fract(p * K) - Ko;
	oy = mod7(floor(p * K)) * K - Ko;
	dx = Pf.x - 1.5 + jitter * ox;
	dy = Pf.y - of + jitter * oy;
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


vec2 closestToLine(vec2 point, vec2 lineStart, vec2 lineEnd) {
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


float DistanceToInfiniteLine(vec2 base, vec2 rclDirect, vec2 point) {
	vec2 dir = rclDirect - base;
	return abs((cross(dir, base - point))) / length(dir);
}

float pDistance(vec2 l1, vec2 l2, vec2 point) {
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

float angle_to(vec2 v, vec2 p_vec2) {
	return atan(cross(v, p_vec2), dot(v, p_vec2));
}

float angle_to_point(vec2 v, vec2 p_vec2) {
	return atan(v.y - p_vec2.y, v.x - p_vec2.x);
}

float lineDistance(vec2 a, vec2 b, vec2 p) {
	vec2 pa = p - a;
	vec2 ba = b - a;
	float t = clamp(dot(pa, ba) / dot(ba, ba), 0.0, 1.0);
	return length(pa - ba * t);
}




vec2 esteiraWrap(vec2 pos, float radius, vec2 size){
	
	
	return pos;
}




