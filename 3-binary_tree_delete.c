#include "binary_trees.h"

/**
 * binary_tree_delete - free a binary tree data structure.
 * @tree: root node of the tree.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
