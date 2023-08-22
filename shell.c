#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> // Include sys/wait.h for the wait() function

#define BUFFER_SIZE 1024

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void);

int main(void)
{
    char buffer[BUFFER_SIZE]; // Buffer to store user input
    char *command;           // Pointer to the command to execute
    ssize_t read_bytes;
    int status; // Store the status of child process

    while (1)
    {
        display_prompt();

        // Read user input
        read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);

        if (read_bytes == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        if (read_bytes == 0) // End of File (Ctrl+D)
        {
            printf("\n");
            break;
        }

        // Remove trailing newline
        if (buffer[read_bytes - 1] == '\n')
        {
            buffer[read_bytes - 1] = '\0';
        }

        // Execute the command
        command = buffer;
        if (access(command, X_OK) == 0)
        {
            pid_t pid = fork();

            if (pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (pid == 0)
            {
                // Child process
                if (execve(command, NULL, NULL) == -1)
                {
                    perror("execve"); // This will only be reached if execve fails
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                // Parent process
                wait(&status); // Wait for the child process to finish
            }
        }
        else
        {
            fprintf(stderr, "%s: command not found\n", command);
        }
    }

    return EXIT_SUCCESS;
}

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
    printf("#cisfun$ ");
}

