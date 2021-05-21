//=======================================================================================
vec4 CubicHermite (vec4 A, vec4 B, vec4 C, vec4 D, float t)
{
	float t2 = t*t;
    float t3 = t*t*t;
    vec4 a = -A/2.0 + (3.0*B)/2.0 - (3.0*C)/2.0 + D/2.0;
    vec4 b = A - (5.0*B)/2.0 + 2.0*C - D / 2.0;
    vec4 c = -A/2.0 + C/2.0;
   	vec4 d = B;
    
    return a*t3 + b*t2 + c*t + d;
}

//============================================================
vec4 SampleNearest (in vec2 adjustedFragCoord)
{
	vec2 uv = adjustedFragCoord / iResolution.xy;
    return texture(iChannel0, uv);
}

//============================================================
vec4 SampleBilinear (in vec2 adjustedFragCoord)
{
    adjustedFragCoord-= 0.5;
    vec2 fragFract = fract(adjustedFragCoord);
    
    // get the four data points
    vec2 uvMin = adjustedFragCoord / iResolution.xy;
    vec2 uvMax = (adjustedFragCoord + vec2(1.0)) / iResolution.xy;
    vec4 data00 = texture(iChannel0, uvMin);
    vec4 data10 = texture(iChannel0, vec2(uvMax.x, uvMin.y));
    vec4 data01 = texture(iChannel0, vec2(uvMin.x, uvMax.y));
    vec4 data11 = texture(iChannel0, uvMax);
    
    // bilinear interpolate
    vec4 datax0 = mix(data00, data10, fragFract.x);
    vec4 datax1 = mix(data01, data11, fragFract.x);
    return mix(datax0, datax1, fragFract.y);
}

//============================================================
// More info about this technique here:
// http://iquilezles.org/www/articles/texture/texture.htm
vec4 SampleBilinearSmoothstep (in vec2 adjustedFragCoord)
{
    adjustedFragCoord-= 0.5;
    vec2 fragFract = fract(adjustedFragCoord);
    fragFract = smoothstep(0.0, 1.0, fragFract);
    
    // get the four data points
    vec2 uvMin = adjustedFragCoord / iResolution.xy;
    vec2 uvMax = (adjustedFragCoord + vec2(1.0)) / iResolution.xy;
    vec4 data00 = texture(iChannel0, uvMin);
    vec4 data10 = texture(iChannel0, vec2(uvMax.x, uvMin.y));
    vec4 data01 = texture(iChannel0, vec2(uvMin.x, uvMax.y));
    vec4 data11 = texture(iChannel0, uvMax);
    
    // bilinear interpolate
    vec4 datax0 = mix(data00, data10, fragFract.x);
    vec4 datax1 = mix(data01, data11, fragFract.x);
    return mix(datax0, datax1, fragFract.y);    
}

//============================================================
vec4 SampleBicubic (in vec2 adjustedFragCoord)
{
    adjustedFragCoord-= 0.5;    
    vec2 fragFract = fract(adjustedFragCoord);
    
    // get the 16 data points
    vec4 dataNN = texture(iChannel0, (adjustedFragCoord + vec2(-1.0, -1.0)) / iResolution.xy);
    vec4 data0N = texture(iChannel0, (adjustedFragCoord + vec2( 0.0, -1.0)) / iResolution.xy);
    vec4 data1N = texture(iChannel0, (adjustedFragCoord + vec2( 1.0, -1.0)) / iResolution.xy);
    vec4 data2N = texture(iChannel0, (adjustedFragCoord + vec2( 2.0, -1.0)) / iResolution.xy);
    
    vec4 dataN0 = texture(iChannel0, (adjustedFragCoord + vec2(-1.0,  0.0)) / iResolution.xy);
    vec4 data00 = texture(iChannel0, (adjustedFragCoord + vec2( 0.0,  0.0)) / iResolution.xy);
    vec4 data10 = texture(iChannel0, (adjustedFragCoord + vec2( 1.0,  0.0)) / iResolution.xy);
    vec4 data20 = texture(iChannel0, (adjustedFragCoord + vec2( 2.0,  0.0)) / iResolution.xy);    
    
    vec4 dataN1 = texture(iChannel0, (adjustedFragCoord + vec2(-1.0,  1.0)) / iResolution.xy);
    vec4 data01 = texture(iChannel0, (adjustedFragCoord + vec2( 0.0,  1.0)) / iResolution.xy);
    vec4 data11 = texture(iChannel0, (adjustedFragCoord + vec2( 1.0,  1.0)) / iResolution.xy);
    vec4 data21 = texture(iChannel0, (adjustedFragCoord + vec2( 2.0,  1.0)) / iResolution.xy);     
    
    vec4 dataN2 = texture(iChannel0, (adjustedFragCoord + vec2(-1.0,  2.0)) / iResolution.xy);
    vec4 data02 = texture(iChannel0, (adjustedFragCoord + vec2( 0.0,  2.0)) / iResolution.xy);
    vec4 data12 = texture(iChannel0, (adjustedFragCoord + vec2( 1.0,  2.0)) / iResolution.xy);
    vec4 data22 = texture(iChannel0, (adjustedFragCoord + vec2( 2.0,  2.0)) / iResolution.xy);     
    
    // bicubic interpolate
    vec4 dataxN = CubicHermite(dataNN, data0N, data1N, data2N, fragFract.x);
    vec4 datax0 = CubicHermite(dataN0, data00, data10, data20, fragFract.x);
    vec4 datax1 = CubicHermite(dataN1, data01, data11, data21, fragFract.x);
    vec4 datax2 = CubicHermite(dataN2, data02, data12, data22, fragFract.x);
    return CubicHermite(dataxN, datax0, datax1, datax2, fragFract.y);
}








