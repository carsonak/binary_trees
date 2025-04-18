#include <inttypes.h>

#include "binary_trees.h"

/**
 * binary_tree_depth - calculate depth of a binary tree.
 * @tree: pointer to starting node.
 *
 * depth = number of links between node and the root node.
 *
 * Return: depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	for (depth = 0; tree->parent; ++depth)
		tree = tree->parent;

	return (depth);
}

/**
 * binary_trees_ancestor - find the lowest common ancestor of two nodes
 * of a binary tree.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: pointer to the lowest common ancestor, NULL if none.
 */
binary_tree_t *
binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ancestor = NULL;
	intmax_t depth_diff = 0;

	if (!first || !second)
		return (NULL);

	depth_diff = binary_tree_depth(first) - binary_tree_depth(second);
	while (depth_diff < 0 && second->parent)
	{
		second = second->parent;
		++depth_diff;
	}

	while (depth_diff > 0 && first->parent)
	{
		first = first->parent;
		--depth_diff;
	}

	while (first && second)
	{
		if (first == second)
		{
			/* Avoiding explicit cast on the return type. */
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
