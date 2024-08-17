#include "binary_trees.h"

/**
 * bst_insert - adds an item into a binary search tree.
 * @tree: address of a pointer to the root of a bst.
 * @value: the value to insert into the binary search tree.
 *
 * Return: pointer to the newly added node, NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL, *parent = NULL;

	if (!tree)
		return (NULL);

	while (*tree && (*tree)->n != value)
	{
		parent = *tree;
		if ((*tree)->n < value)
			tree = &(*tree)->right;
		else if ((*tree)->n > value)
			tree = &(*tree)->left;
	}

	/* Ensures no duplicates in the tree */
	if (!(*tree))
		new_node = binary_tree_node(*tree, value);

	if (new_node)
	{
		new_node->parent = parent;
		*tree = new_node;
	}

	return (new_node);
}
