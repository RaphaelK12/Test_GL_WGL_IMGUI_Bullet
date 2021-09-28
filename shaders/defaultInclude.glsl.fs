




// Output
layout (location = 0) out vec4 color;

// definitions
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

	vec3 normalV;	// normal
	vec3 tangentV;	// tangent
	vec3 bitangentV;	// bitangent

	vec3 TangentViewPos;
	vec3 TangentFragPos;

	vec3 lightDir;	// Light
	vec3 viewPos;	// Light
	vec2 uv1;		// first uv
	
	vec2 uv2;		// Second uv possible not used
	vec4 color1;		// vertex color
	vec4 color2;	// vertex color
} fsin;

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


// uniforms
uniform material mt;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;
uniform sampler2D texture4;


// Material properties
uniform vec4 diffuse_albedo = vec4(0.5, 0.2, 0.7, 1);
uniform vec3 specular_albedo = vec3(0.7);
uniform float specular_power = 128.0; // 200

vec3 lightColor = vec3(1.0, 1.0, 1.0);
float lightPower = 18.0; // 40
vec3 light_pos = vec3(5, 0, 0);

// functions

subroutine vec4 textureSampleMode(sampler2D tex, vec2 uv, vec2 dx, vec2 dy);
  
// a special uniform variable to control which option will be used
layout (location = 0) subroutine uniform textureSampleMode textures;

// subroutine vec4 colorRedGreenBlue ();
// layout (location = 0) subroutine uniform colorRedGreenBlue PrimaryColor;
// layout (index = 0) subroutine (colorRedGreenBlue ) vec4 ColorBlack(){	return vec4(0.0, 0.0, 0.0, 1.0);} 

// location = 0
// layout (index = 10) subroutine (textureSampleMode) vec4 ColorBlack(){	return vec4(0.0, 0.0, 0.0, 1.0);} 
// layout (index = 11) subroutine (textureSampleMode) vec4 ColorWhite(){	return vec4(1.0, 1.0, 1.0, 1.0);} 
// layout (index = 12) subroutine (textureSampleMode) vec4 ColorRed()	{	return vec4(1.0, 0.0, 0.0, 1.0);}  
// layout (index = 13) subroutine (textureSampleMode) vec4 ColorGreen(){	return vec4(0.0, 1.0, 0.0, 1.0);}
// layout (index = 14) subroutine (textureSampleMode) vec4 ColorBlue()	{	return vec4(0.0, 0.0, 1.0, 1.0);}
	


// sample
layout (index = 0) subroutine (textureSampleMode) vec4 sampleLevel0(sampler2D tex, vec2 uv, vec2 dx, vec2 dy) {
	return textureGrad(tex, uv, dx, dy);
}

// smoothstep
layout (index = 1) subroutine (textureSampleMode) vec4 texcubic(sampler2D tex, vec2 uv, vec2 dx, vec2 dy) {
	vec2 textureResolution = vec2(textureSize(tex, 0));
	uv = uv * textureResolution + 0.5;
	vec2 iuv = floor(uv);
	vec2 fuv = fract(uv);
	uv = iuv + smoothstep(0.0, 1.0, fuv); // fuv*fuv*fuv*(fuv*(fuv*6.0-15.0)+10.0);;
	uv = (uv - 0.5) / textureResolution;
	return textureGrad(tex, uv, dx, dy);
}

// 4 samples
layout (index = 2) subroutine (textureSampleMode) vec4 texture_bicubic(sampler2D tex, vec2 uv, vec2 dx, vec2 dy) {
	vec4 texelSize = vec4(1 / vec2(textureSize(tex, 0)), vec2(textureSize(tex, 0)));
	uv = uv * texelSize.zw + 0.5;
	vec2 iuv = floor(uv);
	vec2 fuv = fract(uv);

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

	return g0(fuv.y) * (g0x * textureGrad(tex, p0, dx, dy) +
						g1x * textureGrad(tex, p1, dx, dy)) +
		g1(fuv.y) * (g0x * textureGrad(tex, p2, dx, dy) +
					 g1x * textureGrad(tex, p3, dx, dy));
}

