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
 * btree_printlevel - print all nodes in the current level of a tree.
 * @node: a pointer to the root node of the tree.
 * @level: an int indicating the level to print.
 * @printer: a pointer to a function used to print data of a node.
 */
static void btree_printlevel(const binary_tree_t *node, size_t level, void (*printer)(int))
{
	if (!node || !level || !printer)
		return;

	if (level == 1)
	{
		(*printer)(node->n);
		return;
	}

	btree_printlevel(node->left, level - 1, printer);
	btree_printlevel(node->right, level - 1, printer);
}

/**
 * binary_tree_levelorder - walk a binary tree in level order travesal.
 * @tree: a pointer to the root node of the tree.
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = btree_height(tree) + 1;
	for (i = 1; i <= height; i++)
		btree_printlevel(tree, i, func);
}
