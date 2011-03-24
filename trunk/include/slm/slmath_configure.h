#ifndef SLMATH_CONFIGURE_H
#define SLMATH_CONFIGURE_H

/** Enable SIMD extensions (if supported by this platform) */
#if defined(_M_X64) || (_M_IX86_FP == 2)
#define SLMATH_SIMD
#endif

/** Enable namespace support, everything placed inside 'slm' namespace */
#define SLMATH_NAMESPACE

/** Enable vec-op asserts on _DEBUG build */
#define SLMATH_VEC_ASSERTS

/** Uncomment this if you wish to use old slmath namespace instead of slm */
//#define slmath slm

#endif // SLMATH_CONFIGURE_H

// This file is part of 'slmath' C++ library. Copyright (C) 2009 Jani Kajala (kajala@gmail.com). See http://sourceforge.net/projects/slmath/
