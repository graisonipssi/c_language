#include "ip2si.h"

int ip_pow(int nb, int power) {
    int res;

    if (power < 0) return (0);
    if (power == 0) return (1);

    res = 1;
    while (power > 0) {
        res = res * nb;
        power--;
    }
    return (res);
}
