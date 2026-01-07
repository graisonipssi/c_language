#ifndef IP2SI_H
#define IP2SI_H

#include <stddef.h>

typedef struct s_student {
    char *name;
    int age;
    char *group;
    struct s_student *next;
} t_student;

void ip_putchar(char c);

void ip_swap(int *a, int *b);
void ip_putnbr(int nb);
void *ip_memset(void *s, int c, size_t n);
void *ip_memcpy(void *dest, const void *src, size_t n);
int *ip_range(int min, int max);
char *ip_strdup(char *src);
void ip_init_student(t_student *student, char *name, int age, char *group);
int ip_is_elf(char *file_header);

int     ip_iterative_factorial(int nb);
int     ip_pow(int nb, int power);
char    *simple_xor(char *str, char key);

void    ip_file_info(char *filename);
void    ip_cat(char *filename);
void    ip_cp(char *src, char *dest);
void    ip_crypt_file(char *filename, char key);

#endif
