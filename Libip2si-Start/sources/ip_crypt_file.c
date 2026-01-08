#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ip2si.h"

void ip_crypt_file(char *filename, char key) {
    char *out_name = malloc(strlen(filename) + 5);
    if (!out_name) return;

    strcpy(out_name, filename);
    strcat(out_name, ".enc");

    int fd_in = open(filename, O_RDONLY);
    int fd_out = open(out_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd_in == -1 || fd_out == -1) {
        perror("File error");
        free(out_name);
        if (fd_in != -1) close(fd_in);
        return;
    }

    char buffer[4096];
    ssize_t ret;
    while ((ret = read(fd_in, buffer, sizeof(buffer))) > 0) {
        for (int i = 0; i < ret; i++) {
            buffer[i] = buffer[i] ^ key;
        }
        write(fd_out, buffer, ret);
    }

    close(fd_in);
    close(fd_out);
    free(out_name);
}
