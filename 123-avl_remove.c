#include "binary_trees.h"

/**
 * BST_search - searches a binary search tree for value.
 * @tree: pointer to the root node of the tree.
 * @value: the value to search for.
 *
 * Return: pointer to the node with the value, NULL otherwise.
 */
bst_t *BST_search(bst_t *tree, const int value)
{
	while (tree && tree->n != value)
	{
		if (value < tree->n)
			tree = tree->left;
		else if (value > tree->n)
			tree = tree->right;
	}

	return (tree);
}

/**
 * binary_tree_next_inorder - get the next in order node.
 * @root: pointer to the starting node.
 *
 * Return: pointer to the next in order node,
 * NULL if there is no next in-order node.
 */
binary_tree_t *binary_tree_next_inorder(binary_tree_t *const root)
{
	binary_tree_t *node = NULL;

	if (!root)
		return (NULL);

	if (!root->right)
	{
		/* Retrace steps up the tree to the first left branch off. */
		binary_tree_t *prev_node = root;

		node = root->parent;
		while (node)
		{
			if (node->left == prev_node)
				break;

			prev_node = node;
			node = node->parent;
		}
	}
	else
	{
		node = root->right;
		while (node->left)
			node = node->left;
	}

	return (node);
}

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
		{ /* Pop successor from its original position. */
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

/**
 * avl_rebalance_remove - walk up an edited subtree and rebalance it if needed.
 * @root: pointer to the address of the root node of the AVL tree.
 * @edited_node: pointer to the node that has an added or deleted child.
 *
 * Return: pointer to the rebalanced subtree.
 */
void avl_rebalance_remove(avl_t **const root, avl_t *const edited_node)
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
 * avl_remove - deletes data from a AVL tree.
 * @root: pointer to the root node of the tree.
 * @value: data to delete.
 *
 * Return: pointer to the root node of the of the edited tree.
 */
avl_t *avl_remove(avl_t *root, const int value)
{
	bst_t *to_delete = NULL;
	bst_t *successor = NULL;

	if (!root)
		return (NULL);

	to_delete = BST_search(root, value);
	if (!to_delete)
		return (root);

	successor = binary_tree_unlink_node(to_delete);
	if (!to_delete->parent)
		root = successor;

	if (successor)
		avl_rebalance_remove(&root, successor);
	else
		avl_rebalance_remove(&root, to_delete->parent);

	free(to_delete);
	return (root);
}
