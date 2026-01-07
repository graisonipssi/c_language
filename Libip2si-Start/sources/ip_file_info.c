#include <sys/stat.h>
#include <stdio.h>
#include "ip2si.h"

void ip_file_info(char *filename) {
    struct stat sb;

    if (stat(filename, &sb) == -1) {
        printf("Error: Cannot access file\n");
        return;
    }

    printf("Name: %s\n", filename);
    printf("Size: %ld\n", sb.st_size);
    printf("Inode: %ld\n", sb.st_ino);

    printf("Type: ");
    if (S_ISDIR(sb.st_mode)) printf("Directory\n");
    else if (S_ISREG(sb.st_mode)) printf("Regular File\n");
    else if (S_ISLNK(sb.st_mode)) printf("Symbolic Link\n");
    else printf("Other\n");
}
