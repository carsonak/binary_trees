#include "binary_trees.h"

typedef void delete_func(binary_tree_t *);

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
	do
	{
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
 * heap_get_bottom - return all nodes in the deepest complete level of a
 * binary tree.
 * @root: pointer to the root node of the binary heap tree.
 *
 * Assumes `root` is a complete binary tree.
 *
 * Return: pointer to a queue of the nodes from left to right, NULL on failure.
 */
static deque heap_get_bottom(heap_t * const root)
{
	deque current_level = {0}, next_level = {0};
	unsigned char is_last_level = 0;

	if (!root)
		return (current_level);

	if (!dq_push_tail(&next_level, create_node(root)))
		goto error_cleanup;

	while (is_last_level == 0)
	{
		dln *walk = NULL;

		dq_delete(&current_level, NULL);
		current_level = next_level;
		memset(&next_level, 0, sizeof(next_level));
		walk = current_level.head;
		while (walk && is_last_level == 0)
		{
			binary_tree_t *node = walk->data;

			if (!node->left)
				is_last_level = 1;
			else if (!dq_push_tail(&next_level, create_node(node->left)))
				goto error_cleanup;

			if (is_last_level == 0)
			{
				if (!node->right)
					is_last_level = 1;
				else if (!dq_push_tail(&next_level, create_node(node->right)))
					goto error_cleanup;
			}

			walk = walk->next;
		}
	}

	if (is_last_level == 0)
	{
error_cleanup:
		dq_delete(&current_level, NULL);
		memset(&current_level, 0, sizeof(current_level));
	}

	dq_delete(&next_level, NULL);
	return (current_level);
}
