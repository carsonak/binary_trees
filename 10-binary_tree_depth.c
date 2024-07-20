#include "binary_trees.h"

/**
 * btree_depth_rec - calculate depth of a node in a binary tree recursively.
 * @node: the node to calculate depth for.
 * @depth: starting point for the depth.
 *
 * Return: depth calculated.
 */
static size_t btree_depth_rec(const binary_tree_t *node, size_t depth)
{
	if (!node || !node->parent)
		return (depth);

	return (btree_depth_rec(node->parent, depth + 1));
}

/**
 * binary_tree_depth - calculate depth of a binary tree.
 * @tree: root node to start calculating from.
 *
 * Return: depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return (btree_depth_rec(tree, 0));
}
