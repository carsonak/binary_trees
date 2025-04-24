#include "binary_trees.h"

/**
 * BST_insert - adds an item into a binary search tree.
 * @tree: address of a pointer to the root of a bst.
 * @value: the value to insert.
 *
 * Return: pointer to the newly added node, NULL on failure.
 */
bst_t *BST_insert(bst_t **const tree, const int value)
{
	bst_t *parent = NULL, **node_address = tree;

	if (!tree)
		return (NULL);

	/* Search for where to insert the new node. */
	while ((*node_address) && (*node_address)->n != value)
	{
		parent = (*node_address);
		if (value > (*node_address)->n)
			node_address = &(*node_address)->right;
		else if (value < (*node_address)->n)
			node_address = &(*node_address)->left;
	}

	/* Only insert new node if no duplicate was found. */
	if (*node_address)
		return (NULL);

	*node_address = binary_tree_node(parent, value);
	if (!(*node_address))
		return (NULL);

	return (*node_address);
}

/**
 * avl_rebalance_insert - walk up an edited subtree and rebalance it if needed.
 * @root: pointer to the address of the root node of the AVL tree.
 * @edited_node: pointer to the node that has an added or deleted child.
 *
 * Return: pointer to the rebalanced subtree.
 */
void avl_rebalance_insert(avl_t **const root, avl_t *const edited_node)
{
	avl_t *current = NULL;

	for (current = edited_node; current; current = current->parent)
	{
		int balance = binary_tree_balance(current);
		avl_t **node_address = NULL;

		if (abs(balance) < 2)
			continue;

		if (!current->parent)
			node_address = root;
		else
		{
			if (current->parent->right == current)
				node_address = &current->parent->right;
			else
				node_address = &current->parent->left;
		}

		if (balance < 0) /* Sub-tree is right heavy. */
		{
			/* If right child is left heavy, rotate it right to maintain BST. */
			if (binary_tree_balance(current->right) > 0)
				current->right = binary_tree_rotate_right(current->right);

			*node_address = binary_tree_rotate_left(current);
		}
		else
		{
			/* If left child is right heavy, rotate it left to maintain BST. */
			if (binary_tree_balance(current->left) < 0)
				current->left = binary_tree_rotate_left(current->left);

			*node_address = binary_tree_rotate_right(current);
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

	new_node = BST_insert(tree, value);
	if (!new_node)
		return (NULL);

	avl_rebalance_insert(tree, new_node->parent);
	return (new_node);
}
