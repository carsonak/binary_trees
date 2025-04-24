#include "binary_trees.h"

typedef void delete_func(binary_tree_t *);

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
dln *create_node(binary_tree_t *const data)
{
	dln *node = calloc(1, sizeof(*node));

	if (node)
		node->data = data;

	return (node);
}

/**
 * binary_tree_levelorder - walk a binary tree in level order travesal.
 * @tree: a pointer to the root node of the tree.
 * @print_data: a function that prints data in each tree node.
 */
void binary_tree_levelorder(binary_tree_t *const tree, void (*print_data)(int))
{
	deque tree_nodes = {0, NULL, NULL};

	if (!tree || !print_data)
		return;

	if (!dq_push_tail(&tree_nodes, create_node(tree)))
		return;

	while (tree_nodes.size)
	{
		size_t i = 0, prev_size = tree_nodes.size;

		for (i = 0; i < prev_size; ++i)
		{
			binary_tree_t *node = tree_nodes.head->data;

			print_data(node->n);
			if (node->left &&
				!dq_push_tail(&tree_nodes, create_node(node->left)))
			{
				dq_delete(&tree_nodes, NULL);
				return;
			}

			if (node->right &&
				!dq_push_tail(&tree_nodes, create_node(node->right)))
			{
				dq_delete(&tree_nodes, NULL);
				return;
			}

			dq_pop_head(&tree_nodes, NULL);
		}
	}
}
