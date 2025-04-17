#include "binary_trees.h"

#define INT_IS_ODD(int_to_test) (int_to_test % 2)

/**
 * split_merge_to_tree - recursively split the array into halves adding nodes
 * to the tree in a pre-order fashion.
 * @parent: pointer to the parent of the current node being created.
 * @array: pointer to the first element of the array.
 * @size: number of elements in the array.
 *
 * Return: pointer to the current node being created.
 */
avl_t *split_merge_to_tree(
	avl_t *const parent, const int *const array, const size_t size
)
{
	avl_t *tree = NULL;
	size_t mid_point = 0, left_size = 0, right_size = 0;

	if (!array || size < 1)
		return (NULL);

	mid_point = size / 2;
	if (INT_IS_ODD(size))
		++mid_point;

	right_size = size - mid_point;
	left_size = right_size;
	if (INT_IS_ODD(size) == 0)
		--left_size;

	tree = binary_tree_node(parent, array[mid_point - 1]);
	tree->left = split_merge_to_tree(tree, array, left_size);
	tree->right = split_merge_to_tree(tree, &array[mid_point], right_size);
	return (tree);
}

/**
 * sorted_array_to_avl - convert a sorted array to an avl tree.
 * @array: pointer to the first element of the array.
 * @size: number of elements in the array.
 *
 * The array must be sorted.
 *
 * Return: pointer to the root node of the avl tree.
 */
avl_t *sorted_array_to_avl(const int *const array, const size_t size)
{
	if (!array || size < 1)
		return (NULL);

	return (split_merge_to_tree(NULL, array, size));
}
