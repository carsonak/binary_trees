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
 * btree_depth - calculate depth of a binary tree.
 * @tree: root node to start calculating from.
 *
 * Return: depth of the node.
 */
size_t btree_depth(const binary_tree_t *tree)
{
	return (btree_depth_rec(tree, 0));
}

/**
 * binary_trees_ancestor - find the lowest common ancestors of two nodes.
 * @first: the first node.
 * @second: the second node.
 *
 * Return: pointer to the lowest common ancestor, NULL if none.
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ancestor = NULL;
	long int depth_diff = 0;

	depth_diff = btree_depth(first) - btree_depth(second);
	if (depth_diff < 0)
	{
		while (depth_diff < 0 && second)
		{
			second = second->parent;
			depth_diff++;
		}
	}
	else if (depth_diff > 0)
	{
		while (depth_diff > 0 && first)
		{
			first = first->parent;
			depth_diff--;
		}
	}

	while (first && second)
	{
		if (first == second)
		{
			if (first->left)
				ancestor = first->left->parent;
			else
				ancestor = first->right->parent;

			return (ancestor);
		}

		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}
