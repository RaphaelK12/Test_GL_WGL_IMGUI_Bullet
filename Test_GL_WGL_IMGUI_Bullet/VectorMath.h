#pragma once
#include "mathBase.h"
#include "VectorsGLM.h"

//////////////////////////////////////            //////////////////////////////////////
//////////////////////////////////////    vec2    //////////////////////////////////////
//////////////////////////////////////            //////////////////////////////////////

// Formula de Heron
template <class T>
float area(T A, T B, T C) {
	float a = length(A - B);
	float b = length(A - C);
	float c = length(B - C);
	float p = (a + b + c) / 2;
	float s = sqrt(p * (p - a) * (p - b) * (p - c));
	return s;
};

//////////////////////////////////////    vec2    //////////////////////////////////////

template <class T>
T IncrementalAveragin(T& average, T&value, ulong& samplecount) {
	samplecount++;
	average += (value - average) / samplecount;
	return average;
	//NewAverage = OldAverage + (NewValue - OldAverage) / NewSampleCount;
	//// Or:
	//Average += (NewValue - Average) / NewSampleCount;
	////or
	//Average = mix(Average, NewValue, 1.0 / NewSampleCount);
}



inline vec2  operator+(float p_scalar, const vec2& p_vec) {
	vec2 tmp;
	tmp.x = p_scalar + p_vec.x;
	tmp.y = p_scalar + p_vec.y;
	return tmp;
}
inline vec2  operator-(float p_scalar, const vec2& p_vec) {
	vec2 tmp;
	tmp.x = p_scalar - p_vec.x;
	tmp.y = p_scalar - p_vec.y;
	return tmp;
}
inline vec2  operator*(float p_scalar, const vec2& p_vec) {
	vec2 tmp;
	tmp.x = p_scalar * p_vec.x;
	tmp.y = p_scalar * p_vec.y;
	return tmp;
}
inline vec2  operator/(float p_scalar, const vec2& p_vec) {
	vec2 tmp;
	tmp.x = p_scalar / p_vec.x;
	tmp.y = p_scalar / p_vec.y;
	return tmp;
}

inline vec2  operator+(const vec2& p_vec, float p_scalar) {
	vec2 tmp;
	tmp.x = p_vec.x + p_scalar;
	tmp.y = p_vec.y + p_scalar;
	return tmp;
}
inline vec2  operator-(const vec2& p_vec, float p_scalar) {
	vec2 tmp;
	tmp.x = p_vec.x - p_scalar;
	tmp.y = p_vec.y - p_scalar;
	return tmp;
}
inline vec2  operator*(const vec2& p_vec, float p_scalar) {
	vec2 tmp;
	tmp.x = p_vec.x * p_scalar;
	tmp.y = p_vec.y * p_scalar;
	return tmp;
}
inline vec2  operator/(const vec2& p_vec, float p_scalar) {
	vec2 tmp;
	tmp.x = p_vec.x / p_scalar;
	tmp.y = p_vec.y / p_scalar;
	return tmp;
}

inline int  print(const vec2& v) {
	return printf("x = %f,	y = %f,	len = %f", v.x, v.y, length(v));
}
inline void from_json(const json& j, vec2& v) {
	j[0].get_to(v.x);
	j[1].get_to(v.y);
}
inline void from_json(const json& j, vec3& v) {
	j[0].get_to(v.x);
	j[1].get_to(v.y);
	j[2].get_to(v.z);
}
inline void from_json(const json& j, vec4& v) {
	j[0].get_to(v.x);
	j[1].get_to(v.y);
	j[2].get_to(v.z);
	j[3].get_to(v.w);
}

