#include <stdio.h>
#include <string.h>

/**
 * _strtok - Splits a string into words using a delimiter.
 * @str: The input string to be split.
 * @delimiter: The character used as the delimiter.
 */
void _strtok(const char *str, char delimiter)
{
    int len = strlen(str);
    char word[len + 1];
    int j = 0; // Counter for the current word

    for (int i = 0; i < len; i++) {
        if (str[i] == delimiter || str[i] == '\0') {
            word[j] = '\0'; // Null-terminate the current word
            if (j > 0) {
                printf("%s\n", word); // Print the word if it's not empty
                j = 0; // Reset the counter
            }
        } else {
            word[j] = str[i];
            j++;
        }
    }
}

int main(void)
{
    const char *input = "This is a test string";
    const char delimiter = ' '; // Delimiter character

    _strtok(input, delimiter);

    return 0;
}
