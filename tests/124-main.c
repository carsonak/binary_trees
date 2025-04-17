#include "../binary_trees.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Size of the array
 */
void print_array(const int *const array, const size_t size)
{
	size_t i;

	printf("{");
	for (i = 0; i < size; ++i)
	{
		printf("%03d", array[i]);
		if (i < size - 1)
			printf(", ");
	}

	printf("}\n");
}

/**
 * build_and_print_tree - builds an avl tree from a sorted array and
 * prints the array and the tree.
 * @array: pointer to the first element of the array.
 * @array_size: number of elements in the array.
 *
 * Return: 1 on success, 0 on error.
 */
int build_and_print_tree(const int *const array, const size_t array_size)
{
	avl_t *const tree = sorted_array_to_avl(array, array_size);

	if (!tree)
		return (0);

	print_array(array, array_size);
	binary_tree_print(tree);
	binary_tree_delete(tree);
	return (1);
}

struct int_array
{
	size_t size;
	const int *array;
};

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	size_t i = 0;
	const struct int_array test_arrays[] = {
		{1, (const int[]){1}},
		{2, (const int[]){1, 2}},
		{3, (const int[]){1, 2, 3}},
		{4, (const int[]){1, 2, 3, 4}},
		{5, (const int[]){1, 2, 3, 4, 5}},
		{16, (const int[]){1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87,
						   91, 95, 98}}
	};

	for (i = 0; i < sizeof(test_arrays) / sizeof(*test_arrays); i++)
	{
		if (!build_and_print_tree(test_arrays[i].array, test_arrays[i].size))
			return (1);

		if (i < sizeof(test_arrays) / sizeof(*test_arrays) - 1)
			printf("\n\n");
	}

	build_and_print_tree(NULL, 10);
	build_and_print_tree(test_arrays[1].array, 0);
	return (0);
}
