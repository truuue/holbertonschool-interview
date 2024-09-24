#include "binary_trees.h"

/**
 * heap_extract - heap_extract
 * @root: pointer
 * Return: node
 **/
int heap_extract(heap_t **root)
{
	int val;
	heap_t *h_right, *node;

	if (!root || !*root)
	{
		return (0);
	}

	h_right = *root;
	val = h_right->n;
	if (!h_right->left && !h_right->right)
	{
		*root = NULL;
		free(h_right);
		return (val);
	}

	order(h_right, &node, size(h_right));

	h_right->n = node->n;
	if (node->parent->right)
	{
		node->parent->right = NULL;
	}
	else
	{
		node->parent->left = NULL;
	}
	free(node);
	heapify(h_right);
	*root = h_right;
	return (val);
}


/**
 * heapify - heapify
 * @root: pointer
 */
void heapify(heap_t *root)
{
	int val;
	heap_t *x, *y;

	if (!root)
		return;

	x = root;

	while (1)
	{
		if (!x->left)
			break;
		if (!x->right)
			y = x->left;
		else
		{
			if (x->left->n > x->right->n)
				y = x->left;
			else
				y = x->right;
		}
		if (x->n > y->n)
		{
			break;
		}
		val = x->n;
		x->n = y->n;
		y->n = val;
		x = y;
	}
}

/**
 * order - order
 * @target: pointer
 * @node: node
 * @hei: size
 *
 * Return: val
 */
void order(heap_t *target, heap_t **node, size_t hei)
{
	if (!target)
	{
		return;
	}

	if (!hei)
	{
		*node = target;
	}
	hei--;

	order(target->left, node, hei);
	order(target->right, node, hei);
}

/**
 * size - target hei
 * @target: pointer
 *
 * Return: value
 */
size_t size(const heap_t *target)
{
	size_t h_left = 0, h_right = 0;

	if (!target)
	{
		return (0);
	}

	if (target->left)
	{
		h_left = 1 + size(target->left);
	}

	if (target->right)
	{
		h_right = 1 + size(target->right);
	}

	if (h_left > h_right)
	{
		return (h_left);
	}
	return (h_right);
}
/**
 * size_h - size
 * @target: pointer
 *
 * Return: val
 */
size_t size_h(const binary_tree_t *target)
{
	size_t h_left = 0, h_right = 0;

	if (!target)
	{
		return (0);
	}

	if (target->left)
	{
		h_left = 1 + size_h(target->left);
	}

	if (target->right)
	{
		h_right = 1 + size_h(target->right);
	}

	return (h_left + h_right);
}
