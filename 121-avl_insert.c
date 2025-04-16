#include "binary_trees.h"

/**
 * bst_insert - adds an item into a binary search tree.
 * @tree: address of a pointer to the root of a bst.
 * @value: the value to insert.
 *
 * Return: pointer to the newly added node, NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, const int value)
{
	bst_t *new_node = NULL, *parent = NULL;

	if (!tree)
		return (NULL);

	while (*tree && (*tree)->n != value)
	{
		parent = *tree;
		if ((*tree)->n < value)
			tree = &(*tree)->right;
		else if ((*tree)->n > value)
			tree = &(*tree)->left;
	}

	/* Only insert new node if no duplicate was found. */
	if (!(*tree))
		new_node = binary_tree_node(*tree, value);

	if (new_node)
	{
		new_node->parent = parent;
		*tree = new_node;
	}

	return (new_node);
}

/**
 * avl_rebalance - walk up an edited subtree and rebalance it if needed.
 * @root: pointer to the address of the root node of the AVL tree.
 * @edited_node: pointer to the node that has an added or deleted child.
 *
 * Return: pointer to the rebalanced subtree.
 */
static void avl_rebalance(avl_t **const root, avl_t *const edited_node)
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

/**
 * avl_insert - inserts an item into an AVL tree.
 * @tree: address of a pointer to the root of a bst.
 * @value: the value to insert.
 *
 * Return: pointer to the newly added node, NULL on failure.
 */
avl_t *avl_insert(avl_t **const tree, const int value)
{
	avl_t *new_node = NULL;

	if (!tree)
		return (NULL);

	new_node = bst_insert(tree, value);
	if (!new_node)
		return (NULL);

	avl_rebalance(tree, new_node->parent);
	return (new_node);
}
