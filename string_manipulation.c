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

	return (write(1, &c, 1));
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

/**
 * _print_rev - Prints a string, in reverse.
 *
 * @args: Arguments list.
 *
 * Return: Number of chars printed.
 */

int _print_rev(va_list *args)
{
	char *str = va_arg(*args, char *);
	int length = _str_len(str);
	int count = 0;

	while (length >= 0)
	{
		write(1, &str[length], 1);
		length--;
	}

	return (count);
}
