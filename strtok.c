#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Input string
    char *str = "This is separated word by spaces";
    // Allocate memory for a copy of the string
    char *stc = malloc(sizeof(char) * strlen(str));
    // Delimiter used for tokenization
    char delim[5] = " ";
    // Pointer for token(s)
    char *trunks;
    int i;

    // Copy the original string to stc
    strcpy(stc, str);

    // Get the first token
    trunks = strtok(stc, delim);

    // Iterate through tokens and print them
    while (trunks != NULL) {
        // Print token
        printf("%s\n", trunks);
        // Get next token
        trunks = strtok(NULL, delim);
    }

    // Loop through the characters in the copied string
    for (i = 0; i < 35; i++) {
        // Check if the current character is null terminator
        if (stc[i] == '\0') {
            printf("\\0"); // Print the null terminator_escape_sequence
        } else {
            printf("%c", stc[i]); // Print the character
        }
    }

    // Free the__allocated mem
    free(stc);

    return (0);
}