// 16 samples
layout (index = 3) subroutine (textureSampleMode) vec4 BicubicLagrangeTextureSample(sampler2D tex, vec2 uv, vec2 dx, vec2 dy) {
	vec2 c_textureSize = vec2(textureSize(tex, 0));

	vec2 c_onePixel = vec2(1.0) / c_textureSize;
	vec2 c_twoPixels = vec2(2.0) / c_textureSize;
	vec2 pixel = uv * c_textureSize + 0.5;

	vec2 frac = fract(pixel);
	pixel = floor(pixel) / c_textureSize - vec2(c_onePixel / 2.0);

	vec4 C00 = textureGrad(tex, pixel + vec2(-c_onePixel.x, -c_onePixel.y), dx, dy);
	vec4 C10 = textureGrad(tex, pixel + vec2(0.0, -c_onePixel.y), dx, dy);
	vec4 C20 = textureGrad(tex, pixel + vec2(c_onePixel.x, -c_onePixel.y), dx, dy);
	vec4 C30 = textureGrad(tex, pixel + vec2(c_twoPixels.x, -c_onePixel.y), dx, dy);

	vec4 C01 = textureGrad(tex, pixel + vec2(-c_onePixel.x, 0.0), dx, dy);
	vec4 C11 = textureGrad(tex, pixel + vec2(0.0, 0.0), dx, dy);
	vec4 C21 = textureGrad(tex, pixel + vec2(c_onePixel.x, 0.0), dx, dy);
	vec4 C31 = textureGrad(tex, pixel + vec2(c_twoPixels.x, 0.0), dx, dy);

	vec4 C02 = textureGrad(tex, pixel + vec2(-c_onePixel.x, c_onePixel.y), dx, dy);
	vec4 C12 = textureGrad(tex, pixel + vec2(0.0, c_onePixel.y), dx, dy);
	vec4 C22 = textureGrad(tex, pixel + vec2(c_onePixel.x, c_onePixel.y), dx, dy);
	vec4 C32 = textureGrad(tex, pixel + vec2(c_twoPixels.x, c_onePixel.y), dx, dy);

	vec4 C03 = textureGrad(tex, pixel + vec2(-c_onePixel.x, c_twoPixels.y), dx, dy);
	vec4 C13 = textureGrad(tex, pixel + vec2(0.0, c_twoPixels.y), dx, dy);
	vec4 C23 = textureGrad(tex, pixel + vec2(c_onePixel.x, c_twoPixels.y), dx, dy);
	vec4 C33 = textureGrad(tex, pixel + vec2(c_twoPixels.x, c_twoPixels.y), dx, dy);

	vec4 CP0X = CubicLagrange(C00, C10, C20, C30, frac.x);
	vec4 CP1X = CubicLagrange(C01, C11, C21, C31, frac.x);
	vec4 CP2X = CubicLagrange(C02, C12, C22, C32, frac.x);
	vec4 CP3X = CubicLagrange(C03, C13, C23, C33, frac.x);

	return CubicLagrange(CP0X, CP1X, CP2X, CP3X, frac.y);
}

