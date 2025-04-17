#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	int array[] = {79, 47, 68, 87, 84,  91, 21, 32, 34,
				   2,  20, 22, 98, 100, 1,  62, 95, 96};
	bst_t *tree = array_to_bst(array, sizeof(array) / sizeof(array[0]));

	if (!tree)
		return (1);

	binary_tree_print(tree);

	tree = bst_remove(tree, 79); /* Root node. */
	printf("Removed 79...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 21); /* Successor is right.left. */
	printf("Removed 21...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 68); /* Successor is left. */
	printf("Removed 68...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 20); /* No successor. */
	printf("Removed 20...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 87); /* Successor is right. */
	printf("Removed 87...\n");
	binary_tree_print(tree);

	/* Successor is right.left, but it has a right child */
	tree = bst_remove(tree, 91);
	printf("Removed 91...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 98); /* Successor is right leaf node. */
	printf("Removed 98...\n");
	binary_tree_print(tree);

	binary_tree_delete(tree);
	bst_remove(NULL, 1);
	return (0);
}
