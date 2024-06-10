#include "lists.h"

/**
 * This file contains the implementation of the function is_palindrome,
 * which checks if a linked list is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return (1);
	}

	int size = 0;
	listint_t *current = *head;

	while (current != NULL)
	{
		size++;
		current = current->next;
	}

	int arr[size];

	current = *head;
	for (int i = 0; i < size; i++)
	{
		arr[i] = current->n;
		current = current->next;
	}

	for (int i = 0, j = size - 1; i < j; i++, j--)
	{
		if (arr[i] != arr[j])
		{
			return (0);
		}
	}

	return (1);
}
