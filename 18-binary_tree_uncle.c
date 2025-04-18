#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a binary tree node.
 * @node: the node.
 *
 * Return: pointer to the sibling node, NULL if no sibling.
 */
binary_tree_t *binary_tree_sibling(const binary_tree_t *const node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->right)
		return (node->parent->left);

	return (node->parent->right);
}

/**
 * binary_tree_uncle - find the uncle of a binary tree node.
 * @node: the node.
 *
 * uncle node = sibling of parent node.
 *
 * Return: pointer to the uncle node, NULL if no uncle.
 */
binary_tree_t *binary_tree_uncle(const binary_tree_t *const node)
{
	if (!node)
		return (NULL);

	return (binary_tree_sibling(node->parent));
}
