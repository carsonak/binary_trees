#include "binary_trees.h"

/**
 * binary_tree_is_full - check if binary tree is a full binary tree.
 * @tree: root node of the binary tree.
 *
 * Return: 1 if full binary tree, 0 ohterwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree || (tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
		return (1);

	return (0);
}
