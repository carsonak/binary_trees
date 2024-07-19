#include "binary_trees.h"

/**
 * binary_tree_node - create a new binary tree node.
 * @parent: parent node for the new node.
 * @value: data for the node.
 *
 * Return: pointer to the new node, NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = calloc(1, sizeof(*node));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	if (parent)
	{
		if (!parent->left)
			parent->left = node;
		else if (!parent->right)
			parent->right = node;
		else
		{
			free(node);
			node = NULL;
		}
	}

	return (node);
}
