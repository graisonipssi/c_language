#include <unistd.h>

void ip_putchar(char c) {
    write(1, &c, 1);
}

