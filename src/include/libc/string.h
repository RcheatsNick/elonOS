#ifndef STRING_H
#define STRING_H

#include <libc/stdint.h>

void *memset(void *s, int c, size_t n);
char *itoa(int val, char *buf, int base);
int strlen(const char *s);
int printf(const char *format, ...);
int strcmp(const char *s1, const char *s2);
char *strtok(s, delim);

#endif // STRING_H
