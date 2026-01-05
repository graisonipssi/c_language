#include "ip2si.h"
#include <stdio.h>

int main(int argc, char **argv) {
    if (argc > 1) {
        printf("Longueur de l'argument 1 : %d\n", ip_strlen(argv[1]));
        ip_putstr("Affichage via lib: ");
        ip_putstr(argv[1]);
        ip_putchar('\n');
    } else {
        ip_putstr("Aucun argument fourni\n");
    }
    return 0;
}
