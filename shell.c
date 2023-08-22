#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    size_t buf_size = 0;
    char *buf = NULL;
    char *token;
    int status, i = 0;
    char **array;
    pid_t child_pid;

    while (1)
    {
        write(1, "#cisfun$ ", 9); // Show shell prompt
        getline(&buf, &buf_size, stdin); // Input user input
        token = strtok(buf, " \t\n"); // Tokenize input_command
        array = malloc(sizeof(char *) * 1024); // Allocate memory (command arguments)

        while (token)
        {
            array[i] = token;
            token = strtok(NULL, " \t\n");
            i++;
        }
        array[i] = NULL; // Set last element of the array to NULL for execvp
        child_pid = fork(); // Create a child_process

        if (child_pid == 0)
        {
            if (execve(array[0], array, NULL) == -1) // Execute the command
            {
                perror("Error executing command");
                exit(1); // Exit the child process with an error status
            }
        }
        else
        {
            wait(&status); // Wait for the child_process to finish
        }

        // Clean up
        i = 0;
        free(array);
        buf = NULL; // Set buf to NULL after freeing
    }

    return 0;
}
