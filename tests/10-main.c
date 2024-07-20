#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    printf("Height of NULL: %lu\n\n", binary_tree_depth(NULL));

    root = binary_tree_node(NULL, 98);
    binary_tree_print(root);
    printf("Height from %d: %lu\n\n", root->n, binary_tree_depth(root));

    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    height = binary_tree_depth(root);
    printf("Height from %d: %lu\n", root->n, height);
    height = binary_tree_depth(root->right);
    printf("Height from %d: %lu\n", root->right->n, height);
    height = binary_tree_depth(root->left->right);
    printf("Height from %d: %lu\n\n", root->left->right->n, height);

    binary_tree_insert_right(root, 28);
    binary_tree_insert_right(root->right, 666);
    binary_tree_insert_left(root->right, 100);
    binary_tree_insert_left(root->right->right, 420);
    binary_tree_insert_right(root->left, 99);
    binary_tree_print(root);

    height = binary_tree_depth(root);
    printf("Height from %d: %lu\n", root->n, height); /*98*/
    height = binary_tree_depth(root->left->right);
    printf("Height from %d: %lu\n", root->left->right->n, height); /*99*/
    height = binary_tree_depth(root->right->right->right);
    printf("Height from %d: %lu\n", root->right->right->right->n, height); /*128*/
    height = binary_tree_depth(root->right);
    printf("Height from %d: %lu\n", root->right->n, height); /*28*/
    height = binary_tree_depth(root->right->right->right->right);
    printf("Height from %d: %lu\n\n", root->right->right->right->right->n, height); /*402*/

    binary_tree_insert_left(root->left->right->right, 67);
    binary_tree_insert_left(root->left->right, 44);
    binary_tree_insert_left(root->left->right, 236);
    binary_tree_insert_left(root->left->right, 888);
    binary_tree_print(root);

    height = binary_tree_depth(root);
    printf("Height from %d: %lu\n", root->n, height); /*98*/
    height = binary_tree_depth(root->left->right->right->left);
    printf("Height from %d: %lu\n", root->left->right->right->left->n, height); /*67*/
    height = binary_tree_depth(root->left->right);
    printf("Height from %d: %lu\n", root->left->right->n, height); /*99*/
    height = binary_tree_depth(root->right->right->left);
    printf("Height from %d: %lu\n", root->right->right->left->n, height); /*128*/
    height = binary_tree_depth(root->left->right->left->left);
    printf("Height from %d: %lu\n", root->left->right->left->left->n, height); /*236*/
    return (0);
}
