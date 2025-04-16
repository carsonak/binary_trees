#include "binary_trees.h"

/**
 * avl_rebalance - walk up an edited subtree and rebalance it if needed.
 * @root: pointer to the address of the root node of the AVL tree.
 * @edited_node: pointer to the node that has an added or deleted child.
 *
 * Return: pointer to the rebalanced subtree.
 */
void avl_rebalance(avl_t **const root, avl_t *const edited_node)
{
	avl_t *current = NULL;

	for (current = edited_node; current; current = current->parent)
	{
		int balance = binary_tree_balance(current);
		avl_t **parent_link = NULL;

		if (abs(balance) < 2)
			continue;

		if (!current->parent)
			parent_link = root;
		else
		{
			if (current->parent->right == current)
				parent_link = &current->parent->right;
			else
				parent_link = &current->parent->left;
		}

		if (balance < 0) /* Sub-tree is right heavy. */
		{
			/* If right child is left heavy, rotate it right to maintain BST. */
			if (binary_tree_balance(current->right) > 0)
				current->right = binary_tree_rotate_right(current->right);

			*parent_link = binary_tree_rotate_left(current);
		}
		else
		{
			/* If left child is right heavy, rotate it left to maintain BST. */
			if (binary_tree_balance(current->left) < 0)
				current->left = binary_tree_rotate_left(current->left);

			*parent_link = binary_tree_rotate_right(current);
		}

		break;
	}
}
