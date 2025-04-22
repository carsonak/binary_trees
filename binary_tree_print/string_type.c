#include "string_type.h"

String *string_new(const intmax_t size)
{
	String *str = NULL;

	if (size < 0)
		return (0);

	str = calloc(1, sizeof(*str));
	if (!str)
		return (NULL);

	str->size = size;
	if (size > 0)
	{
		str->s = malloc(sizeof(*str->s) * size);
		if (!str->s)
		{
			free(str);
			return (NULL);
		}
	}

	return (str);
}

void string_delete(String *const str)
{
	str->size = 0;
	free(str->s);
	str->s = NULL;
	free(str);
}

String *string_resize(String *const str, const intmax_t size)
{
	char *new_s = NULL;

	if (!str || size < 0)
		return (NULL);

	new_s = realloc(str->s, size);
	if (!new_s && size > 0)
	{
		string_delete(str);
		return (NULL);
	}

	str->size = size;
	str->s = new_s;
	return (str);
}
