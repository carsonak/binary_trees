#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a new node as left child of parent.
 * @parent: the parent node of the new node.
 * @value: data for the new node.
 *
 * Return: pointer to the new node, NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);

	if (parent->left)
	{
		node->left = parent->left;
		parent->left->parent = node;
	}

	parent->left = node;
	return (node);
}
