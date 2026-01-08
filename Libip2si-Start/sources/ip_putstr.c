#include "ip2si.h"

void ip_putstr(char *str) {
    int i = 0;
    while (str[i]) {
        ip_putchar(str[i]);
        i++;
    }
}
