#ifndef TYPEDEFS_5428_H
#define TYPEDEFS_5428_H

#include <stdint.h>

typedef unsigned char B8;

typedef int8_t				I8;
typedef int16_t				I16;
typedef int32_t				I32;
typedef int64_t				I64;

typedef uint8_t				U8;
typedef uint16_t			U16;
typedef uint32_t			U32;
typedef uint64_t			U64;

typedef float				F32;
typedef double				F64;

#define glob static
#define intern static
#define lscope static
#define scast static_cast
#define rcast reinterpret_cast

#define INLINE __inline
#define INLINEFORCE __attribute__((always_inline))


#endif
