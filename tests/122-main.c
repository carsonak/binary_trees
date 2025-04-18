#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree;
	const int array[] = {79, 47, 68, 87, 84, 91, 21, 32,
						 34, 2,  20, 22, 98, 1,  62, 95};
	const int array2[] = {98, 98, 110, 43, 56, 2, 78, 123, 123, 76, 234};

	tree = array_to_avl(array, sizeof(array) / sizeof(array[0]));
	if (!tree)
		return (1);

	binary_tree_print(tree);
	binary_tree_delete(tree);
	printf("\n\n");

	tree = array_to_avl(array2, sizeof(array2) / sizeof(array2[0]));
	if (!tree)
		return (1);

	binary_tree_print(tree);
	binary_tree_delete(tree);
	return (0);
}
