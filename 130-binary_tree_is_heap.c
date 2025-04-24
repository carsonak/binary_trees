#include "binary_trees.h"

typedef void delete_func(const binary_tree_t *);

/**
 * dq_push_head - add a node to the head of the deque.
 * @dq: pointer to the deque.
 * @node: pointer to the node to be added.
 *
 * Return: pointer to the head of the deque, NULL on failure.
 */
dln_v *dq_push_head(deque_v * const dq, dln_v *const node)
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
dln_v *dq_push_tail(deque_v * const dq, dln_v *const node)
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
dln_v *dq_pop_head(deque_v * const dq, delete_func * const free_data)
{
	dln_v *to_pop = NULL;

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
 * dq_delete - free all the nodes of a queue.
 * @dq: pointer to the deque.
 * @free_data: pointer to a function that frees data in a deque node.
 */
void dq_delete(deque_v * const dq, delete_func * const free_data)
{
	dln_v *prev_node = NULL;

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
dln_v *create_node(const binary_tree_t *const data)
{
	dln_v *node = calloc(1, sizeof(*node));

	if (node)
		node->data = data;

	return (node);
}

/**
 * binary_tree_is_heap - check if a binary tree is a valid Max Binary Heap.
 * @tree: a pointer to the root node of the tree.
 *
 * A max binary heap:
 * Is a complete tree.
 * Has every node greater than all it's descendants.
 *
 * Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *const tree)
{
	unsigned char is_last_node = 0;
	deque_v tree_nodes = {0, NULL, NULL};

	if (!tree)
		return (0);

	if (!dq_push_head(&tree_nodes, create_node(tree)))
		return (0);

	while (tree_nodes.size > 0)
	{
		size_t i = 0, prev_size = tree_nodes.size;

		for (i = 0; i < prev_size; i++)
		{
			const binary_tree_t *node = tree_nodes.head->data;

			if (!is_last_node && !node->left)
				is_last_node = 1;

			if (node->left)
			{
				if (is_last_node || node->n < node->left->n ||
					!dq_push_tail(&tree_nodes, create_node(node->left)))
					goto error_cleanup;

				if (!node->right)
					is_last_node = 1;
			}

			if (node->right)
			{
				if (is_last_node || node->n < node->right->n ||
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
