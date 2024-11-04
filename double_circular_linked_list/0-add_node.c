#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node to the end of a double circular linked list
 *
 * @list:the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;
	char *strNode;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	strNode = strdup(str);
	if (!strNode)
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = strNode;

	if (!*list)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
		return (new_node);
	}

	new_node->next = *list;
	new_node->prev = (*list)->prev;

	(*list)->prev = new_node;
	new_node->prev->next = new_node;

	return (new_node);
}
/**
 * add_node_begin - Adds a new node to the beginning of a
 * double circular linked list
 *
 * @list:the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;
	char *strNode;

	if (!list)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	strNode = strdup(str);
	if (!strNode)
	{
		free(new_node);
		return (NULL);
	}
	new_node->str = strNode;

	if (*list)
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev = new_node;
		if (new_node->prev)
			new_node->prev->next = new_node;
	}
	else
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}

	*list = new_node;

	return (new_node);
}
