#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a new node as right child of parent.
 * @parent: the parent node of the new node.
 * @value: data for the new node.
 *
 * Return: pointer to the new node, NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node = NULL;

	if (!parent)
		return (NULL);

	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);

	if (parent->right)
	{
		node->right = parent->right;
		parent->right->parent = node;
	}

	parent->right = node;
	return (node);
}
