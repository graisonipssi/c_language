#include "ip2si.h"
#include <unistd.h>
#include <stdio.h>

void ip_hexdump(void *addr, int len) {
    unsigned char *pc = (unsigned char*)addr;
    char buffer[17];
    unsigned char zero = 0;
    int i, j;

    for (i = 0; i < len; i += 16) {

        for (j = 0; j < 16; j++) {
            if (i + j < len) {
                printf("%02x ", pc[i + j]);
            } else {
                printf("   ");
            }
        }

        printf(" |");

        for (j = 0; j < 16; j++) {
            if (i + j < len) {
                unsigned char c = pc[i + j];
                if (c >= 32 && c <= 126) printf("%c", c);
                else printf(".");
            }
        }
        printf("|\n");
    }
}
