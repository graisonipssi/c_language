#ifndef STUDENT_H
#define STUDENT_H

typedef struct s_student {
    char *name;
    int age;
    char *group;
    struct s_student *next;
} t_student;

#endif
