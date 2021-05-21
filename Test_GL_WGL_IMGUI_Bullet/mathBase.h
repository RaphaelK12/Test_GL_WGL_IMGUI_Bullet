#pragma once
#include "numdef.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>

#ifndef PI
#  define PI 3.14159265358979323846 /* pi */
#endif

#define F_UNIT_EPSILON 0.0002f
#define F_CMP_EPSILON  0.00002f

#define D_UNIT_EPSILON 0.00001
#define D_CMP_EPSILON  0.000001

#define F_EPSILON      1.192092896e-07F        // smallest such that 1.0+FLT_EPSILON != 1.0
#define D_EPSILON      2.2204460492503131e-016 // smallest such that 1.0+DBL_EPSILON != 1.0

#define D_CMP_EPSILON2 (CMP_EPSILON * CMP_EPSILON)
#define F_CMP_EPSILON2 (CMP_EPSILON * CMP_EPSILON)

#define F_CMP_NORMALIZE_TOLERANCE 0.000001f
#define F_CMP_POINT_IN_PLANE_EPSILON 0.00001f

#define D_CMP_NORMALIZE_TOLERANCE 0.000001
#define D_CMP_POINT_IN_PLANE_EPSILON 0.00001

#define F_PI      3.14159265358979323846f /* pi */
#define F_2PI     6.2831853071795864769252867666f /* 2*pi */
#define F_4PI     12.566370614359172953850573533118f /* 2*pi */
#define F_1_PI    0.318309886183790671538f /* 1/pi */
#define F_1_2PI   0.159154943091895335768f /* 1/(2*pi) */
#define F_PI_2    1.57079632679489661923f /* pi/2 */
#define F_PI_4    0.78539816339744830962f /* pi/4 */
#define F_SQRT2   1.4142135623730950488016887242f /* sqrt(2) */
#define F_SQRT3   1.73205080756887729352f /* sqrt(3) */
#define F_SQRT1_2 0.7071067811865475244008443621048490f /* 1/sqrt(2) */
#define F_SQRT1_3 0.57735026918962576450f /* 1/sqrt(3) */
#define F_E       2.7182818284590452353602874714f /* e euler */
#define F_LOG2E   1.4426950408889634074f /* log_2 e */
#define F_LOG10E  0.43429448190325182765f /* log_10 e */
#define F_LN2     0.6931471805599453094172321215f /* log_e 2 */
#define F_LN10    2.30258509299404568402f /* log_e 10 */
#define F_PHI 	  1.61803398874989484820459f /* Golden Ratio  */

#define D_PI      3.1415926535897932384626433832795 /* pi */
#define D_2PI     6.2831853071795864769252867666 /* 2*pi */
#define D_4PI     12.566370614359172953850573533118 /* 4*pi */
#define D_1_PI    0.318309886183790671538 /* 1/pi */
#define D_1_2PI   0.159154943091895335768 /* 1/(2*pi) */
#define D_PI_2    1.57079632679489661923 /* pi/2 */
#define D_PI_4    0.78539816339744830962 /* pi/4 */
#define D_SQRT2   1.4142135623730950488016887242 /* sqrt(2) */
#define D_SQRT3   1.73205080756887729352 /* sqrt(3) */
#define D_SQRT1_2 0.7071067811865475244008443621048490 /* 1/sqrt(2) */
#define D_SQRT1_3 0.57735026918962576450 /* 1/sqrt(3) */
#define D_E       2.7182818284590452353602874714 /* e euler*/
#define D_LOG2E   1.4426950408889634074 /* log_2 e */
#define D_LOG10E  0.43429448190325182765 /* log_10 e */
#define D_LN2     0.6931471805599453094172321215 /* log_e 2 */
#define D_LN10    2.30258509299404568402 /* log_e 10 */
#define D_PHI 	  1.61803398874989484820459 /* Golden Ratio  */

#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif

template <class T, class R>
T min(T a, R b) {
	return(a < (T)b ? a : b);
};
template <class T, class R>
T max(T a, R b) {
	return(a > (T)b ? a : b);
};

inline float Turn2Deg(float val) {// 0 ... 360
	return  val * 360;
}
inline float Turn2Grad(float val) {// 0 ... 400
	return  val * 400;
}
inline float Turn2Rad(float val) {// 0 ... 2*F_PI
	return val * F_2PI;
}
inline float Deg2Turn(float val) {// 0 ... 1
	return  val / 360.f;
}
inline float Deg2Grad(float val) {// 0 ... 400
	return  (val / 360.f) * 400;
}
inline float Deg2Rad(float val) {// 0 ... 2*F_PI
	return  (val / 180.f) * F_PI;
}
inline float Grad2Turn(float val) {// 0 ... 1
	return  val / 400.f;
}
inline float Grad2Deg(float val) {// 0 ... 360
	return  val / 400.f * 360;
}
inline float Grad2Rad(float val) {// 0 ... 2*F_PI
	return val / 200.f * F_PI;
}
inline float Rad2Turn(float val) {// 0 ... 1
	return val / F_2PI;
}
inline float Rad2Deg(float val) {// 0 ... 360
	return  val / F_PI * 180.f;
}
inline float Rad2Grad(float val) {// 0 ... 400
	return val / F_PI * 200.f;
}

