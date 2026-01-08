#include "ip2si.h"

static int get_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return (0);
}

int ip_atoi(char *str) {
    int res = 0;
    int i = 0;
    int base = 10;

    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        base = 16;
        i = 2;
    } else if (str[0] == '0' && (str[1] == 'b' || str[1] == 'B')) {
        base = 2;
        i = 2;
    }

    while (str[i]) {
        res = res * base + get_val(str[i]);
        i++;
    }
    return (res);
}
