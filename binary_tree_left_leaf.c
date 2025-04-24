#include "binary_trees.h"

/**
 * _is_leaf - check if a binary tree node is a leaf.
 * @node: pointer to a node.
 *
 * leaf node: a node with no children.
 *
 * Return: 1 if node is leaf, 0 otherwise.
 */
static unsigned char _is_leaf(const binary_tree_t *const node)
{
	if (node && !node->left && !node->right)
		return (1);

	return (0);
}

/**
 * binary_tree_left_leaf - return the left most leaf node in a binary tree.
 * @root: pointer to the root node of a binary tree.
 *
 * If the tree has no left child, the left most leaf node on the right subtree
 * is returned. This applies recursively until a leaf node is found.
 * Due to this, the left most leaf node might also be the right most leaf node
 * for a tree whose nodes all lack left children.
 *
 * Return: pointer to the left most leaf node.
 */
binary_tree_t *binary_tree_left_leaf(binary_tree_t *root)
{
	if (!root)
		return (NULL);

	while (_is_leaf(root) == 0)
	{
		if (root->left)
			root = root->left;
		else
			root = root->right;
	}

	return (root);
}
