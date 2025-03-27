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
	unsigned int count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				count += write(1, format, 1);
				format++;
			}
			else
			{
				count += get_op_func(format)(&args);
				format++;
			}
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (count);
}
