#include "binary_trees.h"

/**
 * binary_tree_preorder - traverse a binary tree in pre-order.
 * @tree: root node of the tree.
 * @func: function that prints node data.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	(*func)(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
