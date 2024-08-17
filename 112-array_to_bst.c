#include "binary_trees.h"
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
		if (!bst_insert(&tree, array[i]))
		{
			btree_delete(tree);
			return (NULL);
		}
	}

	return (tree);
}
