
#ifndef PORT_STRING_H
#define PORT_STRING_H

#include <types.h>

void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

size_t strlen(const char *s);
int strncmp(const char *s1, const char *s2, size_t n);

char *strchr(const char *s, int c);
int strcmp(const char *s1, const char *s2);

#endif /* PORT_STRING_H */
