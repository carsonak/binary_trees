#include "binary_trees.h"

/**
 * bstsearch - searches a binary search tree for value.
 * @tree: pointer to the root node of the tree.
 * @value: the value to search for.
 *
 * Return: pointer to the node with the value, NULL otherwise.
 */
static bst_t *bstsearch(const bst_t *tree, int value)
{
	while (tree && tree->n != value)
	{
		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
	}

	return ((bst_t *)tree);
}

/**
 * btree_delete - free a binary tree data structure.
 * @tree: root node of the tree.
 */
static void btree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	btree_delete(tree->left);
	btree_delete(tree->right);
	free(tree);
}

/**
 * array_to_bst - convert an array into a binary search tree.
 * @array: pointer to the array.
 * @size: number of elements in the array.
 *
 * Return: pointer to the root node of the bst, NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i = 0;

	if (!array || !size)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		if (!bst_insert(&tree, array[i]) && !bstsearch(tree, array[i]))
		{
			btree_delete(tree);
			return (NULL);
		}
	}

	return (tree);
}
