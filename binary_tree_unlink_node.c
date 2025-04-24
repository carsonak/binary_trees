#include "binary_trees.h"

/**
 * binary_tree_unlink_node - unlink a node from a binary tree replacing it with
 * its next in order successor.
 * @to_unlink: pointer to the node to unlink.
 *
 * Return: pointer to the successor node.
 */
binary_tree_t *binary_tree_unlink_node(binary_tree_t *const to_unlink)
{
	binary_tree_t *successor = NULL;

	if (!to_unlink)
		return (NULL);

	if (!to_unlink->right)
		successor = to_unlink->left;
	else
	{
		successor = binary_tree_next_inorder(to_unlink);
		/* Successor does not have a left subtree in this case. */
		if (successor)
		{
			/* Pop successor from its original position. */
			if (successor->right)
				successor->right->parent = successor->parent;

			if (successor == to_unlink->right)
				to_unlink->right = successor->right;
			else
				successor->parent->left = successor->right;

			/* Insert successor over node to be unlinked. */
			successor->left = to_unlink->left;
			successor->right = to_unlink->right;
		}

		/* Update left and right nodes of the node to be unlinked. */
		if (to_unlink->left)
			to_unlink->left->parent = successor;

		if (to_unlink->right)
			to_unlink->right->parent = successor;
	}

	if (successor)
		successor->parent = to_unlink->parent;

	/* Update the parent node. */
	if (to_unlink->parent)
	{
		if (to_unlink->parent->left == to_unlink)
			to_unlink->parent->left = successor;
		else
			to_unlink->parent->right = successor;
	}

	return (successor);
}
