#include "binary_trees.h"

/**
 * btree_height - calculate height of a binary tree.
 * @tree: root node to to start calculating from.
 *
 * Return: height of node.
 */
static size_t btree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = btree_height(tree->left) + 1;

	if (tree->right)
		height_right = btree_height(tree->right) + 1;

	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_balance - calculate the balance of a binary tree.
 * @tree: root of the tree.
 *
 * Balance = Height of left subtree - Height of right subtree.
 *
 * Return: the calculated balances.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = btree_height(tree->left) + 1;

	if (tree->right)
		height_right = btree_height(tree->right) + 1;

	return (height_left - height_right);
}
