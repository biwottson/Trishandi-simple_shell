#include <stdio.h>
#include <stdlib.h>

/**
 * main - start program
 * @argc: Number of CLI arguments
 * @argv: Array of strings containing arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
    /* Print the value of argc */
    printf("argv content is argv[]\n");

    while (*argv != NULL)
    {
        printf("argv = %s\n", *argv);
        argv++;
    }

    /* Return 0 */
    return (0);
}
