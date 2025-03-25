#include <stddef.h>

/**
 * _printf - 
 *
 *
 * Return: Number of characters printed.
 */

int _printf(const char *format, ...)
{
	unsigned int i, count = 0;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				count++;
				_putchar(format);
			}
			else
			{
				get_op_function(*format, va_arg(args, void));
			}
		}
		else
		{
			count++;
			_putchar(format);
		}
	}
	va_end(args);
	return (count);
}
