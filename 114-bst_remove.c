#include "binary_trees.h"

/**
 * next_inorder - get the next in order node.
 * @root: pointer to the starting node.
 *
 * Return: pointer to the next in order node.
 */
static bst_t *next_inorder(bst_t *root)
{
	if (!root || !root->left)
		return (root);

	return (next_inorder(root->left));
}

/**
 * bstsearch - searches a binary search tree for value.
 * @tree: pointer to the root node of the tree.
 * @value: the value to search for.
 *
 * Return: pointer to the node with the value, NULL otherwise.
 */
static bst_t *bstsearch(const bst_t *tree, int value)
{
	while (tree && tree->n != value)
	{
		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
	}

	return ((bst_t *)tree);
}

/**
 * bst_remove - deletes a node from a binary tree.
 * @root: pointer to the root node of the tree.
 * @value: value to delete.
 *
 * Return: new root node of the tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *successor = NULL, *to_delete = bstsearch(root, value);

	if (!to_delete)
		return (root);

	if (to_delete->right)
	{
		successor = next_inorder(to_delete->right);
		/* Pop successor from its original position. */
		if (successor->right)
			successor->right->parent = successor->parent;

		successor->parent->left = successor->right;
		/* Update left and right nodes of the node to be deleted. */
		if (to_delete->left)
			to_delete->left->parent = successor;

		to_delete->right->parent = successor;
		/* Update successor's pointers . */
		successor->left = to_delete->left;
		successor->right = to_delete->right;
	}
	else
		successor = to_delete->left;

	successor->parent = to_delete->parent;
	/* Update the parent node. */
	if (to_delete->parent)
	{
		if (to_delete->parent->left == to_delete)
			to_delete->parent->left = successor;
		else
			to_delete->parent->right = successor;
	}
	else
		root = successor;

	free(to_delete);
	return (root);
}
