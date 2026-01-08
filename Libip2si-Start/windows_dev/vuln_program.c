#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

char pass[] = "\x79\x19\x49\x58\x19\x5E";

void secret_admin_panel() {
    printf("[-] YOU ARE ADMIN! Shell spawned.\n");
    printf("[-] (Simulation d'un shell cmd.exe...)\n");
    ExitProcess(0);
}

void check_password() {
    char buffer[16];
    int is_admin = 0;

    printf("Enter password: ");

    gets(buffer);

    for (size_t i = 0; i < strlen(buffer); i++) {
        buffer[i] ^= 0x24;
    }

    if (strcmp(buffer, pass) == 0) {
        is_admin = 1;
    }

    if (is_admin) {
        secret_admin_panel();
    } else {
        printf("Access Denied.\n");
    }
}

int main() {
    check_password();
    return 0;
}
