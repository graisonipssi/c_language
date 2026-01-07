#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "ip2si.h"

void ip_cp(char *src, char *dest) {
    int fd_src, fd_dest;
    char buffer[4096];
    ssize_t bytes_read;

    fd_src = open(src, O_RDONLY);
    if (fd_src == -1) {
        perror("Error opening source");
        return;
    }

    fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_dest == -1) {
        perror("Error opening destination");
        close(fd_src);
        return;
    }

    while ((bytes_read = read(fd_src, buffer, sizeof(buffer))) > 0) {
        write(fd_dest, buffer, bytes_read);
    }

    close(fd_src);
    close(fd_dest);
}
