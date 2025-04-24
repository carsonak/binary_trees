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
	bst_t *parent = NULL, **node_address = tree;

	if (!tree)
		return (NULL);

	/* Search for where to insert the new node. */
	while ((*node_address) && (*node_address)->n != value)
	{
		parent = (*node_address);
		if (value > (*node_address)->n)
			node_address = &(*node_address)->right;
		else if (value < (*node_address)->n)
			node_address = &(*node_address)->left;
	}

	/* Only insert new node if no duplicate was found. */
	if (*node_address)
		return (NULL);

	*node_address = binary_tree_node(parent, value);
	if (!(*node_address))
		return (NULL);

	return (*node_address);
}
