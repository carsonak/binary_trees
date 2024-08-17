#include "binary_trees.h"

/**
 * next_inorder - get the next in order node.
 * @root: pointer to the starting node.
 *
 * Return: pointer to the next in order node.
 */
bst_t *next_inorder(bst_t *root)
{
	if (!root)
		return (NULL);

	if (!root->left)
		return (root);

	return (next_inorder(root->left));
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
	bst_t **node = &root, *to_delete = NULL, *successor = NULL;

	while (*node && (*node)->n != value)
	{
		if (value < (*node)->n)
			*node = (*node)->left;
		else if (value > (*node)->n)
			*node = (*node)->right;
	}

	to_delete = *node;
	if (!to_delete)
		return (root);

	if (to_delete->right)
	{
		successor = next_inorder(to_delete->right);
		/* Pop successor from original position. */
		if (successor->right)
			successor->right->parent = successor->parent;

		successor->parent->left = successor->right;
		/* Update left and right nodes of the node to be deleted. */
		if (to_delete->left)
			to_delete->left->parent = successor;

		to_delete->right->parent = successor;
		/* Replace node to be deleted with the successor. */
		successor->left = to_delete->left;
		successor->right = to_delete->right;
	}
	else
		successor = to_delete->left;

	successor->parent = to_delete->parent;
	*node = successor;
	free(to_delete);
	return (root);
}
