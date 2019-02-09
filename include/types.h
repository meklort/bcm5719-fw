#ifndef TYPES_H
#define TYPES_H


#define SECTION(__section__)   __attribute__((section, __section__))

#define ARRAY_ELEMENTS(__array__)        (sizeof(__array__)/sizeof(__array__[0]))


typedef union {
    uint64_t u64;

    struct
    {
        uint8_t pad[2];
        uint8_t  u8[6];
    } oct;

    struct
    {
        uint32_t  u32[2];
    } word;
} mac_t;

#endif /* !TYPES_H */