inline vec2  mix(const vec2& a, const vec2& b, float factor) {
	return a * (1 - factor) + b * factor;
}
inline vec2  clamp(const vec2& v, float& a, float& b) {
	vec2 tmp;
	tmp.x = clamp(v.x, a, b);
	tmp.y = clamp(v.y, a, b);
	return tmp;
}
inline vec2  clamp(const vec2& v, const vec2& a, const  vec2& b) {
	vec2 tmp;
	tmp.x = clamp(v.x, a.x, b.x);
	tmp.y = clamp(v.y, a.y, b.y);
	return tmp;
}
inline vec2  saturate(const vec2& v) {
	vec2 tmp;
	tmp.x = saturate(v.x);
	tmp.y = saturate(v.y);
	return tmp;
}
inline vec2  smoothstep(const vec2& v, float a, float b) {
	vec2 tmp;
	tmp.x = smoothstep(v.x, a, b);
	tmp.y = smoothstep(v.y, a, b);
	return tmp;
}
inline vec2  smoothstep(const vec2& v, const vec2& a, const  vec2& b) {
	vec2 tmp;
	tmp.x = smoothstep(v.x, a.x, b.x);
	tmp.y = smoothstep(v.y, a.y, b.y);
	return tmp;
}
inline vec2  smootherstep(const vec2& v, float a, float b) {
	vec2 tmp;
	tmp.x = smootherstep(v.x, a, b);
	tmp.y = smootherstep(v.y, a, b);
	return tmp;
}
inline vec2  smootherstep(const vec2& v, const vec2& a, const vec2& b) {
	vec2 tmp;
	tmp.x = smootherstep(v.x, a.x, b.x);
	tmp.y = smootherstep(v.y, a.y, b.y);
	return tmp;
}

inline vec2  normalize(const vec2& v) {
	float l = v.x * v.x + v.y * v.y;
	vec2 tmp(v);
	if (l != 0 && l != 1.f) {
		l = sqrt(l);
		tmp.x /= l;
		tmp.y /= l;
	}
	return tmp;
}
inline float distance(const vec2& v, const vec2& val) {
	return abs(length(v - val));
}
inline float dot(const vec2& v, const vec2& val) {
	return (v.x * val.x) + (v.y * val.y);
}
inline float GetAngle(const vec2& v, const vec2& rcVect) {
	float divid, fNum;

	divid = length(v) * length(rcVect);

	if ((divid < -1e-10f) || (divid > 1e-10f)) {
		fNum = dot(v, rcVect) / divid;
		if (fNum < -1)
			return F_PI;
		else if (fNum > 1)
			return 0.0F;
		else
			return acos(fNum);
	}
	else
		return 1.f; // division by zero
}
inline float sqr(const vec2& v) {
	return ((v.x * v.x) + (v.y * v.y));
}
inline float length(const vec2& v) {
	float l = (v.x * v.x) + (v.y * v.y);
	if (l != 0)
		l = sqrt(l);
	return l;
}
inline float len_sq(const vec2& v) {
	return (v.x * v.x) + (v.y * v.y);
}
inline float cross(const vec2& v, const vec2& val) {
	return (v.x * val.y) - (v.y * val.x);
}

