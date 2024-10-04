#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * is_digit - checks if a string is composed only of digits.
 * @str: string to check.
 *
 * Return: 1 if string is valid (only digits), 0 otherwise.
 */
int is_digit(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

/**
 * print_error - prints an error message and exits with status 98.
 */
void print_error(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * multiply - multiplies two numbers represented as strings.
 * @num1: first number as a string.
 * @num2: second number as a string.
 *
 * Return: the result of the multiplication as a string.
 */
char *multiply(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int *result = calloc(len1 + len2, sizeof(int));
    char *final_result;
    int i, j, carry, sum, k = 0;

    if (!result)
        print_error();

    /* Perform multiplication like in elementary school */
    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int pos1 = i + j;
            int pos2 = i + j + 1;
            sum = mul + result[pos2];
            result[pos2] = sum % 10;
            result[pos1] += sum / 10;
        }
    }

    /* Convert result to a string */
    final_result = malloc(len1 + len2 + 1);
    if (!final_result)
        print_error();

    for (i = 0; i < len1 + len2; i++)
    {
        if (!(k == 0 && result[i] == 0))
            final_result[k++] = result[i] + '0';
    }
    final_result[k] = '\0';

    free(result);
    return (k == 0) ? strdup("0") : final_result;
}

/**
 * main - multiplies two numbers given as arguments.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: 0 on success, or 98 on error.
 */
int main(int argc, char *argv[])
{
    char *num1, *num2, *result;

    if (argc != 3)
        print_error();

    num1 = argv[1];
    num2 = argv[2];

    if (!is_digit(num1) || !is_digit(num2))
        print_error();

    result = multiply(num1, num2);
    printf("%s\n", result);

    free(result);
    return (0);
}
