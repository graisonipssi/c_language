#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    int env_count = 0;

    while (envp[env_count] != NULL)
	{
        printf("%s\n", envp[env_count]);
        env_count++;
    }

    printf("arguments: %d | environnements: %d\n", argc, env_count);

    return 0;
}
