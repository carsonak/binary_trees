#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int balance;

    printf("Balance atULL: %d\n\n", binary_tree_balance(NULL));

    root = binary_tree_node(NULL, 98);
    binary_tree_print(root);
    printf("Balance at %d: %d\n\n", root->n, binary_tree_balance(root));

    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_insert_left(root, 45);
    binary_tree_insert_right(root->left, 50);
    binary_tree_insert_left(root->left->left, 10);
    binary_tree_insert_left(root->left->left->left, 8);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance at %d: %d\n", root->n, balance);
    balance = binary_tree_balance(root->right);
    printf("Balance at %d: %d\n", root->right->n, balance);
    balance = binary_tree_balance(root->left->right);
    printf("Balance at %d: %d\n\n", root->left->right->n, balance);

    binary_tree_insert_right(root, 28);
    binary_tree_insert_right(root->right, 666);
    binary_tree_insert_left(root->right, 100);
    binary_tree_insert_left(root->right->right, 420);
    binary_tree_insert_right(root->left, 99);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance at %d: %d\n", root->n, balance); /*98*/
    balance = binary_tree_balance(root->left->right);
    printf("Balance at %d: %d\n", root->left->right->n, balance); /*99*/
    balance = binary_tree_balance(root->right->right->right);
    printf("Balance at %d: %d\n", root->right->right->right->n, balance); /*128*/
    balance = binary_tree_balance(root->right);
    printf("Balance at %d: %d\n", root->right->n, balance); /*28*/
    balance = binary_tree_balance(root->right->right);
    printf("Balance at %d: %d\n\n", root->right->right->n, balance); /*666*/

    binary_tree_insert_left(root->left->right->right, 67);
    binary_tree_insert_left(root->left->right, 44);
    binary_tree_insert_left(root->left->right, 236);
    binary_tree_insert_left(root->left->right, 888);
    binary_tree_print(root);

    balance = binary_tree_balance(root);
    printf("Balance at %d: %d\n", root->n, balance); /*98*/
    balance = binary_tree_balance(root->left->right->right->left);
    printf("Balance at %d: %d\n", root->left->right->right->left->n, balance); /*67*/
    balance = binary_tree_balance(root->left->right);
    printf("Balance at %d: %d\n", root->left->right->n, balance); /*99*/
    balance = binary_tree_balance(root->right->right->left);
    printf("Balance at %d: %d\n", root->right->right->left->n, balance); /*128*/
    balance = binary_tree_balance(root->left->right->left->left);
    printf("Balance at %d: %d\n", root->left->right->left->left->n, balance); /*236*/
    return (0);
}
