#include <stddef.h>

void *ip_memset(void *s, int c, size_t n) {
    unsigned char *ptr = (unsigned char *)s;
    size_t i = 0;

    while (i < n) {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return (s);
}
