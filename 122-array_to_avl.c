#include "binary_trees.h"

/**
 * tree_delete - free a binary tree data structure.
 * @tree: root node of the tree.
 */
static void tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	tree_delete(tree->left);
	tree_delete(tree->right);
	free(tree);
}

/**
 * array_to_avl - convert an array to an AVL tree.
 * @array: pointer to the array of data.
 * @size: length of the array.
 *
 * Return: pointer to the created AVL tree.
 */
avl_t *array_to_avl(const int *const array, size_t size)
{
	avl_t *tree = NULL;

	if (!array || size < 1)
		return (NULL);

	while (size > 0)
	{
		if (!avl_insert(&tree, array[--size]))
		{
			tree_delete(tree);
			return (NULL);
		}
	}

	return (tree);
}
