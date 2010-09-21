/*
 * Copyright (c) 2009  Marko Kreen
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/** @file
 * Random stuff that does not fit elsewhere.
 */
#ifndef _USUAL_MISC_H_
#define _USUAL_MISC_H_

#include <usual/base.h>

#ifdef WORDS_BIGENDIAN
#define FOURCC(a,b,c,d) \
	(  ((unsigned int)(unsigned char)(a) << 24) \
	 | ((unsigned int)(unsigned char)(b) << 16) \
	 | ((unsigned int)(unsigned char)(c) << 8) \
	 | ((unsigned int)(unsigned char)(d)))
#else
/** Four-byte identifier as integer */
#define FOURCC(a,b,c,d) \
	(  ((unsigned int)(unsigned char)(a)) \
	 | ((unsigned int)(unsigned char)(b) << 8) \
	 | ((unsigned int)(unsigned char)(c) << 16) \
	 | ((unsigned int)(unsigned char)(d) << 24))
#endif

/** Checks if integer has only one bit set */
static inline int is_power_of_2(int n)
{
	return (n > 0) && !(n & (n - 1));
}

#if defined(__i386__) || defined(__x86_64__)
#define mb()  asm volatile("mfence":::"memory")
#define rmb() asm volatile("lfence":::"memory")
#define wmb() asm volatile("sfence":::"memory")
#endif

/*
 * Single-eval and type-safe rol/ror
 */

/** Rotate 16-bit int to left */
static inline uint16_t rol16(uint16_t v, int s)
{
	return (v << s) | (v >> (16 - s));
}
/** Rotate 32-bit int to left */
static inline uint32_t rol32(uint32_t v, int s)
{
	return (v << s) | (v >> (32 - s));
}
/** Rotate 64-bit int to left */
static inline uint64_t rol64(uint64_t v, int s)
{
	return (v << s) | (v >> (64 - s));
}
/** Rotate 16-bit int to right */
static inline uint16_t ror16(uint16_t v, int s) { return rol16(v, 16 - s); }
/** Rotate 32-bit int to right */
static inline uint32_t ror32(uint32_t v, int s) { return rol32(v, 32 - s); }
/** Rotate 64-bit int to right */
static inline uint64_t ror64(uint64_t v, int s) { return rol64(v, 64 - s); }

#endif

