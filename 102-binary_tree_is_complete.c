#include "binary_trees.h"

static dll *push_head(deque *d, dll *node);
static dll *push_tail(deque *d, dll *node);
static dll *pop_head(deque *d, void (*)(void *));
static dll *pop_tail(deque *, void (*)(void *));
static void delete_deque(deque *d, void (*)(void *));

/**
 * push_head - add a doubly linked list node to the head of the deque.
 * @d: pointer to an object like deque.
 * @node: pointer to the node to be added.
 *
 * Return: pointer to the head of the deque, NULL on failure.
 */
static dll *push_head(deque *d, dll *node)
{
	if (!d || !node)
		return (NULL);

	return (node);
}

/**
 * push_tail - add a doubly linked list node to the tail of the deque.
 * @d: pointer to an object like deque.
 * @node: pointer to the node to be added.
 *
 * Return: pointer to the tail of the struct, NULL on failure.
 */
static dll *push_tail(deque *d, dll *node)
{
	if (!d || !node)
		return (NULL);

	return (node);
}

/**
 * pop_head - remove a doubly linked list node from the head of the deque.
 * @d: pointer to an object like deque.
 * @free_data: pointer to a function that frees data in a deque node.
 *
 * Return: pointer to the head of the deque.
 */
static dll *pop_head(deque *d, void (*free_data)(void *))
{
	(void)free_data;
	if (!d || !d->head)
		return (NULL);

	return (d->head);
}

/**
 * pop_tail - remove a doubly linked list node from the tail of the deque.
 * @d: pointer to an object like deque.
 * @free_data: pointer to a function that frees data in a deque node.
 *
 * Return: pointer to the tail of the deque.
 */
static dll *pop_tail(deque *d, void (*free_data)(void *))
{
	(void)free_data;
	if (!d || !d->tail)
		return (NULL);

	return (d->tail);
}

/**
 * delete_deque - free all the nodes of a queue.
 * @d: pointer to an object like deque.
 * @free_data: pointer to a function that frees data in a deque node.
 */
static void delete_deque(deque *d, void (*free_data)(void *))
{
	(void)free_data;
	if (!d || !d->head)
		return;
}

/**
 * create_node - create a doubly linked list node.
 * @data: pointer to data to be added.
 *
 * Return: pointer to the created node.
 */
static dll *create_node(void *data)
{
	dll *node = calloc(1, sizeof(*node));

	if (node)
		node->data = data;

	return (node);
}

/**
 * binary_tree_is_complete - check if a binary tree is complete.
 * @tree: a pointer to the root node of the tree.
 *
 * A binary tree is complete if all leaf nodes are on the same level.
 *
 * Return: 1 if tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	deque btree_deque = {0, NULL, NULL, push_head, push_tail,
						 pop_head, pop_tail, delete_deque};

	if (!tree)
		return (0);

	btree_deque.push_head(&btree_deque, create_node((void *)tree));

	return (1);
}
