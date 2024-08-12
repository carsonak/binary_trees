#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate a binary tree node left.
 * @tree: pointer to the root node to rotate.
 *
 * Return: the new root after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *r = NULL;

	if (!tree)
		return (NULL);

	r = tree->right;
	if (r)
	{
		/* move node r.left to tree.right */
		if (r->left)
			r->left->parent = tree;

		tree->right = r->left;
		/* move node r to tree.parent */
		r->parent = tree->parent;
		r->left = tree;
	}

	tree->parent = r;
	return (r);
}
