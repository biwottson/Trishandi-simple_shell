<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

/**
 * display_prompt - Display the shell prompt.
 */
void display_prompt(void);

/**
 * check_command - Check if a command exists in PATH.
 * @command: The command to check.
 * @path: The PATH environment variable.
 * Return: Full path of the command if found, NULL otherwise.
 */
char *check_command(const char *command, const char *path);

/**
 * shell_exit - EIT_FAILURE);
        }

        if (read_bytes == 0)
        {
            printf("\n");
            shell_exit(); // Exit on Ctrl+D
        }

        if (buffer[read_bytes - 1] == '\n')
        {
            buffer[read_bytes - 1] = '\0';
        }

    xit the shell.
 */
void shell_exit(void);

/**
 * shell_env - Display the current environment.
 * @envp: The environment variables.
 */
void shell_env(char *envp[]);

int main(void)
{
    char buffer[BUFFER_SIZE];
    char *args[BUFFER_SIZE / 2];
    ssize_t read_bytes;
    int status;
    extern char **environ;

    while (1)
    {
        display_prompt();

        read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);

        if (read_bytes == -1)
        {
            perror("read");
            exit(EX    char *token = strtok(buffer, " ");
        int arg_count = 0;

        while (token != NULL)
        {
            args[arg_count] = token;
            token = strtok(NULL, " ");
            arg_count++;
        }

        args[arg_count] = NULL;

        if (arg_count > 0)
        {
            if (strcmp(args[0], "exit") == 0)
            {
                shell_exit(); // Exit if the command is "exit"
            }
            else if (strcmp(args[0], "env") == 0)
            {
                shell_env(environ); // Display environment if the command is "env"
            }

            char *command_path = check_command(args[0], getenv("PATH"));

            if (command_path != NULL)
            {
                pid_t pid = fork();

                if (pid == -1)
                {
                    perror("       fprintf(stderr, "%s: not found\n", args[0]);
            }
        }
    }

    return EXIT_SUCCESS;
}

void display_prompt(void)
{
    printf(":) ");
}

char *check_command(const char *command, const char *path)
{
    char *token, *path_copy;
    cfork");
                    exit(EXIT_FAILURE);
                }

                if (pid == 0)
                {
                    if (execve(command_path, args, environ) == -1)
                    {
                        perror("execve");
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    wait(&status);
                }
                free(command_path);
            }
            else
            {
         har *full_path = NULL;
    int path_len, command_len;

    if (command == NULL || path == NULL)
        return NULL;

    path_copy = strdup(path);
    if (path_copy == NULL)
        return NULL;

    command_len = strlen(command);
    token = strtok(path_copy, ":");

    while (token != NULL)
    {
        path_len = strlen(token);
        full_path = malloc(path_len + command_len + 2); // 2 for '/' and null terminator

        if (full_path == NULL)
        {
            free(path_copy);
            return NULL;
        }

        strcpy(full_path, token);
        strcat(full_path, "/");
        strcat(full_path, command);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

void shell_exit(void)
{
    printf("Exiting the shell.\n");
    exit(EXIT_SUCCESS);
}

void shell_env(char *envp[])
{
    int i = 0;
    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
}
