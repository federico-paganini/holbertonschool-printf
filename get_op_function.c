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
		{'c', _print_char}, {'s', _print_str}, {'%', _print_char},
		{'i', _print_int}, {'d', _print_int}, {'b', _print_binary},
		{'u', _print_uint}, {'r', _print_rev}, {'R', _print_rot13},
		{'o', _print_oct}, {'x', _print_hex}, {'X', _print_hexa},
		{'p', _print_ptr}, {'S', _print_S}
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