// 16 samples
layout (index = 4) subroutine (textureSampleMode) vec4 BicubicHermiteTextureSample(sampler2D tex, vec2 uv, vec2 dx, vec2 dy) {
	const float c_x0 = -1.0;
	const float c_x1 = 0.0;
	const float c_x2 = 1.0;
	const float c_x3 = 2.0;

	vec2 c_textureSize = vec2(textureSize(tex, 0));

	vec2 c_onePixel = vec2(1.0) / c_textureSize;
	vec2 c_twoPixels = vec2(2.0) / c_textureSize;

	vec2 pixel = uv * c_textureSize + 0.5;

	vec2 frac = fract(pixel);
	pixel = floor(pixel) / c_textureSize - vec2(c_onePixel / 2.0);

	vec4 C00 = textureGrad(tex, pixel + vec2(-c_onePixel.x, -c_onePixel.y), dx, dy);
	vec4 C10 = textureGrad(tex, pixel + vec2(0.0, -c_onePixel.y), dx, dy);
	vec4 C20 = textureGrad(tex, pixel + vec2(c_onePixel.x, -c_onePixel.y), dx, dy);
	vec4 C30 = textureGrad(tex, pixel + vec2(c_twoPixels.x, -c_onePixel.y), dx, dy);

	vec4 C01 = textureGrad(tex, pixel + vec2(-c_onePixel.x, 0.0), dx, dy);
	vec4 C11 = textureGrad(tex, pixel + vec2(0.0, 0.0), dx, dy);
	vec4 C21 = textureGrad(tex, pixel + vec2(c_onePixel.x, 0.0), dx, dy);
	vec4 C31 = textureGrad(tex, pixel + vec2(c_twoPixels.x, 0.0), dx, dy);

	vec4 C02 = textureGrad(tex, pixel + vec2(-c_onePixel.x, c_onePixel.y), dx, dy);
	vec4 C12 = textureGrad(tex, pixel + vec2(0.0, c_onePixel.y), dx, dy);
	vec4 C22 = textureGrad(tex, pixel + vec2(c_onePixel.x, c_onePixel.y), dx, dy);
	vec4 C32 = textureGrad(tex, pixel + vec2(c_twoPixels.x, c_onePixel.y), dx, dy);

	vec4 C03 = textureGrad(tex, pixel + vec2(-c_onePixel.x, c_twoPixels.y), dx, dy);
	vec4 C13 = textureGrad(tex, pixel + vec2(0.0, c_twoPixels.y), dx, dy);
	vec4 C23 = textureGrad(tex, pixel + vec2(c_onePixel.x, c_twoPixels.y), dx, dy);
	vec4 C33 = textureGrad(tex, pixel + vec2(c_twoPixels.x, c_twoPixels.y), dx, dy);

	vec4 CP0X = CubicHermite(C00, C10, C20, C30, frac.x);
	vec4 CP1X = CubicHermite(C01, C11, C21, C31, frac.x);
	vec4 CP2X = CubicHermite(C02, C12, C22, C32, frac.x);
	vec4 CP3X = CubicHermite(C03, C13, C23, C33, frac.x);

	return CubicHermite(CP0X, CP1X, CP2X, CP3X, frac.y);
}

// note: entirely stolen from https://gist.github.com/TheRealMJP/c83b8c0f46b63f3a88a5986f4fa982b1
// Samples a texture with Catmull-Rom filtering, using 9 texture fetches instead of 16.
// See http://vec3.ca/bicubic-filtering-in-fewer-taps/ for more details
// 9 samples
layout (index = 5) subroutine (textureSampleMode) vec4 SampleTextureCatmullRom(sampler2D tex, vec2 uv, vec2 dx, vec2 dy) {
	vec2 textureResolution = vec2(textureSize(tex, 0));

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
	vec2 w0 = f * (-0.5 + f * (1.0 - 0.5 * f));
	vec2 w1 = 1.0 + f * f * (-2.5 + 1.5 * f);
	vec2 w2 = f * (0.5 + f * (2.0 - 1.5 * f));
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
	result += textureGrad(tex, vec2(texPos0.x, texPos0.y), dx, dy) * w0.x * w0.y;
	result += textureGrad(tex, vec2(texPos12.x, texPos0.y), dx, dy) * w12.x * w0.y;
	result += textureGrad(tex, vec2(texPos3.x, texPos0.y), dx, dy) * w3.x * w0.y;

	result += textureGrad(tex, vec2(texPos0.x, texPos12.y), dx, dy) * w0.x * w12.y;
	result += textureGrad(tex, vec2(texPos12.x, texPos12.y), dx, dy) * w12.x * w12.y;
	result += textureGrad(tex, vec2(texPos3.x, texPos12.y), dx, dy) * w3.x * w12.y;

	result += textureGrad(tex, vec2(texPos0.x, texPos3.y), dx, dy) * w0.x * w3.y;
	result += textureGrad(tex, vec2(texPos12.x, texPos3.y), dx, dy) * w12.x * w3.y;
	result += textureGrad(tex, vec2(texPos3.x, texPos3.y), dx, dy) * w3.x * w3.y;

	return result;
}



vec3 getNormalFromMap(vec3 n, vec3 tangent, sampler2D tex, vec2 coord, vec3 WorldPos, vec2 dx, vec2 dy) {
	// texcubic textureGrad BicubicLagrangeTextureSample BicubicHermiteTextureSample
	// texture_bicubic SampleTextureCatmullRom
	vec3 tangentNormal = unpackNormal(textures(tex, coord, dx, dy).xyz, 0.55);
	vec3 N = normalize(n);
	vec3 T = normalize(tangent);
	vec3 B = -normalize(cross(N, T));
	mat3 TBN = mat3(T, B, N);
	return normalize(TBN * tangentNormal);
}

