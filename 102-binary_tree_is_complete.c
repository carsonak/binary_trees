#include "binary_trees.h"

typedef void delete_func(binary_tree_t *);

dln *dq_push_head(deque * const dq, dln * const node);
dln *dq_push_tail(deque * const dq, dln * const node);
dln *dq_pop_head(deque * const dq, delete_func * const free_data);
dln *dq_pop_tail(deque * const dq, delete_func * const free_data);
void dq_delete(deque * const dq, delete_func * const free_data);

/**
 * dq_push_head - add a node to the head of the deque.
 * @dq: pointer to the deque.
 * @node: pointer to the node to be added.
 *
 * Return: pointer to the head of the deque, NULL on failure.
 */
dln *dq_push_head(deque * const dq, dln * const node)
{
	if (!dq || !node)
		return (NULL);

	node->next = dq->head;
	node->prev = NULL;
	if (dq->head)
		dq->head->prev = node;
	else
		dq->tail = node;

	dq->head = node;
	++(dq->size);
	return (node);
}

/**
 * dq_push_tail - add a node to the tail of the deque.
 * @dq: pointer to the deque.
 * @node: pointer to the node to be added.
 *
 * Return: pointer to the tail of the deque, NULL on failure.
 */
dln *dq_push_tail(deque * const dq, dln * const node)
{
	if (!dq || !node)
		return (NULL);

	node->prev = dq->tail;
	node->next = NULL;
	if (dq->tail)
		dq->tail->next = node;
	else
		dq->head = node;

	dq->tail = node;
	++(dq->size);
	return (node);
}

/**
 * dq_pop_head - remove a node from the head of the deque.
 * @dq: pointer to the deque.
 * @free_data: pointer to a function that frees data in a deque node.
 *
 * Return: pointer to the new head of the deque.
 */
dln *dq_pop_head(deque * const dq, delete_func * const free_data)
{
	dln *to_pop = NULL;

	if (!dq || !dq->head)
		return (NULL);

	to_pop = dq->head;
	dq->head = to_pop->next;
	if (to_pop == dq->tail)
	{
		dq->tail = NULL;
		dq->size = 0;
	}

	if (free_data)
		free_data(to_pop->data);

	to_pop->data = NULL;
	to_pop->prev = NULL;
	to_pop->next = NULL;
	free(to_pop);
	if (dq->size > 0)
		--(dq->size);

	return (dq->head);
}

/**
 * dq_pop_tail - remove a node from the tail of the deque.
 * @dq: pointer to the deque.
 * @free_data: pointer to a function that frees data in the node.
 *
 * Return: pointer to the new tail of the deque.
 */
dln *dq_pop_tail(deque * const dq, delete_func * const free_data)
{
	dln *to_pop = NULL;

	if (!dq || !dq->tail)
		return (NULL);

	to_pop = dq->tail;
	dq->tail = to_pop->prev;
	if (to_pop == dq->head)
	{
		dq->head = NULL;
		dq->size = 0;
	}

	if (free_data)
		free_data(to_pop->data);

	to_pop->data = NULL;
	to_pop->prev = NULL;
	to_pop->next = NULL;
	free(to_pop);
	if (dq->size > 0)
		--(dq->size);

	return (dq->tail);
}

/**
 * dq_delete - free all the nodes of a queue.
 * @dq: pointer to the deque.
 * @free_data: pointer to a function that frees data in a deque node.
 */
void dq_delete(deque * const dq, delete_func * const free_data)
{
	dln *prev_node = NULL;

	if (!dq || !dq->head)
		return;

	prev_node = dq->head;
	do {
		dq->head = prev_node->next;
		prev_node->next = NULL;
		prev_node->prev = NULL;
		if (free_data)
			free_data(prev_node->prev->data);

		free(prev_node);
		prev_node = dq->head;
	} while (dq->head);

	dq->tail = NULL;
	dq->size = 0;
}

/**
 * create_node - initialise a node.
 * @data: pointer to data to be added.
 *
 * Return: pointer to the created node.
 */
dln *create_node(binary_tree_t * const data)
{
	dln *node = calloc(1, sizeof(*node));

	if (node)
		node->data = data;

	return (node);
}

/**
 * binary_tree_is_complete - check if a binary tree is complete.
 * @tree: a pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(binary_tree_t * const tree)
{
	unsigned char is_last_node = 0;
	deque tree_nodes = {0, NULL, NULL};

	if (!tree)
		return (0);

	if (!dq_push_head(&tree_nodes, create_node(tree)))
		return (0);

	while (tree_nodes.size)
	{
		size_t i = 0, prev_size = tree_nodes.size;

		for (i = 0; i < prev_size; i++)
		{
			binary_tree_t *node = tree_nodes.head->data;

			if (!is_last_node && !node->left)
				is_last_node = 1;

			if (node->left)
			{
				if (is_last_node ||
					!dq_push_tail(&tree_nodes, create_node(node->left)))
					goto error_cleanup;

				if (!node->right)
					is_last_node = 1;
			}

			if (node->right)
			{
				if (is_last_node ||
					!dq_push_tail(&tree_nodes, create_node(node->right)))
					goto error_cleanup;
			}

			dq_pop_head(&tree_nodes, NULL);
		}
	}

	return (1);
error_cleanup:
	dq_delete(&tree_nodes, NULL);
	return (0);
}
