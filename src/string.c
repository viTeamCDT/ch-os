#include <string.h>

void *memset (void *dest, char value, size_t count) {
	char *temp = (char*) dest;
	for (; count != 0; count--) *temp++ = value;
	return dest;
}

void *memcpy (void *dest, const void *src, size_t size) {
	const char *sp = (const char*) src;
	char *dp = (char*) dest;
	for (; size != 0; size--) *dp++ = *sp++;
	return dest;
}

size_t strlen(const char* str)
{
	size_t size = 0;
	while (str[size] != '\0')
		size++;
	return size;
}