/////////////////////////////////////////////////////////
#define DOWNSCALE 32.0

vec4 interpolate_bilinear(vec2 p, vec4 q[16])
{
    vec4 r1 = (1.0-p.x)*q[5]+p.x*q[9];
    vec4 r2 = (1.0-p.x)*q[6]+p.x*q[10];
    return (1.0-p.y)*r1+p.y*r2;
}

vec4 interpolate_bicubic(vec2 p, vec4 q[16])
{
    vec4 a00 = q[5];
	vec4 a01 = -.5*q[4]+.5*q[6];
	vec4 a02 = q[4]-2.5*q[5]+2.0*q[6]-.5*q[7];
	vec4 a03 = -.5*q[4]+1.5*q[5]-1.5*q[6]+.5*q[7];
	vec4 a10 = -.5*q[1]+.5*q[9];
	vec4 a11 = .25*q[0]-.25*q[2]-.25*q[8]+.25*q[10];
	vec4 a12 = -.5*q[0]+1.25*q[1]-q[2]+.25*q[3]+.5*q[8]-1.25*q[9]+q[10]-.25*q[11];
	vec4 a13 = .25*q[0]-.75*q[1]+.75*q[2]-.25*q[3]-.25*q[8]+.75*q[9]-.75*q[10]
        +.25*q[11];
	vec4 a20 = q[1]-2.5*q[5]+2.0*q[9]-.5*q[13];
	vec4 a21 = -.5*q[0]+0.5*q[2]+1.25*q[4]-1.25*q[6]-q[8]+q[10]+.25*q[12]-.25*q[14];
	vec4 a22 = q[0]-2.5*q[1]+2.0*q[2]-.5*q[3]-2.5*q[4]+6.25*q[5]-5.0*q[6]+1.25*q[7]
        +2.0*q[8]-5.0*q[9]+4.0*q[10]-q[11]-.5*q[12]+1.25*q[13]-q[14]+.25*q[15];
	vec4 a23 = -.5*q[0]+1.5*q[1]-1.5*q[2]+.5*q[3]+1.25*q[4]-3.75*q[5]+3.75*q[6]
        - 1.25*q[7]-q[8]+3.0*q[9]-3.0*q[10]+q[11]+.25*q[12]-.75*q[13]+.75*q[14]-.25*q[15];
	vec4 a30 = -.5*q[1]+1.5*q[5]-1.5*q[9]+.5*q[13];
	vec4 a31 = .25*q[0]-0.25*q[2]-0.75*q[4]+.75*q[6]+.75*q[8]-.75*q[10]-.25*q[12]+.25*q[14];
	vec4 a32 = -.5*q[0]+1.25*q[1]-q[2]+.25*q[3]+1.5*q[4]-3.75*q[5]+3.0*q[6]-.75*q[7]-1.5*q[8]
        + 3.75*q[9]-3.0*q[10]+.75*q[11]+.5*q[12]-1.25*q[13]+q[14]-.25*q[15];
	vec4 a33 = .25*q[0]-0.75*q[1]+0.75*q[2]-.25*q[3]-.75*q[4]+2.25*q[5]-2.25*q[6]+.75*q[7]
        +.75*q[8]-2.25*q[9]+2.25*q[10]-.75*q[11]-.25*q[12]+.75*q[13]-.75*q[14] 
        +.25*q[15];
    float x2 = p.x*p.x;
    float x3 = x2*p.x;
    float y2 = p.y*p.y;
    float y3 = y2*p.y;
   	return (a00+a01*p.y+a02*y2+a03*y3)+
		   (a10+a11*p.y+a12*y2+a13*y3)*p.x+
		   (a20+a21*p.y+a22*y2+a23*y3)*x2+
		   (a30+a31*p.y+a32*y2+a33*y3)*x3;
}

