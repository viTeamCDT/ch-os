#ifndef STRING_H
#define STRING_H

#include <types.h>

void *memset (void *dest, char value, size_t count);
void *memcpy (void *dest, const void *src, size_t size);
size_t strlen(const char* str);

#endif
