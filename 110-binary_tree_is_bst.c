#include "binary_trees.h"

/**
 * is_bst - traverses a binary tree to check if it is a bst.
 * @tree: root node of the tree.
 * @min: mininum value of a node.
 * @max: maximum value of a node.
 *
 * Return: 1 if the tree is a bst, 0 otherwise.
 */
static int is_bst(const binary_tree_t *tree, const int *min, const int *max)
{
	if (!tree)
		return (1);

	if (min && tree->n <= *min)
		return (0);

	if (max && tree->n >= *max)
		return (0);

	return (is_bst(tree->left, min, &tree->n) &&
			is_bst(tree->right, &tree->n, max));
}

/**
 * binary_tree_is_bst - check if a binary tree is a binary search tree.
 * @tree: root node of the binary tree.
 *
 * Return: 1 if the tree is a bst, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, NULL, NULL));
}
