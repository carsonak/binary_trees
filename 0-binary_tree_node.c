#include "binary_trees.h"

/**
 * binary_tree_node - create a new binary tree node.
 * @parent: pointer to the parent node for the new node.
 * @value: data for the node.
 *
 * Return: pointer to the new node, NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *const parent, const int value)
{
	binary_tree_t *node = calloc(1, sizeof(*node));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	return (node);
}
