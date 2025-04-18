#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <inttypes.h> /* intmax_t */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

#ifndef BINARY_TREES_TYPEDEFS
	#define BINARY_TREES_TYPEDEFS

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

#endif /* BINARY_TREES_TYPEDEFS */

/**
 * struct doubly_linked_node - a doubly linked list node.
 * @next: the next node in the linked list.
 * @prev: the previous node in the linked list.
 * @data: the data the linked list node holds.
 */
typedef struct doubly_linked_node
{
	struct doubly_linked_node *next;
	struct doubly_linked_node *prev;
	binary_tree_t *data;
} dln;

/**
 * struct double_ended_queue - a deque object.
 * @size: number of nodes in the list.
 * @head: a pointer to the head of the queue.
 * @tail: a pointer to the tail of the queue.
 */
typedef struct double_ended_queue
{
	intmax_t size;
	dln *head;
	dln *tail;
} deque;

binary_tree_t *binary_tree_unlink_node(binary_tree_t *const to_unlink);
binary_tree_t *binary_tree_next_inorder(binary_tree_t *const root);

void binary_tree_print(const binary_tree_t *const tree);
binary_tree_t *binary_tree_node(binary_tree_t *const parent, const int value);
binary_tree_t *
binary_tree_insert_left(binary_tree_t *const parent, const int value);
binary_tree_t *
binary_tree_insert_right(binary_tree_t *const parent, const int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *const node);
int binary_tree_is_root(const binary_tree_t *const node);
void binary_tree_preorder(const binary_tree_t *const tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *const tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *const tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *const tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *const tree);
size_t binary_tree_leaves(const binary_tree_t *const tree);
size_t binary_tree_nodes(const binary_tree_t *const tree);
int binary_tree_balance(const binary_tree_t *const tree);
int binary_tree_is_full(const binary_tree_t *const tree);
int binary_tree_is_perfect(const binary_tree_t *const tree);
binary_tree_t *binary_tree_sibling(const binary_tree_t *const node);
binary_tree_t *binary_tree_uncle(const binary_tree_t *const node);
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *const first, const binary_tree_t *const second
);
void binary_tree_levelorder(binary_tree_t *const tree, void (*func)(int));
int binary_tree_is_complete(binary_tree_t *const tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *const tree);
bst_t *bst_insert(bst_t **tree, const int value);
bst_t *array_to_bst(const int *const array, const size_t size);
bst_t *bst_search(bst_t *tree, const int value);
bst_t *bst_remove(bst_t *root, const int value);
int binary_tree_is_avl(const binary_tree_t *const tree);
avl_t *avl_insert(avl_t **const tree, const int value);
avl_t *array_to_avl(const int *const array, const size_t size);
avl_t *avl_remove(avl_t *root, const int value);
avl_t *sorted_array_to_avl(const int *const array, const size_t size);

#endif /* BINARY_TREES_H */
