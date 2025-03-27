#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - 
 *
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
				count += _putchar(*format);
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
			count += _putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
