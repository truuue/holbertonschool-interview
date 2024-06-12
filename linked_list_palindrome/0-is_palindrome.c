#include "lists.h"

/**
 * is_palindrome - vérifie si une liste chaînée est un palindrome
 * @head: pointeur vers le pointeur du premier noeud de la liste listint_t
 * Return: 0 si ce n'est pas un palindrome, 1 si c'est un palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *prev = NULL, *next;

	if (*head == NULL)
		return (1);

	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		next = slow->next;
		slow->next = prev;
		prev = slow;
		slow = next;
	}

	if (fast != NULL)
		slow = slow->next;

	while (prev != NULL && prev->n == slow->n)
	{
		slow = slow->next;
		prev = prev->next;
	}

	return (prev == NULL);
}
