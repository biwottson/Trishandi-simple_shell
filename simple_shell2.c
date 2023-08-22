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
    char *args[BUFFER_SIZE / 2]; // Array to store command and arguments
    ssize_t read_bytes;
    int status; // Store the status of the child process

    while (1)
    the command and arguments
        char *token = strtok(buffer, " ");
        int arg_count = 0;

        while (token != NULL)
        {
            args[arg_count] = token;
            token = strtok(NULL, " ");
            arg_count++;
        }

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

        // Tokenize  args[arg_count] = NULL; // Null-terminate the argument list

        // Execute the command
        if (arg_count > 0)
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
                if (execve(args[0], args, NULL) == -1)
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
