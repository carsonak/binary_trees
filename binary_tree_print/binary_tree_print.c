#include "../binary_trees.h"
#include "string_type.h"

/**
 * _tree_height - calculate height of a binary tree.
 * @tree: root node to to start calculating from.
 *
 * Return: height of the tree.
 */
static size_t _tree_height(const binary_tree_t *const tree)
{
	size_t height_left = 0, height_right = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_left = _tree_height(tree->left) + 1;

	if (tree->right)
		height_right = _tree_height(tree->right) + 1;

	return (height_left > height_right ? height_left : height_right);
}

static String *_node_tostr(const binary_tree_t *const node)
{
	intmax_t s_len = 0;
	String *str = NULL;

	if (!node)
		return (NULL);

	s_len = snprintf(NULL, 0, "[%.3d]", node->n);
	if (s_len < 0)
		return (NULL);

	str = string_new(++s_len);
	if (!str)
		return (NULL);

	if (snprintf(str->s, str->size, "[%.3d]", node->n) < 0)
	{
		string_delete(str);
		return (NULL);
	}

	return (str);
}

static String *adjust_line(String *line, const intmax_t new_size)
{
	intmax_t old_line_end = 0;

	if (!line || new_size < 0)
		return (NULL);

	old_line_end = line->size;
	if (old_line_end > 0)
		--old_line_end;

	line = string_resize(line, new_size);
	if (!line)
		return (NULL);

	memset(&line->s[old_line_end], ' ', new_size - old_line_end);
	return (line);
}

/**
 * struct tree_sizes - measurements of a tree.
 * @width: width of the tree.
 * @hook_point: mid point of the root node.
 */
struct tree_sizes
{
	intmax_t width;
	intmax_t hook_point;
};

/**
 * draw_tree - traverse a binary tree in-order drawing out the nodes and
 * their links onto string buffers.
 * @tree: pointer to the current root node of the tree.
 * @canvas: array of string buffers.
 * @left_margin: left offset into the canvas to start drawing the tree at.
 * @depth: depth of the current root node.
 *
 * Return: sizes of the stringified tree.
 */
static struct tree_sizes draw_tree(
	const binary_tree_t *const tree, String **const canvas,
	const intmax_t left_margin, const intmax_t depth
)
{
	String *node_str = NULL;
	intmax_t node_strlen = 0, i = left_margin;
	struct tree_sizes left = {0}, current = {0}, right = {0};

	if (!tree || left_margin < 0 || depth < 0)
		return (current);

	left = draw_tree(tree->left, canvas, left_margin, depth + 1);
	node_str = _node_tostr(tree);
	/* MALLOC FAIL?? */
	node_strlen = node_str->size - 1;
	right = draw_tree(
		tree->right, canvas, left_margin + left.width + node_strlen, depth + 1
	);
	canvas[depth] = adjust_line(
		canvas[depth], left_margin + left.width + node_strlen + right.width + 1
	);
	/* MALLOC FAIL?? */
	if (left.width > 0)
	{
		i += left.hook_point;
		canvas[depth]->s[i++] = '.';
		memset(&canvas[depth]->s[i], '-', (left_margin + left.width) - i);
	}

	i = left_margin + left.width;
	strncpy(&canvas[depth]->s[i], node_str->s, node_strlen);
	string_delete(node_str);
	i += node_strlen;
	if (right.width > 0)
	{
		memset(&canvas[depth]->s[i], '-', right.hook_point);
		i += right.hook_point;
		canvas[depth]->s[i++] = '.';
	}

	canvas[depth]->s[canvas[depth]->size - 1] = '\0';
	current.width = left.width + node_strlen + right.width;
	current.hook_point = left.width + (node_strlen / 2);
	return (current);
}

/**
 * free_canvas - free a string array.
 * @canvas: pointer to the array of strings.
 * @len: number of elements in the array.
 */
static void free_canvas(String **canvas, size_t len)
{
	while (len > 0)
		string_delete(canvas[--len]);

	free(canvas);
}

/**
 * binary_tree_print - print a binary tree.
 * @tree: pointer to the root node of the tree to print.
 */
void binary_tree_print(const binary_tree_t *const tree)
{
	String **canvas = NULL;
	size_t height = 0, i = 0;

	if (!tree)
		return;

	height = _tree_height(tree);
	canvas = calloc(height + 1, sizeof(*canvas));
	if (!canvas)
		return;

	for (i = 0; i < height + 1; ++i)
	{
		canvas[i] = string_new(0);
		if (!canvas[i])
			goto clean_exit;
	}

	draw_tree(tree, canvas, 0, 0);
	for (i = 0; i < height + 1; i++)
		printf("%s\n", canvas[i]->s);

clean_exit:
	free_canvas(canvas, height + 1);
}
