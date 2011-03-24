#include <slm/vec3.h>

SLMATH_BEGIN()

vec3 normalize( const vec3& v )
{
	SLMATH_VEC_ASSERT( check(v) );

	float len = length(v);
	SLMATH_VEC_ASSERT( len >= FLT_MIN );
	
	float invlen = 1.f / len;
	vec3 res( v.x*invlen, v.y*invlen, v.z*invlen );
	SLMATH_VEC_ASSERT( check(res) );
	return res;
}

vec3 cross( const vec3& a, const vec3& b )		
{
	SLMATH_VEC_ASSERT( check(a) );
	SLMATH_VEC_ASSERT( check(b) );

	// i    j     k
	// a.x  a.y   a.z
	// b.x  b.y   b.z
	vec3 res( a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x );
	SLMATH_VEC_ASSERT( check(res) );
	return res;
}

vec3 facenormal_ccw( const vec3& v0, const vec3& v1, const vec3& v2 )
{
	vec3 a( v1.x-v0.x, v1.y-v0.y, v1.z-v0.z );
	vec3 b( v2.x-v0.x, v2.y-v0.y, v2.z-v0.z );
	vec3 res( a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x );
	const float len = length(res);
	SLMATH_VEC_ASSERT( len >= FLT_MIN );
	res *= 1.f/len;
	return res;
}

vec3 facenormal_cw( const vec3& v0, const vec3& v1, const vec3& v2 )
{
	return facenormal_ccw( v0, v2, v1 );
}

vec3 faceforward( const vec3& n, const vec3& i, const vec3& nref )
{
	return dot(nref,i) < 0.f ? n : -n;
}

vec3 reflect( const vec3& i, const vec3& n )
{
	return i - n*( 2.f*dot(n,i) );
}

vec3 refract( const vec3& i, const vec3& n, float eta )
{
	float ndoti = dot(n,i);
	float k = 1.0f - eta*eta*(1.0f - ndoti*ndoti);
	if ( k < 0.f )
		return vec3(0.f);
	else
		return i*eta - n*(eta*ndoti+sqrtf(k));
}

SLMATH_END()

// This file is part of 'slmath' C++ library. Copyright (C) 2009 Jani Kajala (kajala@gmail.com). See http://sourceforge.net/projects/slmath/
