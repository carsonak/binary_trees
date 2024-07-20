#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t size;

    printf("Size of NULL: %lu\n\n", binary_tree_size(NULL));

    root = binary_tree_node(NULL, 98);
    binary_tree_print(root);
    printf("Size from %d: %lu\n\n", root->n, binary_tree_size(root));

    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    size = binary_tree_size(root);
    printf("Size from %d: %lu\n", root->n, size);
    size = binary_tree_size(root->right);
    printf("Size from %d: %lu\n", root->right->n, size);
    size = binary_tree_size(root->left->right);
    printf("Size from %d: %lu\n\n", root->left->right->n, size);

    binary_tree_insert_right(root, 28);
    binary_tree_insert_right(root->right, 666);
    binary_tree_insert_left(root->right, 100);
    binary_tree_insert_left(root->right->right, 420);
    binary_tree_insert_right(root->left, 99);
    binary_tree_print(root);

    size = binary_tree_size(root);
    printf("Size from %d: %lu\n", root->n, size); /*98*/
    size = binary_tree_size(root->left->right);
    printf("Size from %d: %lu\n", root->left->right->n, size); /*99*/
    size = binary_tree_size(root->right->right->right);
    printf("Size from %d: %lu\n", root->right->right->right->n, size); /*128*/
    size = binary_tree_size(root->right);
    printf("Size from %d: %lu\n", root->right->n, size); /*28*/
    size = binary_tree_size(root->right->right->right->right);
    printf("Size from %d: %lu\n\n", root->right->right->right->right->n, size); /*402*/

    binary_tree_insert_left(root->left->right->right, 67);
    binary_tree_insert_left(root->left->right, 44);
    binary_tree_insert_left(root->left->right, 236);
    binary_tree_insert_left(root->left->right, 888);
    binary_tree_print(root);

    size = binary_tree_size(root);
    printf("Size from %d: %lu\n", root->n, size); /*98*/
    size = binary_tree_size(root->left->right->right->left);
    printf("Size from %d: %lu\n", root->left->right->right->left->n, size); /*67*/
    size = binary_tree_size(root->left->right);
    printf("Size from %d: %lu\n", root->left->right->n, size); /*99*/
    size = binary_tree_size(root->right->right->left);
    printf("Size from %d: %lu\n", root->right->right->left->n, size); /*128*/
    size = binary_tree_size(root->left->right->left->left);
    printf("Size from %d: %lu\n", root->left->right->left->left->n, size); /*236*/
    return (0);
}
