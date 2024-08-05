#include "binary_trees.h"

/**
 * create_avl_node - Creates a new AVL tree node
 *
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_avl_node(avl_t *parent, int value)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

/**
 * build_avl_tree - Recursively builds an AVL tree from sorted array
 *
 * @array: Pointer to the first element of the array
 * @start: Starting index of the array
 * @end: Ending index of the array
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the subtree
 */
avl_t *build_avl_tree(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *root = NULL;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = create_avl_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl_tree(array, start, mid - 1, root);
	root->right = build_avl_tree(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1, NULL));
}
