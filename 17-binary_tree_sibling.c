#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a binary tree node.
 * @node: the node.
 *
 * Return: pointer to the sibling node, NULL if node is NULL or parent is NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->right)
		return (node->parent->left);

	return (node->parent->right);
}
