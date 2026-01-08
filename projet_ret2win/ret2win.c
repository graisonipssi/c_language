#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Fonction "win" à atteindre
void win_function() {
    printf("\n🎉 SUCCÈS! Fonction win() exécutée!\n");
    setreuid(geteuid(), geteuid());
    system("/bin/sh");
    exit(0); // Quitter proprement
}

// Fonction vulnérable
void vulnerable_function(char *input) {
    char buffer[64];  // Buffer de 64 octets

    printf("Buffer @ %p\n", buffer);
    printf("win_function @ %p\n", win_function);

    strcpy(buffer, input);  // VULN: copie sans vérification

    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    printf("=== Programme pédagogique ret2win ===\n");
    printf("Objectif: Overflow buffer pour exécuter win_function()\n\n");

    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        printf("Exemple: %s $(python -c 'print \"A\"*76 + \"\\xad\\xbe\\xef\\x00\"')\n", argv[0]);
        return 1;
    }

    vulnerable_function(argv[1]);

    printf("\nÉchec: Retour normal à main()\n");
    return 0;
}
