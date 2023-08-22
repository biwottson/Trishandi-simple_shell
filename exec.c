#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * main - Running "echo" using execve
 *
 * Return: Always 0.
 */
int main(void)
{
    char *argv[] = {"echo", "Hello, execve!", NULL}; // Command and its arguments
    char *envv[] = {NULL}; // Environment variables

    printf("Before execve\n");

    // Execute the "echo" command
    if (execve("/bin/echo", argv, envv) == -1)
    {
        perror("Error:"); // Print an error message if execve fails
        return EXIT_FAILURE; // Return with an error code
    }

    // Won't run after successful execve
    printf("After execve\n");

    return (0);
}
