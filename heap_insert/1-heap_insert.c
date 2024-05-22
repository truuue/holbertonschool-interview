#include "binary_trees.h"

/**
 * height - measures the height of a tree
 *
 * @tree: tree root
 * Return: height
 */
int height(const binary_tree_t *tree)
{
	/* Initialize left and right heights */
	int left = 0;
	int right = 0;

	/* If tree is NULL, return -1 */
	if (tree == NULL)
		return (-1);

	/* Recursively calculate the height of the left and right subtrees */
	left = height(tree->left);
	right = height(tree->right);

	/* Return the maximum of the left and right heights, plus 1 for the current node */
	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * btree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: tree root
 * Return: 1 if tree is perfect, 0 otherwise
 */
int btree_is_perfect(const binary_tree_t *tree)
{
	/* Initialize variables */
	_Bool left_is_leaf;
	_Bool right_is_leaf;
	int left_is_perfect;
	int right_is_perfect;

	/* If tree exists and the heights of the left and right subtrees are equal */
	if (tree && height(tree->left) == height(tree->right))
	{
		/* If the tree is a leaf node, return 1 */
		if (height(tree->left) == -1)
			return (1);

		/* Check if the left and right children are leaf nodes */
		left_is_leaf = !((tree->left)->left) && !((tree->left)->right);
		right_is_leaf = !((tree->right)->left) && !((tree->right)->right);

		/* If both children are leaf nodes, return 1 */
		if ((tree->left && left_is_leaf) && (tree->right && right_is_leaf))
			return (1);

		/* If tree and its children exist */
		if (tree && tree->left && tree->right)
		{
			/* Recursively check if the left and right subtrees are perfect */
			left_is_perfect = btree_is_perfect(tree->left);
			right_is_perfect = btree_is_perfect(tree->right);
			/* If both subtrees are perfect, return 1 */
			return (left_is_perfect && right_is_perfect);
		}
	}

	/* If the tree is not perfect, return 0 */
	return (0);
}

/**
 * swap - swaps nodes when child is greater than parent
 *
 * @arg_node: parent node
 * @arg_child: child node
 * Return: no return
 */
void swap(heap_t **arg_node, heap_t **arg_child)
{
	/* Initialize variables */
	heap_t *node, *child, *node_child, *node_left, *node_right, *parent;
	int left_right;

	/* Assign pointers */
	node = *arg_node, child = *arg_child;

	/* If the child's value is greater than the parent's value */
	if (child->n > node->n)
	{
		/* Update parent pointers of child's left and right nodes */
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;

		/* Determine the relationship between node and child (left or right) */
		if (node->left == child)
			node_child = node->right, left_right = 0;
		else
			node_child = node->left, left_right = 1;

		/* Store the left and right nodes of child and node */
		node_left = child->left, node_right = child->right;

		/* Perform the swap based on the relationship between node and child */
		if (left_right == 0)
		{
			child->right = node_child;
			if (node_child)
				node_child->parent = child;
			child->left = node;
		}
		else
		{
			child->left = node_child;
			if (node_child)
				node_child->parent = child;
			child->right = node;
		}

		/* Update parent pointer of child's parent */
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = child;
			else
				node->parent->right = child;
		}

		/* Update parent pointers of parent and child */
		parent = node->parent, child->parent = parent;
		node->parent = child, node->left = node_left;
		node->right = node_right, *arg_node = child;
	}
}

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @value: value to be inserted
 * @root: tree root
 * Return: pointer to the created node, or NULL on failure.
 */
/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @root: double pointer to the root of the heap
 * @value: value to be inserted
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	/* If the root is NULL, create a new node and assign it as the root */
	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* If the tree is perfect or the left subtree is not perfect */
	if (btree_is_perfect(*root) || !btree_is_perfect((*root)->left))
	{
		/* If the left child exists */
		if ((*root)->left)
		{
			/* Recursively insert the value in the left subtree */
			new = heap_insert(&((*root)->left), value);
			swap(root, &((*root)->left));
			return (new);
		}
		else
		{
			/* Create a new node and assign it as the left child */
			new = (*root)->left = binary_tree_node(*root, value);
			swap(root, &((*root)->left));
			return (new);
		}
	}

	/* If the right child exists */
	if ((*root)->right)
	{
		/* Recursively insert the value in the right subtree */
		new = heap_insert(&((*root)->right), value);
		swap(root, (&(*root)->right));
		return (new);
	}
	else
	{
		/* Create a new node and assign it as the right child */
		new = (*root)->right = binary_tree_node(*root, value);
		swap(root, &((*root)->right));
		return (new);
	}

	return (NULL);
}