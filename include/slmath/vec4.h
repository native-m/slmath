#ifndef SLMATH_VEC4_H
#define SLMATH_VEC4_H

#include <slmath/vec3.h>

SLMATH_BEGIN()

/**
 * 4-vector.
 *
 * Note naming convention: This class is starting with small letter since 
 * it is NOT initialized by the default constructor, much like int, float, etc. types.
 *
 * @ingroup vec_util
 */
#ifdef SWIG
class vec4
#else
SLMATH_ALIGN16 class vec4
#endif
{
public:
	/** Constants related to the class. */
	enum Constants
	{
		/** Number of dimensions in this vector. */
		SIZE = 4,
	};

	/** The first component of the vector. */
	float x;

	/** The second component of the vector. */
	float y;

	/** The third component of the vector. */
	float z;

	/** The fourth component of the vector. */
	float w;

	/** Constructs undefined 4-vector. */
	vec4();

	/** 
	 * Constructs vector with all components set to the same value.
	 * @param v Each of the vector components will be set to this value.
	 */
	explicit vec4( float v );

	/** 
	 * Constructs the vector from scalars. 
	 * @param x0 The vector X-component (0)
	 * @param y0 The vector Y-component (1)
	 * @param z0 The vector Z-component (2)
	 * @param w0 The vector W-component (3)
	 */
	vec4( float x0, float y0, float z0, float w0 );

	/** 
	 * Constructs the vector from 2-vector and 2 scalars. 
	 * @param v0 The vector XY-components (0-2)
	 * @param z0 The vector Z-component
	 * @param w0 The vector W-component
	 */
	vec4( const vec2& v0, float z0, float w0 );

	/** 
	 * Constructs the vector from 3-vector and scalar. 
	 * @param v0 The vector XYZ-components (0-3)
	 * @param w0 The vector W-component (3)
	 */
	vec4( const slmath::vec3& v0, float w0 );

#ifndef SWIG
	/**
	 * Constructs vector from 128bit scalar type.
	 */
	vec4( const m128_t& xyzw )		{m128()=xyzw;}
#endif

	/** Sets vector value. */
	void		set( float x0, float y0, float z0, float w0 );

	/** Component wise addition. */
	vec4&		operator+=( const slmath::vec4& o );

	/** Component wise subtraction. */
	vec4&		operator-=( const slmath::vec4& o );

	/** Component wise scalar multiplication. */
	vec4&		operator*=( float s );

	/** Component wise scalar division. */
	vec4&		operator/=( float s );

	/** Component wise multiplication. */
	vec4&		operator*=( const slmath::vec4& o );

	/** Component wise division. */
	vec4&		operator/=( const slmath::vec4& o );

	/** Returns component at specified index. */
	float&		operator[]( size_t i );

	/** Returns sub-vector. */
	vec3&		xyz();

#ifndef SWIG
	/** Returns 128bit scalar type. Internal use only. */
	m128_t&		m128()			{return *(m128_t*)&x;}
#endif

	/** Component wise multiplication. */
	vec4		operator*( const slmath::vec4& o ) const;

	/** Component wise division. */
	vec4		operator/( const slmath::vec4& o ) const;

	/** Component wise addition. */
	vec4		operator+( const slmath::vec4& o ) const;

	/** Component wise subtraction. */
	vec4		operator-( const slmath::vec4& o ) const;

	/** Component wise subtraction. */
	vec4		operator-() const;

	/** Component wise scalar multiplication. */
	vec4		operator*( float s ) const;

	/** Component wise scalar division. */
	vec4		operator/( float s ) const;

	/** Returns component at specified index. */
	const float& operator[]( size_t i ) const;

	/** Returns true if vectors are bitwise equal. */
	bool		operator==( const slmath::vec4& o ) const;

	/** Returns true if vectors are bitwise inequal. */
	bool		operator!=( const slmath::vec4& o ) const;

	/** Returns sub-vector. */
	const slmath::vec3&	xyz() const;

#ifndef SWIG
	/** Returns 128bit scalar type. Internal use only. */
	const m128_t& m128() const		{return *(const m128_t*)&x;}
#endif
};


/** 
 * Component wise scalar multiplication. 
 * @ingroup vec_util
 */
vec4			operator*( float s, const slmath::vec4& v );

/** 
 * Returns length of the vector. 
 * @ingroup vec_util
 */
float			length( const slmath::vec4& v );

/** 
 * Returns dot product (inner product) of two vectors. 
 * @param a The first vector
 * @param b The second vector
 * @return a dot b
 * @ingroup vec_util
 */
float			dot( const slmath::vec4& a, const slmath::vec4& b );

/** 
 * Returns the vector normalized to unit (1) length.
 * @ingroup vec_util
 */
vec4			normalize( const slmath::vec4& v );

/**
 * Returns component wise maximum of two vectors.
 * @ingroup vec_util
 */
vec4			max( const slmath::vec4& a, const slmath::vec4& b );

/**
 * Returns component wise minimum of two vectors.
 * @ingroup vec_util
 */
vec4			min( const slmath::vec4& a, const slmath::vec4& b );

/**
 * Returns component wise absolute of the vector.
 * @ingroup vec_util
 */
vec4			abs( const slmath::vec4& v );

/** 
 * Returns linear blend between two values. Formula is x*(1-a)+y*a.
 * @param x The first value.
 * @param y The second value.
 * @param a The blend factor.
 * @return x*(1-a)+y*a
 * @ingroup vec_util
 */
slmath::vec4	mix( const slmath::vec4& x, const slmath::vec4& y, float a );

/** 
 * Returns distance between two values. 
 * @param p0 The first point vector.
 * @param p1 The second point vector.
 * @return Distance between p0 and p1, i.e. length(p1-p0).
 * @ingroup vec_util
 */
float			distance( const slmath::vec4& p0, const slmath::vec4& p1 );

/**
 * Returns value with components clamped between [min,max].
 * @ingroup vec_util
 */
slmath::vec4	clamp( const slmath::vec4& v, const slmath::vec4& min, const slmath::vec4& max );

/**
 * Returns value with components clamped between [0,1].
 * @ingroup vec_util
 */
slmath::vec4	saturate( const slmath::vec4& v );

/**
 * Returns true if all components are valid numbers.
 * @ingroup vec_util
 */
bool			check( const slmath::vec4& v );

/**
 * Returns negated vector. This function is useful for scripting where overloaded operators are not available.
 * @ingroup vec_util
 */
slmath::vec4	neg( const slmath::vec4& a );

/**
 * Adds two vectors together. This function is useful for scripting where overloaded operators are not available.
 * @ingroup vec_util
 */
slmath::vec4	add( const slmath::vec4& a, const slmath::vec4& b );

/**
 * Subtracts two vectors together. This function is useful for scripting where overloaded operators are not available.
 * @ingroup vec_util
 */
slmath::vec4	sub( const slmath::vec4& a, const slmath::vec4& b );

/**
 * Multiplies vector by scalar. This function is useful for scripting where overloaded operators are not available.
 * @ingroup vec_util
 */
slmath::vec4	mul( const slmath::vec4& a, float b );

/**
 * Multiplies vector by scalar. This function is useful for scripting where overloaded operators are not available.
 * @ingroup vec_util
 */
slmath::vec4	mul( float b, const slmath::vec4& a );

#include <slmath/vec4.inl>

SLMATH_END()

#endif

// This file is part of 'slmath' C++ library. Copyright (C) 2009 Jani Kajala (kajala@gmail.com). See http://sourceforge.net/projects/slmath/