// Ray intersect depth map using relaxed cone stepping.
// Depth value stored in alpha channel (black at object surface)
// and relaxed cone ratio stored in blue channel.
void ray_intersect_relaxedcone(sampler2D relief_map, inout vec3 ray_pos, inout vec3 ray_dir) {
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

vec2 ParallaxMapping(vec2 texCoords, vec3 viewDir) {
	float heightScale = 0.04;
	const float minLayers = 5;
	const float maxLayers = 100;
	float numLayers = mix(maxLayers, minLayers, abs(dot(vec3(0.0, 0.0, 1.0), viewDir)));
	float layerDepth = 1.0 / numLayers;
	float currentLayerDepth = 1.0;
	vec2 P = viewDir.xy / viewDir.z * heightScale;
	vec2 deltaTexCoords = P / numLayers;
	vec2  currentTexCoords = texCoords;
	float currentDepthMapValue = texture(texture2, currentTexCoords).r;
	while (currentLayerDepth > currentDepthMapValue) {
		currentTexCoords -= deltaTexCoords;
		currentDepthMapValue = texture(texture2, currentTexCoords).r;
		currentLayerDepth -= layerDepth;
	}
	vec2 prevTexCoords = currentTexCoords + deltaTexCoords;
	float afterDepth = currentDepthMapValue - currentLayerDepth;
	float beforeDepth = texture(texture2, prevTexCoords).r - currentLayerDepth + layerDepth;
	float weight = afterDepth * (afterDepth - beforeDepth);
	vec2 finalTexCoords = prevTexCoords * (weight)+currentTexCoords * (1.0 - weight);
	return finalTexCoords;
}

vec2 cone_step(vec2 uv, vec3 ds, sampler2D stepmap) {
	float conesteps = 25;
	vec3 dp = vec3(uv, 0);
	float iz = max(abs(ds.x), abs(ds.y));
	const float w = 0.01;
	vec4 t;
	for (int i = 0; i < conesteps; i++) {
		t = texture2D(stepmap, dp.xy);
		dp += ds * w * (t.r - dp.z) / (iz / (t.g * t.g) + 1.0);
	}
	return dp.xy;
}

float relief(vec2 initialPos, vec2 offsetDir, sampler2D stepmap) {
	int linearSteps = 10;
	int binarySteps = 5;
	float depth_step = 1.0 / linearSteps;
	float size = depth_step;
	float depth = 0.0;
	float best_depth = 1.0;
	vec2 dx = dFdx(initialPos) * 5;
	vec2 dy = dFdy(initialPos) * 5;
	for (int i = 0; i < linearSteps - 1; i++) {
		depth += size;
		float height = 1 - textureGrad(stepmap, initialPos + offsetDir * depth, dx, dy).x;
		if (best_depth >= 0.996)
			if (depth >= height)
				best_depth = depth;
	}
	depth = best_depth;
	for (int i = 0; i < binarySteps; i++) {
		size *= 0.5;
		float height = 1 - textureGrad(stepmap, initialPos + offsetDir * depth, dx, dy).x;
		if (depth >= height) {
			best_depth = depth;
			depth -= 2 * size;
		}
		depth += size;
	}
	return best_depth;
}


shading lambertian(in vec3 n, in vec3 v, in light l, in vec2 uv, vec2 dx, vec2 dy) {
	shading s;
	vec3 N = getNormalFromMap(n, fsin.tangent, texture3, fsin.uv1, fsin.position_M.xyz, dx, dy);
	vec3 L = normalize(l.direction);
	s.diffuse = l.color * saturate(dot(N, L));
	s.specular = vec3(0);
	s.rim = 0;
	return s;
}
shading blinPhong1(in vec3 n, in vec3 v, in light l, in vec2 uv, vec2 dx, vec2 dy) {
	shading s;
	vec3 N = getNormalFromMap(n, fsin.tangent, texture3, fsin.uv1, fsin.position_M.xyz, dx, dy);
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
shading blinPhong2(in vec3 n, in vec3 v, in light l, in vec2 uv, vec2 dx, vec2 dy) {
	shading s;
	vec3 N = getNormalFromMap(n, fsin.tangent, texture3, uv, fsin.position_M.xyz, dx, dy);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	float distance = length(l.direction);
	s.distance = distance * distance;
	float diff = dot(L, N);
	// s.diffuse = l.color * saturate(diff*0.5+0.5);
	s.diffuse = l.color * saturate(diff);

	vec3 rf = normalize(reflect(-L, N));
	s.specular = l.color * pow(vec3(saturate(dot(rf, V))), l.specPower)
		* smoothstep(0, 1, saturate(diff + 0.01) * 4)
		;
	// s.specular=N;
	s.rim = 0;
	return s;
}
shading blinPhong3(in vec3 n, in vec3 v, in light l, in vec2 uv, vec2 dx, vec2 dy) {
	shading s;
	vec3 N = getNormalFromMap(n, fsin.tangent, texture3, uv, fsin.position_M.xyz, dx, dy);
	vec3 L = normalize(l.direction);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	float distance = length(l.direction);
	s.distance = distance * distance;
	float diff = dot(L, N);
	s.diffuse = l.color * saturate(diff);

	float specAngle = saturate(dot(reflect(-L, N), V));
	s.specular = l.color * pow(vec3(specAngle), l.specPower)
		* smoothstep(0, 1, saturate(diff + 0.01) * 4)
		;
	s.rim = 0;
	return s;
}

vec4 blinPhong_1(in vec3 n, in vec3 l, in vec3 v,
				 in float spec_power, in vec3 spec_albedo,
				 in vec4 diff_albedo, in vec4 color) {
	vec3 N = normalize(n);	// Normalize the incoming N, L and V vectors
	vec3 L = normalize(l);
	vec3 V = normalize(v);
	vec3 H = normalize(L + V); // Half Dir
	vec4 diffuse = max(dot(N, L), 0.0) * diff_albedo; // Compute the diffuse component for each fragment
	vec3 specular = pow(max(dot(N, H), 0.0), spec_power) * spec_albedo; // Compute the specular component for each fragment
	return diffuse + vec4(specular, 0);	// Write final color to the framebuffer
}
vec4 blinPhong_2(in vec3 n, in vec3 l, in vec3 v,
				 in float spec_power, in vec3 spec_albedo,
				 in vec4 diff_albedo, in vec4 color) {
	vec3 normal = normalize(n);
	vec3 lightDir = l;
	lightDir = normalize(lightDir);
	vec3 viewDir = normalize(v);
	vec3 halfDir = normalize(lightDir + viewDir);
	float distance = length(lightDir);
	distance = distance * distance;
	float lambert = max(dot(lightDir, normal), 0.0);
	float specular = 0.0;
	// if (lambert > 0.0) {
	   // this is blinn phong
	specular = pow(max(dot(halfDir, normal), 0.0), specular_power);
	// }
	vec3 colorLinear = diff_albedo.rgb * lambert * lightColor * lightPower / distance +
						spec_albedo * specular * lightColor * lightPower / distance;
	return vec4(colorLinear.rgb, diff_albedo.a);
}
vec4 blinPhong_3(in vec3 n, in vec3 l, in vec3 v, // this is phong, good specular in angular
				 in float spec_power, in vec3 spec_albedo,
				 in vec4 diff_albedo, in vec4 color) {
	vec3 normal = normalize(n);
	vec3 lightDir = l;
	float distance = length(lightDir);
	distance = distance * distance;
	lightDir = normalize(lightDir);
	float lambert = max(dot(lightDir, normal), 0.0);
	float specular = 0.0;
	// if (lambert > 0.0) {
	vec3 viewDir = normalize(v);
	vec3 reflectDir = reflect(-lightDir, normal);
	float specAngle = max(dot(reflectDir, viewDir), 0.0);
	specular = pow(specAngle, specular_power / 4.0);
	// }
	vec3 colorLinear = lambert * diff_albedo.rgb * lightColor * lightPower / distance +
		spec_albedo * specular * lightColor * lightPower / distance;
	return vec4(colorLinear.rgb, diff_albedo.a);
}









