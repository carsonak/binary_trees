#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse a binary tree in post-order.
 * @tree: root node of the tree.
 * @func: function that prints node data.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	(*func)(tree->n);
}
