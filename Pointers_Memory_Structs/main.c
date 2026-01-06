#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void ip_swap(int *a, int *b);
void ip_putnbr(int nb);
void *ip_memset(void *s, int c, size_t n);
int *ip_range(int min, int max);
char *ip_strdup(char *src);
void ip_init_student(t_student *student, char *name, int age, char *group);
int ip_is_elf(char *file_header);

int main() {
    int a = 10, b = 20;
    ip_swap(&a, &b);
    printf("Ex00 Swap: a=%d, b=%d (Attendu: 20, 10)\n", a, b);

    printf("Ex01 Putnbr: ");
    ip_putnbr(-42);
    printf("\n");

    int *range = ip_range(5, 8);
    printf("Ex03 Range: %d, %d, %d\n", range[0], range[1], range[2]);
    free(range);

    char elf_header[] = {0x7F, 'E', 'L', 'F', 0x01};
    printf("Ex06 ELF: %d (Attendu: 1)\n", ip_is_elf(elf_header));

    return 0;
}