// 0 ~ 1						
inline vec2 rotateTurn(const vec2& v, float val) {
	val = val * 2 * F_PI;
	float fsin, fcos;
	vec2 tmp;
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
// 0 ~ 360
inline vec2 rotateDeg(const vec2& v, float val) {
	val = val / 180.f * F_PI;
	float fsin, fcos;
	vec2 tmp;
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
// 0 ~ 400
inline vec2 rotateGrad(const vec2& v, float val) {
	val = val / 200.f * F_PI;
	float fsin, fcos;
	vec2 tmp;
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
// 0 ~ 2*F_PI (6.283185)
inline vec2 rotateRad(const vec2& v, float val) {
	float fsin, fcos;
	vec2 tmp;
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}

inline void  fitImage(const vec2& screen, const vec2& im, float zoom, vec2& rcStart, vec2& rcEnd) {
	//vec2 rc;
	float w1 = 1, w2 = 1;
	float x = 1, y = 1, scx = 1, scy = 1;
	float x_start = 2, y_start = 2, x_end = 4, y_end = 4;
	float bmx = im.x * zoom;
	float bmy = im.y * zoom;

	{ // if screnn < image then rescale image to fit in window
		scx = screen.x - 4;
		scy = screen.y - 4;
		x = bmx;
		y = bmy;

		if (scx < x) w1 = scx / x;
		if (scy < y) w2 = scy / y;
		x = (bmx)*min(w1, w2);
		y = (bmy)*min(w1, w2);
		x_end = floorf(x + 0.5f);
		y_end = floorf(y + 0.5f);

		x_start = floorf((screen.x / 2.f - x / 2.f) + 0.5f);
		y_start = floorf((screen.y / 2.f - y / 2.f) + 0.5f);
		x_start = max(x_start, 2.f);
		y_start = max(y_start, 2.f);
	};
	{ // rescale to window size, maintaining aspect
		scx = screen.x - 4;
		scy = screen.y - 4;
		x = bmx;
		y = bmy;

		/*if (scx < x)*/ w1 = scx / x;
		/*if (scy < y)*/ w2 = scy / y;
		x = (bmx)*min(w1, w2);
		y = (bmy)*min(w1, w2);
		x_end = floorf(x + 0.5f);
		y_end = floorf(y + 0.5f);
		x_start = floorf((screen.x / 2.f - x / 2.f) + 0.5f);
		y_start = floorf((screen.y / 2.f - y / 2.f) + 0.5f);
		x_start = max(x_start, 2.f);
		y_start = max(y_start, 2.f);
	};


	rcStart.x = x_start;
	rcStart.y = y_start;
	rcEnd.x = x_end;
	rcEnd.y = y_end;
}

inline float pDistance2(const vec2& point, const vec2& lineStart, const vec2& lineEnd) {
	float  A = point.x - lineStart.x;
	float  B = point.y - lineStart.y;
	float  C = lineEnd.x - lineStart.x;
	float  D = lineEnd.y - lineStart.y;
	float  dot = A * C + B * D;
	float  len_sq = C * C + D * D;
	float  param = -1;
	if (len_sq != 0) //in case of 0 length line
		param = dot / len_sq;
	float  xx, yy;
	if (param < 0) {
		xx = lineStart.x;
		yy = lineStart.y;
	}
	else if (param > 1) {
		xx = lineEnd.x;
		yy = lineEnd.y;
	}
	else {
		xx = lineStart.x + param * C;
		yy = lineStart.y + param * D;
	}
	float  dx = point.x - xx;
	float  dy = point.y - yy;
	return sqrt(dx * dx + dy * dy);
}

inline float distanceToLineInfinite(const vec2& point, const vec2& lineStart, const vec2& lineEnd) {
	vec2 dir = lineEnd - lineStart;
	return fabs((cross(dir, lineStart - point))) / length(dir);
}
inline float distanceToLineInfinite2(const vec2& point, const vec2& linePos, const vec2& dir) {
	return fabs((cross(dir, linePos - point))) / length(dir);
}
inline float distanceToLine(const vec2& point, const vec2& lineStart, const vec2& lineEnd) {
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
	vec2  dxy = point - pointProjection;
	return sqrt(len_sq(dxy));
}
inline float lineDistance(const vec2 &a, const vec2 &b, const vec2 &p) {
    vec2 ba = b-a;
    vec2 pa = p-a;
	float t = clamp(dot(pa,ba)/dot(ba,ba), 0.0, 1.0);
    return length(pa-ba*t);
}

inline vec2 closestPointToLine(const vec2& point, const vec2& lineStart, const vec2& lineEnd) {
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



inline float magnitude(const vec2& v) {
	return sqrt(pow(v.x, 2.f) + pow(v.y, 2.f));
}

inline float Angle(const vec2& v) {
	return atan2(v.y, v.x);
}
inline bool  is_normalized(const vec2& v) {
	// use length_squared() instead of length() to avoid sqrt(), makes it more stringent.
	return is_equal_approx(len_sq(v), 1.0, F_EPSILON);
}
inline float distance_to(const vec2& v, const vec2& p_vec2) {
	return sqrt((v.x - p_vec2.x) * (v.x - p_vec2.x) + (v.y - p_vec2.y) * (v.y - p_vec2.y));
}
inline float distance_squared_to(const vec2& v, const vec2& p_vec2) {
	return (v.x - p_vec2.x) * (v.x - p_vec2.x) + (v.y - p_vec2.y) * (v.y - p_vec2.y);
}
inline float angle_to(const vec2& v, const vec2& p_vec2) {
	return atan2(cross(v, p_vec2), dot(v, p_vec2));
}
inline float angle_to_point(vec2& v, const vec2& p_vec2) {
	return atan2(v.y - p_vec2.y, v.x - p_vec2.x);
}
inline vec2  floor(const vec2& v) {
	return vec2(floor(v.x), floor(v.y));
}
inline vec2  ceil(const vec2& v) {
	return vec2(ceil(v.x), ceil(v.y));
}
inline vec2  round(const vec2& v) {
	return vec2(round(v.x), round(v.y));
}
inline vec2  rotated(const vec2& v, float p_by) {
	float sine = sin(p_by);
	float cosi = cos(p_by);
	return vec2(
		v.x * cosi - v.y * sine,
		v.x * sine + v.y * cosi);
}
inline vec2  posmod(const vec2& v, float p_mod) {
	return vec2(fposmod(v.x, p_mod), fposmod(v.y, p_mod));
}
inline vec2  posmodv(const vec2& v, const vec2& p_modv) {
	return vec2(fposmod(v.x, p_modv.x), fposmod(v.y, p_modv.y));
}
inline vec2  project(const vec2& v, const vec2& p_b) {
	return p_b * (dot(v, p_b) / len_sq(p_b));
}
inline vec2  snapped(const vec2& v, const vec2& p_by) {
	return vec2(
		snapped(v.x, p_by.x),
		snapped(v.y, p_by.y));
}
inline vec2  clamped(const vec2& v, float p_len) {
	float l = length(v);
	vec2 ve = v;
	if (l > 0 && p_len < l) {
		ve /= l;
		ve *= p_len;
	}

	return v;
}
inline vec2  cubic_interpolate(const vec2& v, const vec2& p_b, const vec2& p_pre_a, const vec2& p_post_b, float p_t) {
	vec2 p0 = p_pre_a;
	vec2 p1 = v;
	vec2 p2 = p_b;
	vec2 p3 = p_post_b;

	float t = p_t;
	float t2 = t * t;
	float t3 = t2 * t;

	vec2 out;
	out = 0.5 * ((p1 * 2.0) +
				 (-p0 + p2) * t +
				 (2.0 * p0 - 5.0 * p1 + 4 * p2 - p3) * t2 +
				 (-p0 + 3.0 * p1 - 3.0 * p2 + p3) * t3);
	return out;
}
inline vec2  move_toward(const vec2& v, const vec2& p_to, float p_delta) {
	vec2 vd = p_to - v;
	float len = length(vd);
	return len <= p_delta || len < F_CMP_EPSILON ? p_to : v + vd / len * p_delta;
}
inline vec2  slide(const vec2& v, const vec2& p_normal) {// slide returns the component of the vector along the given plane, specified by its normal vector.
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!p_normal.is_normalized(), vec2(), "The normal vec2 must be normalized.");
#endif
	return v - p_normal * dot(v, p_normal);
}
inline vec2  reflect(const vec2& v, const vec2& p_normal) {
#ifdef MATH_CHECKS
	ERR_FAIL_COND_V_MSG(!p_normal.is_normalized(), vec2(), "The normal vec2 must be normalized.");
#endif
	return 2.0 * p_normal * dot(v, p_normal) - v;
}
inline vec2  bounce(const vec2& v, const vec2& p_normal) {
	return -reflect(v, p_normal);
}
inline bool  is_equal_approx(const vec2& v, const vec2& p_v) {
	return is_equal_approx(v.x, p_v.x, F_CMP_EPSILON) && is_equal_approx(v.y, p_v.y, F_CMP_EPSILON);
}



//////////////////////////////////////    vec3    //////////////////////////////////////

inline vec3  operator+(float p_scalar, const vec3& p_vec) {
	vec3 tmp;
	tmp.x = p_scalar + p_vec.x;
	tmp.y = p_scalar + p_vec.y;
	tmp.z = p_scalar + p_vec.z;
	return tmp;
}
inline vec3  operator-(float p_scalar, const vec3& p_vec) {
	vec3 tmp;
	tmp.x = p_scalar - p_vec.x;
	tmp.y = p_scalar - p_vec.y;
	tmp.z = p_scalar - p_vec.z;
	return tmp;
}
inline vec3  operator*(float p_scalar, const vec3& p_vec) {
	vec3 tmp;
	tmp.x = p_scalar * p_vec.x;
	tmp.y = p_scalar * p_vec.y;
	tmp.z = p_scalar * p_vec.z;
	return tmp;
}
inline vec3  operator/(float p_scalar, const vec3& p_vec) {
	vec3 tmp;
	tmp.x = p_scalar / p_vec.x;
	tmp.y = p_scalar / p_vec.y;
	tmp.z = p_scalar / p_vec.z;
	return tmp;
}

inline int   print(const vec3& v) {
	return printf("x = %f,	y = %f,	z = %f,	len = %f\n", v.x, v.y, v.z, length(v));
}

inline float len_sq(const vec3& v) {
	return (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
}
inline float length(const vec3& v) {
	return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}
inline float distance(const vec3& v, const vec3& val) {
	return abs(length(v - val));
}
inline float dot(const vec3& v, const vec3& val) {
	return (v.x * val.x) + (v.y * val.y) + (v.z * val.z);
}
inline float sqr(const vec3& v) {
	return (v.x * v.x) + (v.y * v.y) + (v.z * v.z);
}
inline float GetAngle(const vec3& v, const vec3& rcVect) {
	float divid, fNum;

	divid = length(v) * length(rcVect);

	if ((divid < -1e-10f) || (divid > 1e-10f)) {
		fNum = dot(v, rcVect) / divid;
		if (fNum < -1)
			return F_PI;
		else if (fNum > 1)
			return 0.0F;
		else
			return acos(fNum);
	}
	else
		return 1.f; // division by zero
}
inline float magnitude(const vec3& v) {
	return sqrt(pow(v.x, 2.f) + pow(v.y, 2.f) + pow(v.z, 2.f));
}

inline vec3  mix(const vec3& a, const vec3& b, float factor) {
	return a * (1 - factor) + b * factor;
}
inline vec3  clamp(const vec3& v, float a, float b) {
	vec3 tmp;
	tmp.x = clamp(v.x, a, b);
	tmp.y = clamp(v.y, a, b);
	tmp.z = clamp(v.z, a, b);
	return tmp;
}
inline vec3  clamp(const vec3& v, const vec3& a, const vec3& b) {
	vec3 tmp;
	tmp.x = clamp(v.x, a.x, b.x);
	tmp.y = clamp(v.y, a.y, b.y);
	tmp.z = clamp(v.z, a.z, b.z);
	return tmp;
}
inline vec3  saturate(const vec3& v) {
	vec3 tmp;
	tmp.x = saturate(v.x);
	tmp.y = saturate(v.y);
	tmp.z = saturate(v.z);
	return tmp;
}
inline vec3  vmod(vec3 v, float m) {
	return vec3(fmodf(v.x, m), fmodf(v.y, m), fmodf(v.z, m));
}

inline vec3  smoothstep(const vec3& v, float a, float b) {
	vec3 tmp;
	tmp.x = smoothstep(v.x, a, b);
	tmp.y = smoothstep(v.y, a, b);
	tmp.z = smoothstep(v.z, a, b);
	return tmp;
}
inline vec3  smoothstep(const vec3& v, const vec3& a, const vec3& b) {
	vec3 tmp;
	tmp.x = smoothstep(v.x, a.x, b.x);
	tmp.y = smoothstep(v.y, a.y, b.y);
	tmp.z = smoothstep(v.z, a.z, b.z);
	return tmp;
}
inline vec3  smootherstep(const vec3& v, float a, float b) {
	vec3 tmp;
	tmp.x = smootherstep(v.x, a, b);
	tmp.y = smootherstep(v.y, a, b);
	tmp.z = smootherstep(v.z, a, b);
	return tmp;
}
inline vec3  smootherstep(const vec3& v, const vec3& a, const vec3& b) {
	vec3 tmp;
	tmp.x = smootherstep(v.x, a.x, b.x);
	tmp.y = smootherstep(v.y, a.y, b.y);
	tmp.z = smootherstep(v.z, a.z, b.z);
	return tmp;
}

inline vec3  normalize(const vec3& v) {
	vec3 tmp(v);
	float fLen = length(v);
	if (fLen != 0.f && fLen != 1.f) {
		tmp.x /= fLen;
		tmp.y /= fLen;
		tmp.z /= fLen;
	}
	return tmp;
}
inline vec3  cross(const vec3& v, const vec3& val) {
	vec3 tmp;
	tmp.x = (v.y * val.z) - (v.z * val.y);
	tmp.y = (v.z * val.x) - (v.x * val.z);
	tmp.z = (v.x * val.y) - (v.y * val.x);
	return tmp;
}
inline vec3  sqrt(const vec3& a) {
	return vec3(sqrt(a.x), sqrt(a.y), sqrt(a.z));
}
inline vec3  faceforward(const vec3& N, const vec3& I, const vec3& Nref) {
	if (dot(Nref, I) < 0.0f) {
		return N;
	}
	return -N;
}
inline vec3  reflect(const vec3& I, const vec3& N) {
	return I - N * dot(N, I) * 2.0f;
}
inline vec3  refract(const vec3& I, const vec3& N, float eta) {
	float k = 1.0f - eta * eta * (1.0f - dot(N, I) * dot(N, I));
	if (k < 0.0f)
		return vec3(0.0f);
	else
		return I * eta - (N * sqrt(k)) + eta * dot(N, I);
}
inline vec3  calcNormal(const vec3& v1, const vec3& v2, const vec3& v3) {
	vec3 n1, n2;
	n1 = v1 - v2;
	n2 = v3 - v2;
	return cross(n1, n2);
}
inline vec3  faceNormal2(const vec3& v1, const vec3& v2, const vec3& v3) {
	vec3 n1, n2;
	// Calculate two vectors from the three points
	n1 = v1 - v2;
	n2 = v3 - v2;
	// Take the cross product of the two vectors to get the normal vector and Normalize the vector (shorten length to one)
	return cross(n1, n2) * abs(area(v1, v2, v3));
}
inline vec3  faceNormal(const vec3& v1, const vec3& v2, const vec3& v3) {
	vec3 n1, n2;
	// Calculate two vectors from the three points
	n1 = v1 - v2;
	n2 = v3 - v2;
	// Take the cross product of the two vectors to get the normal vector and Normalize the vector (shorten length to one)
	return normalize(cross(n1, n2));
}

// 0 ~ 1						
inline vec3  rotateXTurn(const vec3& v, float val) { // 0 ~ 1
	val = val * 2 * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.y = (v.y * fcos) - (v.z * fsin);
	tmp.z = (v.y * fsin) + (v.z * fcos);
	return tmp;
}
// 0 ~ 360
inline vec3  rotateXDeg(const vec3& v, float val) { // 0 ~ 360
	val = val / 180.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.y = (v.y * fcos) - (v.z * fsin);
	tmp.z = (v.y * fsin) + (v.z * fcos);
	return tmp;
}
// 0 ~ 400
inline vec3  rotateXGrad(const vec3& v, float val) { // 0 ~ 400
	val = val / 200.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.y = (v.y * fcos) - (v.z * fsin);
	tmp.z = (v.y * fsin) + (v.z * fcos);
	return tmp;
}
// 0 ~ 2*F_PI (6.283185)
inline vec3  rotateXRad(const vec3& v, float val) { // 0 ~ 2*F_PI (6.283185)
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.y = (v.y * fcos) - (v.z * fsin);
	tmp.z = (v.y * fsin) + (v.z * fcos);
	return tmp;
}

// 0 ~ 1						
inline vec3  rotateYTurn(const vec3& v, float val) {
	val = val * 2 * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.z * fsin) + (v.x * fcos);
	tmp.z = (v.z * fcos) - (v.x * fsin);
	return tmp;
}
// 0 ~ 360
inline vec3  rotateYDeg(const vec3& v, float val) {
	val = val / 180.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.z * fsin) + (v.x * fcos);
	tmp.z = (v.z * fcos) - (v.x * fsin);
	return tmp;
}
// 0 ~ 400
inline vec3  rotateYGrad(const vec3& v, float val) {
	val = val / 200.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.z * fsin) + (v.x * fcos);
	tmp.z = (v.z * fcos) - (v.x * fsin);
	return tmp;
}
// 0 ~ 2*F_PI (6.283185)
inline vec3  rotateYRad(const vec3& v, float val) {
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.z * fsin) + (v.x * fcos);
	tmp.z = (v.z * fcos) - (v.x * fsin);
	return tmp;
}

