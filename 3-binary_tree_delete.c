#include "binary_trees.h"

/**
 * binary_tree_delete - free a binary tree data structure.
 * @tree: pointer to the root node of the tree.
 */
void binary_tree_delete(binary_tree_t *const tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;
	free(tree);
}
