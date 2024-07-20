#include "binary_trees.h"

/**
 * btree_sibling - find the sibling of a binary tree node.
 * @node: the node.
 *
 * Return: pointer to the sibling node, NULL if node or parent is NULL.
 */
static binary_tree_t *btree_sibling(binary_tree_t *node)
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
 * Return: pointer to the uncle node, NULL if node or parent is NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node)
		return (NULL);

	return (btree_sibling(node->parent));
}
