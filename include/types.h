#ifndef TYPES_H
#define TYPES_H

#ifdef CXX_SIMULATOR
#include <stdint.h>
#include <stdbool.h>
#elif defined(__arm__) || defined(__mips__)
typedef signed char     int8_t;
typedef unsigned char  uint8_t;

typedef signed short     int16_t;
typedef unsigned short  uint16_t;

typedef signed int     int32_t;
typedef unsigned int  uint32_t;

typedef long long unsigned int uint64_t;
typedef long long signed int int64_t;

typedef _Bool    bool;

typedef uint32_t size_t;

#define true (1)
#define false (0)
#else
#error Unknown target architechture
#endif

#define SECTION(__section__) __attribute__((section, __section__))

#define ARRAY_ELEMENTS(__array__) (sizeof(__array__) / sizeof(__array__[0]))

#define DIVIDE_RND_UP(__value__, __round__)     (((__value__) + (__round__)-1) / (__round__))
#define DIVIDE_RND_DOWN(__value__, __round__)   ((__value__) / (__round__))

typedef union {
    uint64_t u64;

    struct
    {
        uint8_t pad[2];
        uint8_t u8[6];
    } oct;

    struct
    {
        uint32_t u32[2];
    } word;
} mac_t;

#endif /* !TYPES_H */
