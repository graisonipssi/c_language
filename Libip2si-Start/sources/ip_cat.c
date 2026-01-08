#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ip2si.h"

void ip_cat(char *filename) {
    int fd;
    char buffer[4096];
    ssize_t bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read);
    }

    close(fd);
}
