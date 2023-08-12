#include <stdio.h>

/**
 * sum - Calculate the sum of two integers
 * @a: The first integer
 * @b: The second integer
 *
 * Return: The sum of the two integers
 */
int sum(int a, int b)
{
return (a + b);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int num1, num2, result;
num1 = 5;
num2 = 7;
result = sum(num1, num2);
printf("The sum of %d and %d is %d\n", num1, num2, result);
return (0);
}
