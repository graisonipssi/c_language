#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

// 64-bit Linux x86_64
// Compilation: gcc -fno-stack-protector -z execstack -no-pie -o grimoire_fixed grimoire_fixed.c

#define CHUNK_SIZE 128

void *active_spell = NULL;

// /!\ Vous n'avez pas besoin de vous interresser à cette fonction /!\
// Configuration de la mémoire pour qu'elle soit exécutable (RWX)
void setup_spell_memory(void *ptr) {
    unsigned long p = (unsigned long)ptr;
    p &= ~(sysconf(_SC_PAGESIZE) - 1);
    mprotect((void *)p, sysconf(_SC_PAGESIZE), PROT_READ | PROT_WRITE | PROT_EXEC);
}

void banner() {
    puts("\n=== THE FORBIDDEN GRIMOIRE (FIXED) ===");
    puts("1. Learn a Spell");
    puts("2. Cast Spell");
    puts("3. Write in Diary");
    puts("4. Exit");
    printf("> ");
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);

    int choice;
    char *diary_page = NULL;
    char buffer[CHUNK_SIZE];

    while (1) {
        banner();
        if (!fgets(buffer, sizeof(buffer), stdin)) break;
        choice = atoi(buffer);

        if (choice == 1) { // 1. Allocation
            if (active_spell) {
                printf("[!] You already know a spell!\n");
                continue;
            }
            active_spell = malloc(CHUNK_SIZE);
            setup_spell_memory(active_spell);
            memset(active_spell, 0xC3, CHUNK_SIZE); // RET instruction
            printf("[+] Spell learned at %p.\n", active_spell);
        }
        else if (choice == 2) { // 2. Exécution
            if (active_spell) {
                printf("[*] Casting spell at %p...\n", active_spell);
                ((void (*)(void))active_spell)(); // CALL
            } else {
                printf("[-] No spell known.\n");
            }
        }
        else if (choice == 3) { // 3. UAF & Remplacement
            printf("Write (%d chars max): ", CHUNK_SIZE);
            diary_page = malloc(CHUNK_SIZE);
            fgets(diary_page, CHUNK_SIZE, stdin);
            
            if (strstr(diary_page, "Voldemort")) {
                printf("[!] CURSED WORD! BURNING PAGES!\n");
                free(diary_page); 
                // LE BUG:
                if (active_spell) free(active_spell); 
            } else {
                printf("[+] Entry saved.\n");
            }
        }
        else if (choice == 4) break;
    }
    return 0;
}
