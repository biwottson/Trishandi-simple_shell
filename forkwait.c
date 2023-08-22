#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t child_id;
    int stat;
    int x;

    char *cmds[] = {"ls", "-l", "/tmp", NULL};

    for (x = 1; x <= 5; x++)
    {
        child_id = fork();
        if (child_id == -1)
        {
            perror("Err:");
            return (1);
        }
        else if (child_id == 0)
        {
            execve("/usr/bin/ls", cmds, NULL);
            perror("Err:");
            exit(1);
        }
        else
        {
            /* Par */
            wait(&stat);
        }
    }

    return (0);
}
