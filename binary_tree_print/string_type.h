#ifndef STRING_TYPE_H
#define STRING_TYPE_H

#include <inttypes.h> /* intmax_t */
#include <stdlib.h>   /* *alloc */

/**
 * struct String - a string type.
 * @size: size of the string in bytes.
 * @s: pointer to the string.
 */
struct String
{
	intmax_t size;
	char *s;
};
typedef struct String String;

String *string_new(const intmax_t size);
void string_delete(String *const str);
String *string_resize(String *const str, const intmax_t size);

#endif /* STRING_TYPE_H */
