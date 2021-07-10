#include <string.h>

int memcmp (const void *m1,
    const void *m2,
    size_t n)
{
    unsigned char *s1 = (unsigned char *) m1;
    unsigned char *s2 = (unsigned char *) m2;

    while (n--)
    {
        if (*s1 != *s2)
        {
            return *s1 - *s2;
        }

        s1++;
        s2++;
    }

    return 0;
}

void *memcpy (void *__restrict dst0,
    const void *__restrict src0,
    size_t len0)
{
    char *dst = (char *) dst0;
    char *src = (char *) src0;

    void *save = dst0;

    while (len0--)
    {
        *dst++ = *src++;
    }

    return save;
}

void *memset (void *m,
    int c,
    size_t n)
{
    char *s = (char *) m;

    while (n--)
    {
        *s++ = (char) c;
    }

    return m;
}
size_t strlen(const char *s)
{
    size_t count = 0;
    while (*s)
    {
        s++;
        count++;
    }

    return count;
}

int strncmp (const char *s1,
    const char *s2,
    size_t n)
{
    if (n == 0)
        return 0;

    while (n-- != 0 && *s1 == *s2)
    {
        if (n == 0 || *s1 == '\0')
            break;

        s1++;
        s2++;
    }

    return (*(unsigned char *) s1) - (*(unsigned char *) s2);
}


int strcmp (const char *s1,
    const char *s2)
{
    while (*s1 != '\0' && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return (*(unsigned char *) s1) - (*(unsigned char *) s2);
}

char *strchr (const char *s1,
    int i)
{
    const unsigned char *s = (const unsigned char *)s1;
    unsigned char c = i;

    while (*s && *s != c)
    {
        s++;
    }

    if (*s == c)
    {
        return (char *)s;
    }

    return (void*)0;
}
