#include "binary_trees.h"

/**
 * bst_smallest - returns the smallest node in a binary search tree.
 * @root: pointer to the root node of the tree.
 *
 * Return: a struct with a pointer to the smallest node and its depth.
 */
node_depth bst_smallest(const bst_t *root)
{
	node_depth smallest = {root, 0};

	if (!root)
		return (smallest);

	while (smallest.node->left)
	{
		++(smallest.depth);
		smallest.node = smallest.node->left;
	}

	return (smallest);
}
