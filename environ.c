#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ; // External references to environment variables

int main(void)
{
    int i = 0; // Initialize Counter

    while (environ[i] != NULL) // Loop through environment variables
    {
        printf("%s", environ[i]); // Print each Environment variable
        i++; // Increment counter
    }
    return 0; // Return 0 = successful_execution
}