vec2 hash(vec2 v)
{
    return vec2(
        fract(v.x*sin(v.y*v.y)*12345.0),
        fract(v.y*sin(v.x*v.x)*42312.0)
        );
}

#define PI 3.14159265359

vec4 interpolate(vec2 p, vec2 pixel, vec2 base, vec2 uv)
{
    vec2 rand_vec = hash(uv);
    vec2 offset = vec2(
        -rand_vec.x*sin(rand_vec.y*2.0*PI),
        rand_vec.x*cos(rand_vec.y*2.0*PI)
        );
    return texture(iChannel0,base+floor(offset)*pixel);
}

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
	vec2 uv = fragCoord.xy / iResolution.xy;
  	vec2 lowres = iResolution.xy/DOWNSCALE;
  	vec2 pixel = 1.0/lowres;
  	vec2 base_uv = floor(uv*lowres)/lowres;
  	vec2 sub_uv = fract(uv*lowres);
    

    vec4 q[16];
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            q[i*4+j] = texture(iChannel0,base_uv+vec2(pixel.x*float(i-1),pixel.y*float(j-1)));
        }
    }
    
    vec4 bicubic = interpolate_bicubic(sub_uv,q);
    
    vec4 bilinear = interpolate_bilinear(sub_uv,q);
    
    float x;
    if(iMouse.z>0.0){
        x = iMouse.x/iResolution.x;
    }else{
        x = 0.5;
    }
    
    if(uv.x < x)
    {
        fragColor = bicubic;
    }
    else
    {
        fragColor = bilinear;
    }
    
}







///////////////////////////////////////////////
float4 bspline_2d_fp( float2 coord_source : TEXCOORD0,    uniform sampler2D tex_source,  
// source texture    
uniform sampler1D tex_hg,      
// filter offsets and weights      
uniform float2 e_x,            
// texel size in x direction    
uniform float2 e_y,            
// texel size in y direction    
uniform float2 size_source     
// source texture size    
) : COLOR  {    
// calc filter texture coordinates where [0,1] is a single texel    
// (can be done in vertex program instead)
    float2 coord_hg = coord_source * size_source - float2(0.5f, 0.5f);      
// fetch offsets and weights from filter texture
      float3 hg_x = tex1D( tex_hg, coord_hg.x ).xyz;    
float3 hg_y = tex1D( tex_hg, coord_hg.y ).xyz;      
// determine linear sampling coordinates
    float2 coord_source10 = coord_source + hg_x.x * e_x;    
float2 coord_source00 = coord_source - hg_x.y * e_x;      
float2 coord_source11 = coord_source10 + hg_y.x * e_y;    
float2 coord_source01 = coord_source00 + hg_y.x * e_y;    
coord_source10 = coord_source10 - hg_y.y * e_y;    
coord_source00 = coord_source00 - hg_y.y * e_y;      
// fetch four linearly interpolated inputs
float4 tex_source00 = tex2D( tex_source, coord_source00 );    
float4 tex_source10 = tex2D( tex_source, coord_source10 );    
float4 tex_source01 = tex2D( tex_source, coord_source01 );    
float4 tex_source11 = tex2D( tex_source, coord_source11 );      
// weight along y direction      
tex_source00 = lerp( tex_source00, tex_source01, hg_y.z );    
tex_source10 = lerp( tex_source10, tex_source11, hg_y.z );      
// weight along x direction    
tex_source00 = lerp( tex_source00, tex_source10, hg_x.z );      
return tex_src00;  
} 

/////////////
e_x = float2( 1/256.0f, 0.0f );  
e_y = float2( 0.0f, 1/128.0f );    
size_source = float2( 256.0f, 128.0f );








