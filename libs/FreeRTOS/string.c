#include <string.h>


void *memcpy(void *dest, const void *src, size_t n)
{
    char *pDest = dest;
    const char *pSrc = src;
    while (n)
    {
        *pDest = *pSrc;
        pDest++;
        pSrc++;
        --n;
    }

    return dest;
}

void *memset(void *s, int c, size_t n)
{
    const char byte = (char)c;
    char *pDest = s;
    while (n)
    {
        *pDest = byte;
        pDest++;
        --n;
    }

    return s;
}
