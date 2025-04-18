#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if a binary tree node is a leaf.
 * @node: pointer to a node.
 *
 * leaf node: a node with no children.
 *
 * Return: 1 if node is leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *const node)
{
	if (node && !node->left && !node->right)
		return (1);

	return (0);
}
