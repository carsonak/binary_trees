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
 * btree_balance - calculate the balance of a binary tree.
 * @tree: root of the tree.
 *
 * Return: the calculated balances.
 */
static int btree_balance(const binary_tree_t *tree)
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

/**
 * btree_is_full - check if binary tree is a full binary tree.
 * @tree: root node of the binary tree.
 *
 * Return: 1 if full binary tree, 0 ohterwise.
 */
static int btree_is_full(const binary_tree_t *tree)
{
	if (!tree || (tree->left && !tree->right) || (!tree->left && tree->right))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (btree_is_full(tree->left) && btree_is_full(tree->right))
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
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (btree_balance(tree) == 0)
		return (btree_is_full(tree));

	return (0);
}
