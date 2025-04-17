#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree;
	int array[] = {79, 47, 68, 87, 84, 91, 21, 32,
				   34, 2,  20, 22, 98, 1,  62, 95};
	int array2[] = {56, 43, 123, 2, 78, 234, 76};

	tree = array_to_avl(array, sizeof(array) / sizeof(array[0]));
	if (!tree)
		return (1);

	printf("Original tree:\n");
	binary_tree_print(tree);

	tree = avl_remove(tree, 1024); /* Remove node that does not exist. */
	printf("Removed 1024...\n");
	binary_tree_print(tree);

	tree = avl_remove(tree, 47); /* Remove root node. */
	printf("Removed 47...\n");
	binary_tree_print(tree);

	/* Remove leaf node on right, BF after: right 2. */
	tree = avl_remove(tree, 79);
	printf("Removed 79...\n");
	binary_tree_print(tree);

	/* Remove node with both children, no grand-children, BF after: left 1. */
	tree = avl_remove(tree, 32);
	printf("Removed 32...\n");
	binary_tree_print(tree);

	/* Remove node with only left child, no grand-children, BF after: left 1. */
	tree = avl_remove(tree, 34);
	printf("Removed 34...\n");
	binary_tree_print(tree);

	tree = avl_remove(tree, 34); /* Double remove. */
	printf("Removed 34...\n");
	binary_tree_print(tree);

	/* Remove leaf node on right, BF after: left 2. */
	tree = avl_remove(tree, 22);
	printf("Removed 22...\n");
	binary_tree_print(tree);

	binary_tree_delete(tree);
	avl_remove(NULL, 87); /* Null tree. */

	tree = array_to_avl(array2, sizeof(array2) / sizeof(array2[0]));
	if (!tree)
		return (1);

	printf("\n\nOriginal tree:\n");
	binary_tree_print(tree);

	/* Remove left heavy parent, BF after: left 2 */
	tree = avl_remove(tree, 123);
	printf("Removed 123...\n");
	binary_tree_print(tree);

	binary_tree_delete(tree);
	return (0);
}
