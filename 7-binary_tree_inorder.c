#include "binary_trees.h"

/**
 * binary_tree_inorder - traverse a binary tree in in-order.
 * @tree: root node of the tree.
 * @func: function that prints node data.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	(*func)(tree->n);
	binary_tree_inorder(tree->right, func);
}
