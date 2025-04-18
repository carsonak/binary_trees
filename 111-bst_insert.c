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
	bst_t *new_node = NULL, *walk = NULL, *parent = NULL, **parent_link = tree;

	if (!tree)
		return (NULL);

	/* Search for where to insert the new node. */
	walk = *tree;
	while (walk && walk->n != value)
	{
		parent = walk;
		if (walk->n < value)
		{
			parent_link = &walk->right;
			walk = walk->right;
		}
		else if (walk->n > value)
		{
			parent_link = &walk->left;
			walk = walk->left;
		}
	}

	/* Only insert new node if no duplicate was found. */
	if (walk)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	*parent_link = new_node;
	return (new_node);
}
