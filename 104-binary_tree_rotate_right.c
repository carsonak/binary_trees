#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate a binary tree node right.
 * @tree: pointer to the node to rotate.
 *
 * Return: the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *const tree)
{
	binary_tree_t *left_node = NULL;

	if (!tree)
		return (NULL);

	left_node = tree->left;
	if (left_node)
	{
		/* move node left_node.right to tree.left */
		if (left_node->right)
			left_node->right->parent = tree;

		tree->left = left_node->right;
		/* move node left_node to tree.parent */
		left_node->parent = tree->parent;
		left_node->right = tree;
	}

	tree->parent = left_node;
	return (left_node);
}
