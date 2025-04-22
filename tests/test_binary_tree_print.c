#include "../binary_trees.h"
#include <inttypes.h>
#include <limits.h>

/**
 * make_array - initialise an array of ints with the range [start, end).
 * @start: the first integer in the array.
 * @end: the integer after the last in the array.
 *
 * Return: pointer to the created array.
 */
static int *make_array(const int start, const int end)
{
	int *array = NULL;
	const intmax_t array_size = (intmax_t)end - start;
	intmax_t i = 0, k = start;

	if (array_size <= 0)
		return (NULL);

	array = malloc(sizeof(*array) * array_size);
	if (!array)
		return (NULL);

	for (i = 0, k = start; k < end; ++i, ++k)
		array[i] = k;

	return (array);
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	bst_t *tree;
	int *big_array = NULL;
	const int min_val = -50000, max_val = 50001;
	const int array[] = {
		79,  47, 68,   87,      -84,       91,      21,        32,    32, 34,
		2,   20, 22,   98,      1,         62,      -512,      -7,    95, 95,
		100, 0,  1024, INT_MAX, INT16_MAX, INT_MIN, INT16_MIN, -4096,
	};

	tree = array_to_bst(array, sizeof(array) / sizeof(array[0]));
	if (!tree)
		return (1);

	binary_tree_print(tree);
	binary_tree_delete(tree);

	printf("\n\n");
	big_array = make_array(min_val, max_val);
	tree = sorted_array_to_avl(big_array, (intmax_t)max_val - min_val);
	free(big_array);
	if (!tree)
		return (1);

	binary_tree_print(tree);
	binary_tree_delete(tree);
	return (0);
}
