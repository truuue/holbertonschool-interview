#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

#include <stdlib.h>

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
void binary_tree_print(const binary_tree_t *);

int heap_extract(heap_t **root);
size_t size(const heap_t *tree);
size_t size_h(const binary_tree_t *tree);
void order(heap_t *tree, heap_t **node, size_t height);
void heapify(heap_t *root);

#endif /* _BINARY_TREES_H_ */
