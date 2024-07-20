#include "binary_trees.h"

/**
 * binary_tree_size - calculate size of a binary tree.
 * @tree: root node to start from.
 *
 * Return: the number of nodes in the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
