#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

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
		return (write(1, ptr, _strlen(ptr)));
	}
	else
	{
		return (write(1, "(null)", 6));
	}
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
	int length = _strlen(str) - 1;
	int count = 0;

	while (length >= 0)
	{
		count += write(1, &str[length], 1);
		length--;
	}

	return (count);
}

/**
 * _print_rot13 - Encodes a string into rot13.
 *
 * @args: Arguments recived from _printf.
 *
 * Return: Pointer.
 */

int _print_rot13(va_list *args)
{
	int j, i = 0, count = 0;
	char *str = va_arg(*args, char *);
	char *copy = _strdup(str);
	const char *charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	const char *code = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (copy == NULL)
		return (1);

	while (copy[i] != '\0')
	{
		for (j = 0; j < 52; j++)
		{
			if (copy[i] == charset[j])
			{
				copy[i] = code[j];
				break;
			}
		}
		i++;
	}
	i = 0;
	while (copy[i] != '\0')
	{
		count += write(1, &copy[i], 1);
		i++;
	}
	free(copy);

	return (count);
}

/**
 * _print_S - Prints a string and characters less tan 32 and bigger than 126
 * in ASCII code, encripted.
 *
 * @args: Arguments recived from _printf.
 *
 * Return: Number of characters printed.
 */

int _print_S(va_list *args)
{
	char *str = va_arg(*args, char*);
	int count = 0;
	char hex[4];

	while (str[i] != '\0')
	{
		char c = str[i];

		if (c > 31 && c < 127)
		{
			count += write(1, &c, 1);
		}
		else
		{
			hex[0] = '\\';
			hex[1] = 'x';
			hex[2] = (c / 16 < 10) ? ('0' + (c / 16)) : ('A' + (c / 16) - 10);
			hex[3] = (c % 16 < 10) ? ('0' + (c % 16)) : ('A' + (c % 16) - 10);
			count += write(1, hex, 4);
		}
	}

	return (count);
}
