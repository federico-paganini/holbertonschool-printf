#include "3-calc.h"
#include <stddef.h>
#include <string.h>

/**
 * get_op_func - Selects the correct function to print args.
 *
 * @s: Character who indicates the print function to return.
 *
 * Return: A pointer to the function to perform the operation.
 */

void (*get_op_func(char *s))(void *)
{
	op_t ops[] = {
		{'c', op_add},
		{'s', op_sub},
		{'d', op_mul},
		{'i', op_div},
		{'%', op_mod},
		{NULL, NULL}
	};

	int i = 0;

	while (ops[i].op && ops[i].op != *s)
	{
		i++;
	}
	return (ops[i].f);
}
