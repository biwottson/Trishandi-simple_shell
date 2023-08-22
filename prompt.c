#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Declare variables
    size_t n = 0; // Initial size of the buffer
    char *buf = NULL; // Pointer to a character buffer

    // Prompt the user for input
    printf("Just Me and Trish ");

    // Read input from the user into the buffer
    getline(&buf, &n, stdin);

    // Print a character
    printf("%s", buf);

    // Free the allocated memory
    free(buf);

    // Return 0 to indicate successful completion
    return 0;
}
