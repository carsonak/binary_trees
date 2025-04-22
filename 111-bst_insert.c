#include "binary_trees.h"

/**
 * bst_insert - adds an item into a binary search tree.
 * @tree: address of a pointer to the root of a bst.
 * @value: the value to insert.
 *
 * Return: pointer to the newly added node, NULL on failure.
 */
bst_t *bst_insert(bst_t **const tree, const int value)
{
	bst_t *new_node = NULL, *parent = NULL, **parent_link = tree;

	if (!tree)
		return (NULL);

	/* Search for where to insert the new node. */
	new_node = *tree;
	while (new_node && new_node->n != value)
	{
		parent = new_node;
		if (value > new_node->n)
		{
			parent_link = &new_node->right;
			new_node = new_node->right;
		}
		else if (value < new_node->n)
		{
			parent_link = &new_node->left;
			new_node = new_node->left;
		}
	}

	/* Only insert new node if no duplicate was found. */
	if (new_node)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	*parent_link = new_node;
	return (new_node);
}