// 0 ~ 1						
inline vec3  rotateZTurn(const vec3& v, float val) {
	val = val * 2 * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
// 0 ~ 360
inline vec3  rotateZDeg(const vec3& v, float val) {
	val = val / 180.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
// 0 ~ 400
inline vec3  rotateZGrad(const vec3& v, float val) {
	val = val / 200.f * F_PI;
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(val);
	fcos = cos(val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}
// 0 ~ 2*F_PI (6.283185)
inline vec3  rotateZRad(const vec3& v, float val) {
	float fsin, fcos;
	vec3 tmp(v);
	fsin = sin(-val);
	fcos = cos(-val);
	tmp.x = (v.x * fcos) - (v.y * fsin);
	tmp.y = (v.x * fsin) + (v.y * fcos);
	return tmp;
}

// 0 ~ 1						
inline vec3  rotateTurn(const vec3& v, const vec3& val) {
	vec3 tmp(v);
	tmp = rotateZTurn(v, val.z);
	tmp = rotateYTurn(tmp, val.y);
	tmp = rotateXTurn(tmp, val.x);
	return tmp;
}
// 0 ~ 360
inline vec3  rotateDeg(const vec3& v, const vec3& val) {
	vec3 tmp(v);
	tmp = rotateZDeg(v, val.z);
	tmp = rotateYDeg(tmp, val.y);
	tmp = rotateXDeg(tmp, val.x);
	return tmp;
}
// 0 ~ 400
inline vec3  rotateGrad(const vec3& v, const vec3& val) {
	vec3 tmp(v);
	tmp = rotateZGrad(v, val.z);
	tmp = rotateYGrad(tmp, val.y);
	tmp = rotateXGrad(tmp, val.x);
	return tmp;
}
// 0 ~ 2*F_PI (6.283185)
inline vec3  rotateRad(const vec3& v, const vec3& val) {
	vec3 tmp(v);
	if (val.z != 0.f)
		tmp = rotateZRad(v, val.z);
	if (val.y != 0.f)
		tmp = rotateYRad(tmp, val.y);
	if (val.x != 0.f)
		tmp = rotateXRad(tmp, val.x);
	return tmp;
}

inline vec3  rotateAroundAxis(const vec3& p, const vec3& axis, float angle) {
	float costheta = cosf(angle);
	float sintheta = sinf(angle);
	vec3 r;

	r.x = ((costheta + (1 - costheta) * axis.x * axis.x) * p.x) +
		(((1 - costheta) * axis.x * axis.y - axis.z * sintheta) * p.y) +
		(((1 - costheta) * axis.x * axis.z + axis.y * sintheta) * p.z);

	r.y = (((1 - costheta) * axis.x * axis.y + axis.z * sintheta) * p.x) +
		((costheta + (1 - costheta) * axis.y * axis.y) * p.y) +
		(((1 - costheta) * axis.y * axis.z - axis.x * sintheta) * p.z);

	r.z = (((1 - costheta) * axis.x * axis.z - axis.y * sintheta) * p.x) +
		(((1 - costheta) * axis.y * axis.z + axis.x * sintheta) * p.y) +
		((costheta + (1 - costheta) * axis.z * axis.z) * p.z);

	return r;
}

inline vec3  rotateAxis(const vec3& v, const vec3& axis, float theta) {
	float cos_theta = cos(theta);
	float sin_theta = sin(theta);
	return (v * cos_theta) + (cross(axis, v) * sin_theta) + (axis * dot(axis, v)) * (1 - cos_theta);
}

// distance to line direction
inline float distanceToLineInfinite(const vec3& point, const vec3& lineStart, const vec3& lineEnd) {
	vec3 dir = lineEnd - lineStart;
	return fabs(length(cross(dir, lineStart - point))) / length(dir);
}
// distance to infinite line
inline float distanceToLineInfinite2(const vec3& point, const vec3& linePos, const vec3& dir) {
	return fabs(length(cross(dir, linePos - point))) / length(dir);
}
// distance to line
inline float distanceToLine(const vec3& point, const vec3& lineStart, const vec3& lineEnd) {
	vec3 dr = lineEnd - lineStart;
	float  dt = dot(point - lineStart, dr);
	float  len_s = sqr(dr);
	float  param = -1;
	if (len_s != 0) //in case of 0 length line
		param = dt / len_s;
	vec3  pointProjection;
	if (param < 0) {
		pointProjection = lineStart;
	}
	else if (param > 1) {
		pointProjection = lineEnd;
	}
	else {
		pointProjection = lineStart + param * dr;
	}
	vec3  dxy = point - pointProjection;
	return sqrt(len_sq(dxy));
}

inline vec3 closestPointToLine(const vec3& point, const vec3& lineStart, const vec3& lineEnd) {
	vec3 dr = lineEnd - lineStart;
	float  dt = dot(point - lineStart, dr);
	float  len_s = sqr(dr);
	float  param = -1;
	if (len_s != 0) //in case of 0 length line
		param = dt / len_s;
	vec3  pointProjection;
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

