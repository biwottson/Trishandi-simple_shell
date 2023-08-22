#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(const char *name)
{
    extern char **environ;
    int i;
    char *token;

    i = 0;
    while (environ[i])
    {
        token = strtok(environ[i], "=");
        if (token != NULL && strcmp(token, name) == 0)
        {
            return strtok(NULL, "=");
        }
        i++;
    }
    return NULL; // Environment variable not found.
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
    char *homevalue = _getenv("HOME"); // Retrieve HOME environment variable

    if (homevalue != NULL)
    {
        printf("%s\n", homevalue); // Print the value if found
    }
    else
    {        printf("HOME environment variable not set.\n"); // Handle not found
    }

    return (0); // Return success
}

