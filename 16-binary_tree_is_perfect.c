#include "binary_trees.h"

/**
 * _tree_height - calculate height of a binary tree.
 * @tree: pointer to the root node of the binary tree.
 *
 * height = number of links between root node and farthest leaf node.
 *
 * Return: height of node.
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

	return (height_right > height_left ? height_right : height_left);
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

/**
 * binary_tree_is_perfect - check is a binary tree is perfect.
 * @tree: root node of the tree to check.
 *
 * A perfect binary tree is full and has all leaf nodes on the same level.
 *
 * Return: 1 if tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *const tree)
{
	if (binary_tree_is_full(tree))
	{
		return (
			binary_tree_balance(tree) == 0 &&
			binary_tree_balance(tree->left) == 0 &&
			binary_tree_balance(tree->right) == 0
		);
	}

	return (0);
}
