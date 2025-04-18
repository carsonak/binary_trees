#include "binary_trees.h"

/**
 * binary_tree_is_full - check if binary tree is a full binary tree.
 * @tree: pointer to the root node of the binary tree.
 *
 * A full binary tree has all its nodes with either 0 or 2 children.
 *
 * Return: 1 if tree is a full binary tree, 0 ohterwise.
 */
int binary_tree_is_full(const binary_tree_t *const tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->right || !tree->left)
		return (0);

	if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
		return (1);

	return (0);
}
