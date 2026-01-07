#include "ip2si.h"

int ip_iterative_factorial(int nb) {
    long result;
    int i;

    if (nb < 0) return (0);
    if (nb == 0) return (1);

    result = 1;
    i = 1;
    while (i <= nb) {
        result = result * i;
        if (result > 2147483647)
            return (0);
        i++;
    }
    return ((int)result);
}
