#include "binary_trees.h"

/**
 * binary_tree_next_inorder - get the next in order node.
 * @root: pointer to the starting node.
 *
 * Return: pointer to the next in order node,
 * NULL if there is no next in-order node.
 */
binary_tree_t *binary_tree_next_inorder(binary_tree_t *const root)
{
	binary_tree_t *node = NULL;

	if (!root)
		return (NULL);

	if (!root->right)
	{
		/* Retrace steps up the tree to the first left branch off. */
		binary_tree_t *prev_node = root;

		node = root->parent;
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
		node = root->right;
		while (node->left)
			node = node->left;
	}

	return (node);
}