//////////////////////////////////////////////////////////
//-----------------------------------------------------------------------------------------

vec4 BS_A = vec4(   3.0,  -6.0,   0.0,  4.0 ) /  6.0;
vec4 BS_B = vec4(  -1.0,   6.0, -12.0,  8.0 ) /  6.0;
vec4 RE_A = vec4(  21.0, -36.0,   0.0, 16.0 ) / 18.0;
vec4 RE_B = vec4(  -7.0,  36.0, -60.0, 32.0 ) / 18.0;
vec4 CR_A = vec4(   3.0,  -5.0,   0.0,  2.0 ) /  2.0;
vec4 CR_B = vec4(  -1.0,   5.0,  -8.0,  4.0 ) /  2.0;
        
vec4 powers( float x ) { return vec4(x*x*x, x*x, x, 1.0); }

vec4 ca, cb;

vec4 spline( float x, vec4 c0, vec4 c1, vec4 c2, vec4 c3 )
{
    // We could expand the powers and build a matrix instead (twice as many coefficients
    // would need to be stored, but it could be faster.
    return c0 * dot( cb, powers(x + 1.0)) + 
           c1 * dot( ca, powers(x      )) +
           c2 * dot( ca, powers(1.0 - x)) +
           c3 * dot( cb, powers(2.0 - x));
}

#define SAM(a,b)  texture(iChannel0, (i+vec2(float(a),float(b))+0.5)/res, -99.0)

vec4 texture_Bicubic( sampler2D tex, vec2 t )
{
    vec2 res = iChannelResolution[0].xy;
    vec2 p = res*t - 0.5;
    vec2 f = fract(p);
    vec2 i = floor(p);

    return spline( f.y, spline( f.x, SAM(-1,-1), SAM( 0,-1), SAM( 1,-1), SAM( 2,-1)),
                        spline( f.x, SAM(-1, 0), SAM( 0, 0), SAM( 1, 0), SAM( 2, 0)),
                        spline( f.x, SAM(-1, 1), SAM( 0, 1), SAM( 1, 1), SAM( 2, 1)),
                        spline( f.x, SAM(-1, 2), SAM( 0, 2), SAM( 1, 2), SAM( 2, 2)));
}

//-----------------------------------------------------------------------------------------

vec4 lerp( float x, vec4 a, vec4 b ) { return mix(a,b,x); }

vec4 texture_Bilinear( sampler2D tex, vec2 t )
{
    vec2 res = iChannelResolution[0].xy;
    vec2 p = res*t - 0.5;
    vec2 f = fract(p);
    vec2 i = floor(p);

    return lerp( f.y, lerp( f.x, SAM(0,0), SAM(1,0)),
                      lerp( f.x, SAM(0,1), SAM(1,1)) );
}

//-----------------------------------------------------------------------------------------

void mainImage( out vec4 fragColor, in vec2 fragCoord )
{
	vec2 p = fragCoord.xy/iResolution.x;
    vec2 q = fragCoord.xy/iResolution.xy;
    
    vec2 uv = vec2(0.0);

         if( q.x<0.33 ) { ca=BS_A; cb=BS_B; uv = p-vec2(0.00,0.0); }
    else if( q.x<0.66 ) { ca=RE_A; cb=RE_B; uv = p-vec2(0.33,0.0); }
    else                { ca=CR_A; cb=CR_B; uv = p-vec2(0.66,0.0); }

    uv = uv * 0.06 + 0.001*iTime;

  //vec3 cola = texture(          iChannel0, uv ).xyz;
    vec3 cola = texture_Bilinear( iChannel0, uv ).xyz;
    vec3 colb = texture_Bicubic(  iChannel0, uv ).xyz;
    
    vec3 col = mix( cola, colb, smoothstep( -0.1, 0.1, cos(2.0*iTime)) );

    float gre = dot(col,vec3(0.333));
    
    vec3 colc = 0.5 + 50.0*vec3( dFdx(gre), dFdy(gre), 0.0 );
    
    col = mix( col, colc, step(q.y,0.40) );
    
    col *= smoothstep( 0.0, 2.0/iResolution.x, abs(p.x-0.33) );
    col *= smoothstep( 0.0, 2.0/iResolution.x, abs(p.x-0.66) );
    col *= smoothstep( 0.0, 2.0/iResolution.y, abs(q.y-0.40) );
    
	fragColor = vec4( col, 1.0 );
}
