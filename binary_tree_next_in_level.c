#include "binary_trees.h"

/**
 * binary_tree_next_in_level - return the next node in the level of the
 * given node.
 * @node: pointer to a binary tree node.
 *
 * The level is traversed left to right starting from the given node.
 *
 * Return: pointer to the next node in the level, NULL if not found.
 */
binary_tree_t *binary_tree_next_in_level(binary_tree_t *node)
{
	intmax_t height = 0;
	binary_tree_t *parent = NULL;

	if (!node)
		return (NULL);

	parent = node->parent;
	while (parent && parent->right == node)
	{
		++height;
		node = parent;
		parent = node->parent;
	}

	if (!parent)
		return (NULL);

	node = parent->right;
	--height;
	while (node && height > 0)
	{
		if (node->left)
			node = node->left;
		else
			node = node->right;

		--height;
	}

	return (node);
}
