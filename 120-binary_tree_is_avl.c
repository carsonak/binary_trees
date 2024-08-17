#include "binary_trees.h"

/**
 * is_bst - traverses a binary tree to check if it is a bst.
 * @tree: root node of the tree.
 * @min: mininum value of a node.
 * @max: maximum value of a node.
 *
 * Return: 1 if the tree is a bst, 0 otherwise.
 */
static int is_bst(const binary_tree_t *tree, const int *min, const int *max)
{
	if (!tree)
		return (1);

	if (min && tree->n <= *min)
		return (0);

	if (max && tree->n >= *max)
		return (0);

	return (is_bst(tree->left, min, &tree->n) &&
			is_bst(tree->right, &tree->n, max));
}

/**
 * btree_height - calculate height of a binary tree.
 * @tree: root node to to start calculating from.
 *
 * Return: height of node.
 */
static size_t btree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = btree_height(tree->left) + 1;

	if (tree->right)
		height_right = btree_height(tree->right) + 1;

	return (height_left > height_right ? height_left : height_right);
}

/**
 * btree_balance - calculate the balance of a binary tree.
 * @tree: root of the tree.
 *
 * Balance = Height of left subtree - Height of right subtree.
 *
 * Return: the calculated balances.
 */
static int btree_balance(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = btree_height(tree->left) + 1;

	if (tree->right)
		height_right = btree_height(tree->right) + 1;

	return (height_left - height_right);
}

/**
 * avl_balanced - checks if a AVL tree is balanced.
 * @tree: pointer to the root of the avl tree.
 * @deviation: the deviation of balance.
 *
 * Return: 1 if AVL tree is balanced, 0 otherwise.
 */
static int avl_balanced(const binary_tree_t *tree, size_t deviation)
{
	if (!tree)
		return (1);

	return (
		(abs(btree_balance(tree)) <= deviation) &&
		avl_balanced(tree->left, deviation) &&
		avl_balanced(tree->right, deviation));
}

/**
 * binary_tree_is_avl - check if a binary tree is a AVL tree.
 * @tree: root node of the binary tree.
 *
 * Properties of a AVL tree:
 * 1. An AVL Tree is a BST.
 * 2. The difference between heights of left and right subtrees cannot be
 * more than one.
 * 3. The left and right subtrees must also be AVL trees
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, NULL, NULL) && avl_balanced(tree, 1));
}
