#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>

/**
 * _printf - Prints a string and arguments content.
 *
 * @format: String to print and arguments information.
 *
 * Return: Number of characters printed.
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list args;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[0] == '%' && format[1] == '\0')
			return (-1);

		if (format[i] == '%' && get_op_func(&format[i + 1]) != NULL)
		{
			i++;
			if (format[i] == '%')
			{
				count += write(1, &format[i], 1);
				i++;
			}
			else
			{
				count += get_op_func(&format[i])(&args);
				i++;
			}
		}
		else
		{
			count += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (count);
}
