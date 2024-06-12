#include "lists.h"

/**
 * is_palindrome - vérifie si une liste chaînée est un palindrome
 * @head: pointeur vers le pointeur du premier noeud de la liste listint_t
 * Return: 0 si ce n'est pas un palindrome, 1 si c'est un palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int len = 0, i;
	int *arr;

	if (*head == NULL)
		return (1);

	while (current != NULL)
	{
		current = current->next;
		len++;
	}

	arr = malloc(len * sizeof(int));
	if (arr == NULL)
		return (0);

	current = *head;
	for (i = 0; i < len; i++)
	{
		arr[i] = current->n;
		current = current->next;
	}

	for (i = 0; i < len / 2; i++)
	{
		if (arr[i] != arr[len - i - 1])
		{
			free(arr);
			return (0);
		}
	}

	free(arr);
	return (1);
}
