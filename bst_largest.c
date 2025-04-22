#include "binary_trees.h"

/**
 * bst_largest - returns the largest node in a binary search tree.
 * @root: pointer to the root node of the tree.
 *
 * Return: a struct with a pointer to the largest node and its depth.
 */
node_depth bst_largest(const bst_t *root)
{
	node_depth largest = {root, 0};

	if (!root)
		return (largest);

	while (largest.node->right)
	{
		++(largest.depth);
		largest.node = largest.node->right;
	}

	return (largest);
}
