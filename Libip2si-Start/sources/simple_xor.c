#include "ip2si.h"

char *simple_xor(char *str, char key) {
    int i = 0;
    while (str[i]) {
        str[i] = str[i] ^ key;
        i++;
    }
    return (str);
}
