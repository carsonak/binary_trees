#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if a binary tree node is a leaf.
 * @node: pointer to a node.
 *
 * leaf node: a node with no children.
 *
 * Return: 1 if node is leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *const node)
{
	if (node && !node->left && !node->right)
		return (1);

	return (0);
}

/**
 * binary_tree_leaves - count the number of leaves in a binary tree.
 * @tree: root of the binary tree.
 *
 * Return: number of leaves counted.
 */
size_t binary_tree_leaves(const binary_tree_t *const tree)
{
	if (!tree)
		return (0);

	if (binary_tree_is_leaf(tree))
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