inline bool  is_equal_approx(float a, float b, float eps) {
	float t = abs(a - b);
	return (t < eps);
}
inline float fact(float x) {
	if (x > 1.f)
		return fact(x - 1.f);
	return 1.f;
}
inline float mix(float a, float b, float factor) {
	return a * (1.f - factor) + b * factor;
}
inline float clamp(float v, float a, float b) {
	if (v < a)
		return a;
	if (v < b)
		return v;
	return b;
}
inline float saturate(float v) {
	if (v <= 0.f)
		return 0.f;
	if (v <= 1.f)
		return v;
	if (v >= 1.f)
		return v;
	return 0.f;
}
inline float smoothstep(float v, float a, float b) {
	// Scale, bias and saturate v to 0..1 range
	v = saturate((v - a) / (b - a));
	// Evaluate polynomial
	return v * v * (3.f - 2.f * v);
}
inline float smootherstep(float v, float a, float b) {
	// Scale, and clamp v to 0..1 range
	v = clamp((v - a) / (b - a), 0.0f, 1.0f);
	// Evaluate polynomial
	return v * v * v * (v * (v * 6.f - 15.f) + 10.f);
}
inline float snapped(float p_value, float p_step) {
	if (p_step != 0) {
		p_value = floor(p_value / p_step + 0.5f) * p_step;
	}
	return p_value;
}
inline float fposmod(float x, float y) {
	return (x >= 0.f) ? fmod(x, y) : y - fmod(-x, y);
}

template <typename T>
T bezier3(T a, T b, T c, float t) {
	T e = mix(a, b, t);
	T f = mix(b, c, t);

	return  mix(e, f, t);
}

template <typename T>
T bezier4(T a, T b, T c, T d, float t) {
	T e = mix(a, b, t);
	T f = mix(b, c, t);
	T g = mix(c, d, t);

	T h = mix(e, f, t);
	T i = mix(f, g, t);

	return mix(h, i, t);
}

template <typename T>
T bezier5(T a, T b, T c, T d, T e, float t) {
	T f = mix(a, b, t);
	T g = mix(b, c, t);
	T h = mix(c, d, t);
	T i = mix(d, e, t);

	T j = mix(f, g, t);
	T k = mix(g, h, t);
	T l = mix(h, i, t);

	T m = mix(j, k, t);
	T n = mix(k, l, t);

	return mix(m, n, t);
};

inline uint  halfbits_to_floatbits(ushort h) {
	ushort h_exp, h_sig;
	uint f_sgn, f_exp, f_sig;

	h_exp = (h & 0x7c00u);
	f_sgn = ((uint)h & 0x8000u) << 16;
	switch (h_exp) {
		case 0x0000u: /* 0 or subnormal */
			h_sig = (h & 0x03ffu);
			/* Signed zero */
			if (h_sig == 0) {
				return f_sgn;
			}
			/* Subnormal */
			h_sig <<= 1;
			while ((h_sig & 0x0400u) == 0) {
				h_sig <<= 1;
				h_exp++;
			}
			f_exp = ((uint)(127 - 15 - h_exp)) << 23;
			f_sig = ((uint)(h_sig & 0x03ffu)) << 13;
			return f_sgn + f_exp + f_sig;
		case 0x7c00u: /* inf or NaN */
			/* All-ones exponent and a copy of the significand */
			return f_sgn + 0x7f800000u + (((uint)(h & 0x03ffu)) << 13);
		default: /* normalized */
			/* Just need to adjust the exponent and shift */
			return f_sgn + (((uint)(h & 0x7fffu) + 0x1c000u) << 13);
	}
}

inline float halfptr_to_float(const ushort* h) {
	union {
		uint u32;
		float f32;
	} u;

	u.u32 = halfbits_to_floatbits(*h);
	return u.f32;
}

inline float half_to_float(const ushort h) {
	return halfptr_to_float(&h);
}

inline ushort make_half_float(float f) {
	union {
		float fv;
		uint ui;
	} ci;
	ci.fv = f;

	uint x = ci.ui;
	uint sign = (unsigned short)(x >> 31);
	uint mantissa;
	uint exp;
	ushort hf;

	// get mantissa
	mantissa = x & ((1 << 23) - 1);
	// get exponent bits
	exp = x & (0xFF << 23);
	if (exp >= 0x47800000) {
		// check if the original single precision float number is a NaN
		if (mantissa && (exp == (0xFF << 23))) {
			// we have a single precision NaN
			mantissa = (1 << 23) - 1;
		}
		else {
			// 16-bit half-float representation stores number as Inf
			mantissa = 0;
		}
		hf = (((ushort)sign) << 15) | (ushort)((0x1F << 10)) |
			(ushort)(mantissa >> 13);
	}
	// check if exponent is <= -15
	else if (exp <= 0x38000000) {
		/*// store a denorm half-float value or zero
	exp = (0x38000000 - exp) >> 23;
	mantissa >>= (14 + exp);
	hf = (((uint16_t)sign) << 15) | (uint16_t)(mantissa);
	*/
		hf = 0; //denormals do not work for 3D, convert to zero
	}
	else {
		hf = (((ushort)sign) << 15) |
			(ushort)((exp - 0x38000000) >> 13) |
			(ushort)(mantissa >> 13);
	}

	return hf;
}

inline float fast_roundf(float x) {
	//const float MAGIC_ROUNDf = 12582912.0; /* https://stackoverflow.com/questions/17035464/a-fast-method-to-round-a-double-to-a-32-bit-int-explained */
	x += 12582912.0f;
	x -= 12582912.0f;
	return x;
}

// faster than fast_roundf(), only one aritmetic(sum)
inline int fastRound(double x) {
	static const double MAGIC_ROUND = 6755399441055744.0; /* http://stereopsis.com/sree/fpu2006.html */
	union {
		double d;
		struct {
			int lw;
			int hw;
		};
	} fast_trunc;
	fast_trunc.d = x;
	fast_trunc.d += MAGIC_ROUND;
	return fast_trunc.lw;
}

template <typename T>
T clamp(T v, T a, T b) {
	if (v >= b)
		return b;
	if (v >= a)
		return v;
	return a;
}
