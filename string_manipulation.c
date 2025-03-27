#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _print_char - Writes the character passed to func to stdout.
 *
 * @arg: List of arguments from variadic _printf.
 *
 * Return: On success 1. If NULL passed, 6.
 */

int _print_char(va_list *arg)
{
	int c = va_arg(*arg, int);

	if (c != '\0')
	{
		return (write(1, &c, 1));
	}
	else
	{
		return (0);
	}
}

/**
 * _print_str - Prints a string to stdout.
 *
 * @arg: List of arguments from variadic _printf.
 *
 * Return: The number of characters printed or 6 if the string is NULL.
 */

int _print_str(va_list *arg)
{
	char *ptr = va_arg(*arg, char *);

	if (ptr != NULL)
	{
		return (write(1, ptr, _str_len(ptr)));
	}
	else
	{
		return (write(1, "(null)", 6));
	}
}

/**
 * _str_len - Calculates the length of a string.
 *
 * @str: String to evaluate.
 *
 * Return: The length of the string.
 */

int _str_len(char *str)
{
	unsigned int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}
