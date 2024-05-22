#include "binary_trees.h"

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 *
 * @root: Pointer to the root of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;
	heap_t *current = NULL;

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);
	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}
	current = *root;
	while (current)
	{
		parent = current;
		if (current->n < value)
			current = current->right;
		else
			current = current->left;
	}
	new_node->parent = parent;
	if (parent->n < value)
		parent->right = new_node;
	else
		parent->left = new_node;
	return (new_node);
}
