#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate a binary tree node right.
 * @tree: pointer to the root node to rotate.
 *
 * Return: the new root after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *l = NULL;

	if (!tree)
		return (NULL);

	l = tree->left;
	if (l)
	{
		/* move node l.right to tree.left */
		if (l->right)
			l->right->parent = tree;

		tree->left = l->right;
		/* move node l to tree.parent */
		l->parent = tree->parent;
		l->right = tree;
	}

	tree->parent = l;
	return (l);
}
