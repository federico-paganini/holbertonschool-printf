#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _print_int - Prints a int.
 *
 * @args: Agruments from variadic _printf.
 *
 * Return: Number of characters printed.
 */

int _print_int(va_list *args)
{
	int num = va_arg(*args, int);
	int count = 0, i = 0;
	unsigned int n;
	char buffer[11];

	if (num == 0)
		return (write(1, "0", 1));

	if (num < 0)
	{
		n = -num;
		count += write(1, "-", 1);
	}
	else
	{
		n = num;
	}

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}
