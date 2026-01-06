#include <stddef.h>
#include "ip2si.h"

void ip_init_student(t_student *student, char *name, int age, char *group) {
    if (student) {
        student->name = name;
        student->age = age;
        student->group = group;
        student->next = NULL;
    }
}
