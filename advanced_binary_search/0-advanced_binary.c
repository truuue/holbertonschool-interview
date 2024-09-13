#include "search_algos.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 *
 * @array: array
 * @size: array size
 * @value: value to find on array
 *
 * Return: -
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
		return (-1);

	return (binary(array, 0, size - 1, value));
}

/**
 * binary - binary searc
 *
 * @array: array
 * @init: init point
 * @finish: finish point
 * @val: value to find on array
 *
 * Return: -
 */
int binary(int *array, int init, int finish, int val)
{
	int i;
	int middle;

	printf("Searching in array: ");
	for (i = init; i <= finish; i++)
	{
		if (i == finish)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}

	middle = (finish - init) / 2 + init;

	if (init == finish)
	{
		return (-1);
	}
	if (array[middle] == val)
	{
		if (array[middle - 1] == val)
		{
			return (binary(array, init, middle, val));
		}
		return (middle);
	}
	if (array[middle] >= val)
	{
		return (binary(array, init, middle, val));
	}
	if (array[middle] <= val)
	{
		return (binary(array, middle + 1, finish, val));
	}
	return (-1);
}
