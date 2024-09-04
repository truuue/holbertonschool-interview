#include "sort.h"
/**
 * heap_sort - sorts an array of ints in asc order using Heap sort algorithm
 * @array: array
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (!array)
	{
		return;
	}

	for (i = size / 2; i > 0; i--) /* build max heap */
	{
		heapify(array, size, i - 1, size); /* heapify */
	}

	for (i = size - 1; i > 0; i--) /* swap root with last node */
	{
		swap(&array[0], &array[i], array, size); /* swap */
		heapify(array, i, 0, size); /* heapify */
	}
}
/**
 * heapify - organizes the array into max heap
 * @arr: array
 * @n: size
 * @i: index
 * @size: original size
 */
void heapify(int *arr, int n, int i, size_t size)
{
	int higher = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[higher]) /* left child is higher */
	{
		higher = left;
	}

	if (right < n && arr[right] > arr[higher]) /* right child is higher */
	{
		higher = right;
	}

	if (higher != i) /* if higher is not the root */
	{
		swap(&arr[i], &arr[higher], arr, size); /* swap */
		heapify(arr, n, higher, size);
		/* recursively heapify the affected sub-tree */
	}
}
/**
 * swap - swap pointer position
 * @a: pointer to swap
 * @b: pointer to swap
 * @array: array
 * @n: size of array
 */
void swap(int *a, int *b, int *array, size_t n)
{
	int aux = *a;
	*a = *b;
	*b = aux;
	print_array(array, n);
}
