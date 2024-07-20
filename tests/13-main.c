#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t inodes;

    printf("Internal nodes of NULL: %lu\n\n", binary_tree_nodes(NULL));

    root = binary_tree_node(NULL, 98);
    binary_tree_print(root);
    printf("Internal nodes from %d: %lu\n\n", root->n, binary_tree_nodes(root));

    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    inodes = binary_tree_nodes(root);
    printf("Internal nodes from %d: %lu\n", root->n, inodes);
    inodes = binary_tree_nodes(root->right);
    printf("Internal nodes from %d: %lu\n", root->right->n, inodes);
    inodes = binary_tree_nodes(root->left->right);
    printf("Internal nodes from %d: %lu\n\n", root->left->right->n, inodes);

    binary_tree_insert_right(root, 28);
    binary_tree_insert_right(root->right, 666);
    binary_tree_insert_left(root->right, 100);
    binary_tree_insert_left(root->right->right, 420);
    binary_tree_insert_right(root->left, 99);
    binary_tree_print(root);

    inodes = binary_tree_nodes(root);
    printf("Internal nodes from %d: %lu\n", root->n, inodes); /*98*/
    inodes = binary_tree_nodes(root->left->right);
    printf("Internal nodes from %d: %lu\n", root->left->right->n, inodes); /*99*/
    inodes = binary_tree_nodes(root->right->right->right);
    printf("Internal nodes from %d: %lu\n", root->right->right->right->n, inodes); /*128*/
    inodes = binary_tree_nodes(root->right);
    printf("Internal nodes from %d: %lu\n", root->right->n, inodes); /*28*/
    inodes = binary_tree_nodes(root->right->right);
    printf("Internal nodes from %d: %lu\n\n", root->right->right->n, inodes); /*666*/

    binary_tree_insert_left(root->left->right->right, 67);
    binary_tree_insert_left(root->left->right, 44);
    binary_tree_insert_left(root->left->right, 236);
    binary_tree_insert_left(root->left->right, 888);
    binary_tree_print(root);

    inodes = binary_tree_nodes(root);
    printf("Internal nodes from %d: %lu\n", root->n, inodes); /*98*/
    inodes = binary_tree_nodes(root->left->right->right->left);
    printf("Internal nodes from %d: %lu\n", root->left->right->right->left->n, inodes); /*67*/
    inodes = binary_tree_nodes(root->left->right);
    printf("Internal nodes from %d: %lu\n", root->left->right->n, inodes); /*99*/
    inodes = binary_tree_nodes(root->right->right->left);
    printf("Internal nodes from %d: %lu\n", root->right->right->left->n, inodes); /*128*/
    inodes = binary_tree_nodes(root->left->right->left->left);
    printf("Internal nodes from %d: %lu\n", root->left->right->left->left->n, inodes); /*236*/
    return (0);
}
