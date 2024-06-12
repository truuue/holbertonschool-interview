#include "lists.h"

/**
 * is_palindrome - vérifie si une liste chaînée est un palindrome
 * @head: pointeur vers le pointeur du premier noeud de la liste listint_t
 * Return: 0 si ce n'est pas un palindrome, 1 si c'est un palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int i, j, len;
	int arr[10];

	if (*head == NULL)
		return (1);

	current = *head;
	len = 0;

	while (current != NULL)
	{
		arr[len] = current->n;
		current = current->next;
		len++;
	}

	for (i = 0, j = len - 1; i < len / 2; i++, j--)
	{
		if (arr[i] != arr[j])
			return (0);
	}

	return (1);
}
