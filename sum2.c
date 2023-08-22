#include <stdio.h>
#include <stdlib.h>

/**
 * main - start program
 * @argc: Number of CLI arguments
 * @argv: Array of strings containing arguments
 *
 * Return: Sum of the converted integers
 */
int main(int argc, char **argv)
{
    int i;
    int sum = 0;

    /* Print the value of argc */
    printf("argc pr ac = %d\n", argc);
    printf("argv content is argv[]\n");

    for (i = 1; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
        sum += atoi(argv[i]);
    }

    /* Return the sum */
    printf("sum is %d\n", sum);
    return (sum);
}
