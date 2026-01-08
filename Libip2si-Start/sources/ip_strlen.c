#include "ip2si.h"

int ip_strlen(char *str) {
    int i = 0;
    while (str[i]) {
        i++;
    }
    return i;
}
