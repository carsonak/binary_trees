#include "binary_trees.h"

/**
 * binary_tree_nodes - count number of internal nodes in a binary tree.
 * @tree: root node to start from.
 *
 * Return: the number of internal nodes counted.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);

	return (0);
}
