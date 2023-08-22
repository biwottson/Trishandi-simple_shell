++;
        }
        return (NULL); // Not found
	}

/**
 *  * main - Program entry point.
 *   */
int main(void)
{
	        char *homevalue = _getenv("HOME"); // Get HOME env

		        if (homevalue != NULL) // Check if found
				  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - Get environment variable value.
 */
char *_getenv(const char *name)
{
        extern char **environ; // Access environment
        int i;
        char *token;

        i = 0;
        while (environ[i])
        {
                token = strtok(environ[i], "="); // Split env string
                if (strcmp(token, name) == 0) // Compare names
                {
                        return (strtok(NULL, "=")); // Return value      {
                printf("%s\n", homevalue); // Print value
        }
        else
        {
                printf("HOME not found.\n"); // Handle not found
        }

        return (EXIT_SUCCESS); // Return success
}
