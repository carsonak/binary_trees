#include "../binary_trees.h"

const size_t BUFFER_SIZE_100MAIN = 32;

/**
 * node_tostr - print address and data of a binary tree node.
 * @node: pointer to the node.
 * @buf: pointer to a memory area that will be used to store the string.
 *
 * Return: pointer to the modified buffer.
 */
char *node_tostr(const binary_tree_t *const node, char *const buf)
{
	int pointer_str_len =
		snprintf(buf, BUFFER_SIZE_100MAIN, "(%p)", (void *)node);

	if (node)
		snprintf(
			&buf[pointer_str_len], BUFFER_SIZE_100MAIN - pointer_str_len,
			"->%d", node->n
		);

	return (buf);
}

/**
 * launch_test - Test ancestor function and print informations
 *
 * @n1: First node
 * @n2: Second node
 */
void launch_test(binary_tree_t *n1, binary_tree_t *n2)
{
	binary_tree_t *ancestor = binary_trees_ancestor(n1, n2);
	char buf[BUFFER_SIZE_100MAIN];

	printf("Ancestor of %s &", node_tostr(n1, buf));
	printf(" %s:\n", node_tostr(n2, buf));
	printf("%s\n\n", node_tostr(ancestor, buf));
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *tree2 = binary_tree_node(NULL, 1024);
	binary_tree_t *root = binary_tree_node(NULL, 98);

	tree2->right = binary_tree_node(tree2, 4096);

	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	root->left->right = binary_tree_node(root->left, 54);
	root->right->right = binary_tree_node(root->right, 128);
	root->left->left = binary_tree_node(root->left, 10);
	root->right->left = binary_tree_node(root->right, 69420);
	root->right->right->left = binary_tree_node(root->right->right, 92);
	root->right->right->right = binary_tree_node(root->right->right, 7);

	printf("First tree...\n");
	binary_tree_print(root);
	printf("Second tree...\n");
	binary_tree_print(tree2);
	printf("\n");

	launch_test(
		root->left, root->right
	); /* Ancestor is root, depth is the same. */
	launch_test(root->right->left, root->right->right->right);
	/* Ancestor is the first node, depth differs. */
	launch_test(root->right->right, root->right->right->right);
	/* Ancestor is the second node, depth differs. */
	launch_test(root->right->right->right, root->right->right);
	/* Ancestor is root, depth differs. */
	launch_test(root->left->right, root->right->right->left);
	launch_test(root->left, tree2->right); /* Nodes on separate trees. */

	/* Root vs root. */
	launch_test(root, tree2); /* No ancestor, separate trees, root nodes */
	launch_test(root, root);  /* Ancestor is itself. */

	/* NULLs */
	launch_test(NULL, NULL);
	launch_test(NULL, root->left->right); /* First is NULL. */
	launch_test(root->left->right, NULL); /* Second is NULL. */

	binary_tree_delete(root);
	binary_tree_delete(tree2);
	return (0);
}
