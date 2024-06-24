#include "lists.h"

/**
 * This function prints all the elements of a linked list of type listint_t.
 * It takes a pointer to the head of the list as a parameter.
 * The function does not return anything.
 */
int check_cycle(listint_t *list) {
	listint_t *slow = list;
	listint_t *fast = list;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast) {
			return 1;
		}
	}

	return 0;
}
