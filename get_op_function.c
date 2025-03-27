#include "main.h"
#include <stddef.h>
#include <string.h>

/**
 * get_op_func - Selects the correct function to print args.
 *
 * @s: Character who indicates the print function to return.
 *
 * Return: A pointer to the function to perform the operation.
 */

int (*get_op_func(const char *s))(va_list *)
{
	id_f ops[] = {
		{'c', _print_char},
		{'s', _print_str},
	};

	int i = 0;

	while (ops[i].id)
	{
		if (ops[i].id == *s)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
