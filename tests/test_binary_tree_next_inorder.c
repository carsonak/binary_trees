#include "../binary_trees.h"

binary_tree_t *binary_tree_next_inorder(binary_tree_t *const root);

/**
 * main - test binary_tree_next_inorder.
 *
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	const int array[] = {7, 2, 1, 4, 3, 5, 6, 9, 8, 15, 11, 10, 13, 12, 14};
	bst_t *tree = array_to_bst(array, sizeof(array) / sizeof(*array));
	bst_t *inorder_next = NULL;

	if (!tree)
		return (1);

	binary_tree_print(tree);
	inorder_next = tree->left->left;
	while (inorder_next)
	{
		printf("%d", inorder_next->n);
		inorder_next = binary_tree_next_inorder(inorder_next);
		if (inorder_next)
			printf(" -> ");
	}

	binary_tree_delete(tree);
	return (0);
}
