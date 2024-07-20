#include "binary_trees.h"

/**
 * binary_tree_height - calculate height of a binary tree.
 * @tree: root node to to start calculating from.
 *
 * Return: height of node.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = binary_tree_height(tree->left) + 1;

	if (tree->right)
		height_right = binary_tree_height(tree->right) + 1;

	return (height_left > height_right ? height_left : height_right);
}
