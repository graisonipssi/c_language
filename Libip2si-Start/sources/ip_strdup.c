#include <stdlib.h>

char *ip_strdup(char *src) {
    int len = 0;
    int i = 0;

    while (src[len])
        len++;

    char *dest = (char *)malloc(sizeof(char) * (len + 1));

    if (dest == NULL)
        return (NULL);

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return (dest);
}
