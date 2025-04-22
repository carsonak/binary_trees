#include "binary_trees.h"

/**
 * _tree_height - calculate height of a binary tree.
 * @tree: pointer to the root node of the binary tree.
 *
 * height = number of links between root node and farthest leaf node.
 *
 * Return: height of the tree.
 */
size_t _tree_height(const binary_tree_t *const tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = _tree_height(tree->left) + 1;

	if (tree->right)
		height_right = _tree_height(tree->right) + 1;

	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_balance - calculate the balance of a binary tree.
 * @tree: pointer to the root of the tree.
 *
 * Balance = Height of left subtree - Height of right subtree.
 *
 * Return: balance of the binary tree.
 */
int binary_tree_balance(const binary_tree_t *const tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = _tree_height(tree->left) + 1;

	if (tree->right)
		height_right = _tree_height(tree->right) + 1;

	return (height_left - height_right);
}
