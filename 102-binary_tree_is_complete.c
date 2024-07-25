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

	node->next = d->head;
	node->prev = NULL;
	if (d->head)
		d->head->prev = node;
	else
		d->tail = node;

	d->head = node;
	d->size++;
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

	node->prev = d->tail;
	node->next = NULL;
	if (d->tail)
		d->tail->next = node;
	else
		d->head = node;

	d->tail = node;
	d->size++;
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
	dll *p = NULL;

	if (!d || !d->head)
		return (NULL);

	p = d->head;
	d->head = p->next;
	if (p == d->tail)
	{
		d->tail = NULL;
		d->size = 0;
	}

	if (free_data)
		(*free_data)(p->data);

	free(p);
	if (d->size)
		d->size--;

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
	dll *p = NULL;

	if (!d || !d->tail)
		return (NULL);

	p = d->tail;
	d->tail = p->prev;
	if (p == d->head)
	{
		d->head = NULL;
		d->size = 0;
	}

	if (free_data)
		(*free_data)(p->data);

	free(p);
	if (d->size)
		d->size--;

	return (d->tail);
}

/**
 * delete_deque - free all the nodes of a queue.
 * @d: pointer to an object like deque.
 * @free_data: pointer to a function that frees data in a deque node.
 */
static void delete_deque(deque *d, void (*free_data)(void *))
{
	dll *p = NULL;

	if (!d || !d->head)
		return;

	p = d->head;
	while (p->next)
	{
		p = p->next;
		if (free_data)
			(*free_data)(p->prev->data);

		free(p->prev);
	}

	if (free_data)
		(*free_data)(p->data);

	free(p);
	d->head = NULL;
	d->tail = NULL;
	d->size = 0;
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
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	unsigned char is_last_node = 0;
	size_t i = 0, prev = 0;
	binary_tree_t *data = NULL;
	deque btree_dq = {0, NULL, NULL, push_head, push_tail,
					  pop_head, pop_tail, delete_deque};

	if (!tree)
		return (0);

	if (!btree_dq.push_head(&btree_dq, create_node((void *)tree)))
		return (0);

	while (btree_dq.size)
	{
		prev = btree_dq.size;
		for (i = 1; i <= prev; i++)
		{
			data = btree_dq.head->data;
			if (!is_last_node && !data->left)
				is_last_node = 1;

			if (data->left)
			{
				if (is_last_node ||
					!btree_dq.push_tail(&btree_dq, create_node(data->left)))
					goto cleanup_return0;

				if (!data->right)
					is_last_node = 1;
			}

			if (data->right)
			{
				if (is_last_node ||
					!btree_dq.push_tail(&btree_dq, create_node(data->right)))
					goto cleanup_return0;
			}

			btree_dq.pop_head(&btree_dq, NULL);
		}
	}

	return (1);
cleanup_return0:
	btree_dq.delete_deque(&btree_dq, NULL);
	return (0);
}
