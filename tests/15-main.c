#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int full;

	full = binary_tree_is_full(NULL);
	printf("Is NULL full: %d\n\n", full);

	root = binary_tree_node(NULL, 98);
	binary_tree_print(root);
	full = binary_tree_is_full(root);
	printf("Is %d full: %d\n\n", root->n, full);

	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);
	root->left->left = binary_tree_node(root->left, 10);
	binary_tree_print(root);

	full = binary_tree_is_full(root);
	printf("Is %d full: %d\n", root->n, full);
	full = binary_tree_is_full(root->left);
	printf("Is %d full: %d\n", root->left->n, full);
	full = binary_tree_is_full(root->right);
	printf("Is %d full: %d\n\n", root->right->n, full);

	binary_tree_insert_left(root->left->left, 8);
	binary_tree_insert_right(root->left->left, 17);
	binary_tree_insert_left(root->left->left->left, 4);
	binary_tree_insert_right(root->left->left->left, 15);
	binary_tree_insert_left(root->left->left->right, 12);
	binary_tree_insert_right(root->left->left->right, 28);

	binary_tree_insert_left(root->right, 36);
	binary_tree_insert_right(root->right, 301);
	binary_tree_insert_left(root->right->left, 20);
	binary_tree_insert_right(root->right->left, 44);
	binary_tree_insert_left(root->right->right, 144);
	binary_tree_insert_left(root->right->right, 370);
	binary_tree_insert_left(root->right->right->right, 289);
	binary_tree_insert_right(root->right->right->right, 348);
	binary_tree_insert_left(root->right->right->left, 101);
	binary_tree_insert_right(root->right->right->left, 250);
	binary_tree_print(root);

	full = binary_tree_is_full(root);
	printf("Is %d full: %d\n", root->n, full);
	full = binary_tree_is_full(root->left);
	printf("Is %d full: %d\n", root->left->n, full);
	full = binary_tree_is_full(root->right);
	printf("Is %d full: %d\n", root->right->n, full);
	full = binary_tree_is_full(root->left->left);
	printf("Is %d full: %d\n", root->left->left->n, full);
	return (0);
}
