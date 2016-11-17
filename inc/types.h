#ifndef TYPES_H
#define TYPES_H

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef unsigned long size_t;

typedef __builtin_va_list va_list;

#define bool _Bool
#define true 1
#define false 0

#define va_start(ap,last) __builtin_va_start(ap, last)
#define va_end(ap) __builtin_va_end(ap)
#define va_arg(ap,type) __builtin_va_arg(ap, type)
#define va_copy(dest,src) __builtin_va_copy(dest, src)

#endif
