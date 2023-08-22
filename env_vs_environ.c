#include <stdio.h>
#include <stdlib.h>

extern char **environ; // Global variable for environment variables.

int main(int argc, char **argv, char **envp) // Main function with argc, argv, and envp parameters.
{
    // Print the addresses of environ (global variable) and env (main function parameter).
    printf("Address of environ (global variable): %p\n", (void*)environ);
    printf("Address of env (main function parameter): %p\n", (void*)envp);

    // Check if environ and env have the same address.
    if (environ == envp) {
        printf("The addresses are the same, which makes sense because environ is a global variable.\n");
    } else {
        printf("The addresses are different, which may be unexpected.\n");
    }

    return 0; // Return 0 = successful execution.
}

