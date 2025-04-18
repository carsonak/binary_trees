#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	int array[] = {79, 47, 68, 87, 84, 91, 21, 32,
				   34, 2,  20, 22, 98, 1,  62, 95};
	bst_t *node;
	bst_t *root = array_to_bst(array, sizeof(array) / sizeof(array[0]));

	if (!root)
		return (1);

	binary_tree_print(root);
	node = bst_search(root, 32);
	printf("Found: %d\n", node->n);
	binary_tree_print(node);
	node = bst_search(root, 512);
	printf("Node should be nil -> %p\n", (void *)node);

	binary_tree_delete(root);
	return (0);
}
