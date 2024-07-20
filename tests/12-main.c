#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t leaves;

    printf("Leaves of NULL: %lu\n\n", binary_tree_leaves(NULL));

    root = binary_tree_node(NULL, 98);
    binary_tree_print(root);
    printf("Leaves from %d: %lu\n\n", root->n, binary_tree_leaves(root));

    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    leaves = binary_tree_leaves(root);
    printf("Leaves from %d: %lu\n", root->n, leaves);
    leaves = binary_tree_leaves(root->right);
    printf("Leaves from %d: %lu\n", root->right->n, leaves);
    leaves = binary_tree_leaves(root->left->right);
    printf("Leaves from %d: %lu\n\n", root->left->right->n, leaves);

    binary_tree_insert_right(root, 28);
    binary_tree_insert_right(root->right, 666);
    binary_tree_insert_left(root->right, 100);
    binary_tree_insert_left(root->right->right, 420);
    binary_tree_insert_right(root->left, 99);
    binary_tree_print(root);

    leaves = binary_tree_leaves(root);
    printf("Leaves from %d: %lu\n", root->n, leaves); /*98*/
    leaves = binary_tree_leaves(root->left->right);
    printf("Leaves from %d: %lu\n", root->left->right->n, leaves); /*99*/
    leaves = binary_tree_leaves(root->right->right->right);
    printf("Leaves from %d: %lu\n", root->right->right->right->n, leaves); /*128*/
    leaves = binary_tree_leaves(root->right);
    printf("Leaves from %d: %lu\n", root->right->n, leaves); /*28*/
    leaves = binary_tree_leaves(root->right->right);
    printf("Leaves from %d: %lu\n\n", root->right->right->n, leaves); /*666*/

    binary_tree_insert_left(root->left->right->right, 67);
    binary_tree_insert_left(root->left->right, 44);
    binary_tree_insert_left(root->left->right, 236);
    binary_tree_insert_left(root->left->right, 888);
    binary_tree_print(root);

    leaves = binary_tree_leaves(root);
    printf("Leaves from %d: %lu\n", root->n, leaves); /*98*/
    leaves = binary_tree_leaves(root->left->right->right->left);
    printf("Leaves from %d: %lu\n", root->left->right->right->left->n, leaves); /*67*/
    leaves = binary_tree_leaves(root->left->right);
    printf("Leaves from %d: %lu\n", root->left->right->n, leaves); /*99*/
    leaves = binary_tree_leaves(root->right->right->left);
    printf("Leaves from %d: %lu\n", root->right->right->left->n, leaves); /*128*/
    leaves = binary_tree_leaves(root->left->right->left->left);
    printf("Leaves from %d: %lu\n", root->left->right->left->left->n, leaves); /*236*/
    return (0);
}
