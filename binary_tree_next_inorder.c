#include "binary_trees.h"

/**
 * binary_tree_next_inorder - get the next in order node.
 * @starting_node: pointer to the starting node.
 *
 * Return: pointer to the next in order node,
 * NULL if there is no next in-order node.
 */
binary_tree_t *binary_tree_next_inorder(binary_tree_t *const starting_node)
{
	binary_tree_t *node = NULL;

	if (!starting_node)
		return (NULL);

	if (!starting_node->right)
	{
		/* Retrace steps up the tree to the first left branch off. */
		binary_tree_t *prev_node = starting_node;

		node = starting_node->parent;
		while (node)
		{
			if (node->left == prev_node)
				break;

			prev_node = node;
			node = node->parent;
		}
	}
	else
	{
		node = starting_node->right;
		while (node->left)
			node = node->left;
	}

	return (node);
}
