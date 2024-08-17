#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	bst_t *tree;
	int array[] = {
		79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
		20, 22, 98, 1, 62, 95};
	int array2[] = {
		98, 110, 43, 56, 2, 78, 123, 76, 234};

	tree = array_to_bst(array, sizeof(array) / sizeof(array[0]));
	if (!tree)
		return (1);
	binary_tree_print(tree);

	tree = bst_remove(tree, 79);
	printf("Removed 79...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 21);
	printf("Removed 21...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 68);
	printf("Removed 68...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 20);
	printf("Removed 20...\n");
	binary_tree_print(tree);
	binary_tree_delete(tree);

	tree = array_to_bst(array2, sizeof(array2) / sizeof(array2[0]));
	if (!tree)
		return (1);
	binary_tree_print(tree);

	tree = bst_remove(tree, 43);
	printf("Removed 43...\n");
	binary_tree_print(tree);
	binary_tree_delete(tree);
	return (0);
}
