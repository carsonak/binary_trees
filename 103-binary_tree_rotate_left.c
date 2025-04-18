#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate a binary tree node left.
 * @tree: pointer to the node to rotate.
 *
 * Return: the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *const tree)
{
	binary_tree_t *right_node = NULL;

	if (!tree)
		return (NULL);

	right_node = tree->right;
	if (right_node)
	{
		/* move node right_node.left to tree.right */
		if (right_node->left)
			right_node->left->parent = tree;

		tree->right = right_node->left;
		/* move node right_node to tree.parent */
		right_node->parent = tree->parent;
		right_node->left = tree;
	}

	tree->parent = right_node;
	return (right_node);
}
