#pragma once

#ifndef NULL
    #define NULL (void *)0
#endif


#define likely(x)   __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

typedef unsigned char      bool;

typedef signed char        s8;
typedef signed short       s16;
typedef signed int         s32;

enum {
    FALSE = 0,
    TRUE,
};

#define ARRAY_SIZE(x)      (sizeof(x)/sizeof(x[0]))

