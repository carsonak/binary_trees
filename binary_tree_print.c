#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * _tree_height - calculate the height of a binary tree.
 * @tree: pointer to the root node of the tree.
 *
 * Return: the height of the tree.
 */
static size_t _tree_height(const binary_tree_t *const tree)
{
	const size_t height_l = tree->left ? 1 + _tree_height(tree->left) : 0;
	const size_t height_r = tree->right ? 1 + _tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * draw_tree - traverse a binary tree in-order drawing out the nodes and
 * their links onto string buffers.
 * @tree: pointer to the current root node of the tree.
 * @left_margin: left offset into the canvas to start drawing the tree at.
 * @depth: depth of the current root node.
 * @canvas: array of string buffers.
 *
 * Return: new left margin offset after printing the node.
 */
static int draw_tree(
	const binary_tree_t *const tree, const int left_margin, const int depth,
	char *const *const canvas
)
{
	char node_data_str[16];
	int width, left, right, i;

	if (!tree)
		return (0);

	left = draw_tree(tree->left, left_margin, depth + 1, canvas);
	width = sprintf(node_data_str, "(%.3d)", tree->n);
	right =
		draw_tree(tree->right, left_margin + left + width, depth + 1, canvas);
	for (i = 0; i < width; i++)
		canvas[depth][left_margin + left + i] = node_data_str[i];

	if (depth > 0)
	{
		unsigned short int is_left =
			(tree->parent && (tree->parent->left == tree));

		if (is_left)
		{
			canvas[depth - 1][left_margin + left + (width / 2)] = '.';
			for (i = 1; i < width + right; i++)
				canvas[depth - 1][left_margin + left + (width / 2) + i] = '-';
		}
		else
		{
			for (i = 0; i < left + width; i++)
				canvas[depth - 1][left_margin - (width / 2) + i] = '-';

			canvas[depth - 1][left_margin + left + (width / 2)] = '.';
		}
	}

	return (left + width + right);
}

/**
 * free_canvas - free a string array.
 * @canvas: pointer to the array of strings.
 * @len: number of elements in the array.
 */
static void free_canvas(char **canvas, size_t len)
{
	while (len > 0)
		free(canvas[--len]);

	free(canvas);
}

/**
 * binary_tree_print - print a binary tree.
 * @tree: pointer to the root node of the tree to print.
 */
void binary_tree_print(const binary_tree_t *const tree)
{
	char **canvas;
	size_t height, i, j;

	if (!tree)
		return;

	height = _tree_height(tree);
	canvas = calloc(height + 1, sizeof(*canvas));
	if (!canvas)
		return;

	for (i = 0; i < height + 1; i++)
	{
		canvas[i] = malloc(sizeof(**canvas) * 256);
		if (!canvas[i])
			goto clean_exit;

		memset(canvas[i], ' ', 256);
	}

	draw_tree(tree, 0, 0, canvas);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 255; j > 1 && canvas[i][j] == ' '; --j)
			canvas[i][j] = '\0';

		printf("%s\n", canvas[i]);
	}

clean_exit:
	free_canvas(canvas, height + 1);
}
