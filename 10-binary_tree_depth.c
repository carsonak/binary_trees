#include "binary_trees.h"

/**
 * binary_tree_depth - calculate depth of a binary tree.
 * @tree: pointer to starting node.
 *
 * depth = number of links between node and the root node.
 *
 * Return: depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	for (depth = 0; tree->parent; ++depth)
		tree = tree->parent;

	return (depth);
}
