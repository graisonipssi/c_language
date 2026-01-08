#include <windows.h>
#include <stdio.h>

unsigned char shellcode[] = {
    0x90, 0x90, 0x90, 0x90, 0xC3
};

int main() {
    void *exec_mem;
    HANDLE th;

    printf("[*] Allocation de memoire executable...\n");
    exec_mem = VirtualAlloc(0, sizeof(shellcode), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

    if (!exec_mem) {
        printf("Erreur VirtualAlloc\n");
        return 1;
    }

    printf("[*] Copie du shellcode...\n");
    RtlMoveMemory(exec_mem, shellcode, sizeof(shellcode));

    printf("[*] Execution via un Thread...\n");
    th = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)exec_mem, 0, 0, 0);

    WaitForSingleObject(th, -1);

    printf("[*] Fin du programme.\n");
    return 0;
}
