#include <unistd.h>

void ip_putchar(char c) {
    write(1, &c, 1);
}

void ip_putnbr(int nb) {
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }

    if (nb < 0) {
        ip_putchar('-');
        nb = -nb;
    }

    if (nb >= 10) {
        ip_putnbr(nb / 10);
    }
    ip_putchar((nb % 10) + '0');
}
