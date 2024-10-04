#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * is_digit - Checks if a string contains only digits.
 * @s: The string to check.
 *
 * Return: 1 if all characters are digits, 0 otherwise.
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Calculates the length of a string.
 * @s: The string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _multiply - Multiplies two digits and adds the result to the appropriate position.
 * @num1: The first string of digits.
 * @num2: The second string of digits.
 * @result: The result array.
 */
void _multiply(char *num1, char *num2, int *result)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int i, j, mul, sum;

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = mul + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}
}

/**
 * mul - Multiplies two positive numbers.
 * @num1: The first string of digits.
 * @num2: The second string of digits.
 *
 * Return: The resulting multiplication string.
 */
char *mul(char *num1, char *num2)
{
	int len1 = _strlen(num1);
	int len2 = _strlen(num2);
	int len = len1 + len2;
	int *result;
	char *str;
	int i;
	int start = 0;

	result = malloc(sizeof(int) * len);
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		result[i] = 0;

	_multiply(num1, num2, result);

	/* Allocate the resulting string */
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		free(result);
		return (NULL);
	}

	/* Convert the results to characters */
	for (i = 0; i < len; i++)
		str[i] = result[i] + '0';
	str[len] = '\0';

	free(result);

	/* Remove leading zeros */
	while (str[start] == '0' && start < len - 1)
		start++;

	/* Shift the string to remove leading zeros */
	for (i = 0; i < len - start; i++)
		str[i] = str[i + start];
	str[i] = '\0';

	return (str);
}

/**
 * main - Entry point of the program.
 * @argc: Number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	char *result;
	int i; /* Declaration of 'i' to be used in the for loop */

	if (argc != 3)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	if (!is_digit(argv[1]) || !is_digit(argv[2]))
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	result = mul(argv[1], argv[2]);
	if (result == NULL)
	{
		_putchar('E');
		_putchar('r');
		_putchar('r');
		_putchar('o');
		_putchar('r');
		_putchar('\n');
		exit(98);
	}

	/* Display the result */
	for (i = 0; result[i]; i++)
		_putchar(result[i]);
	_putchar('\n');

	free(result);
	return (0);
}
