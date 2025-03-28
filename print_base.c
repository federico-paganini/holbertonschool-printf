#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * _print_binary - Prints an unsigned int in binary.
 *
 * @args: Arguments list.
 *
 * Return: Printed chars count.
 */

int _print_binary(va_list *args)
{
	unsigned int num = va_arg(*args, unsigned int);
	unsigned int bits = sizeof(num) * 8;
	int i = 0, leading = 1, count = 0;

	for (i = bits - 1; i >= 0; i--)
	{
		if (num & (1 << i))
		{
			leading = 0;
			count += write(1, "1", 1);
		}
		else if (!leading)
		{
			count += write(1, "0", 1);
		}
	}

	if (leading)
		count += write(1, "0", 1);

	return (count);
}

/**
 * _print_oct - Print a natural number in otal base.
 *
 * @args: Arguments recived from _printf.
 *
 * Return: Number of chars printed.
 */

int _print_oct(va_list *args)
{
	unsigned int num = va_arg(*args, unsigned int);
	int i = 0, count = 0;
	char buffer[11];

	if (num == 0)
		return (write(1, "0", 1));

	while (num > 0)
	{
		buffer[i++] = (num % 8) + '0';
		num = num / 8;
	}

	while (i--)
		count += write(1, &buffer[i], 1);

	return (count);
}

/**
 * _print_hex - Prints an int in hexadecimal lowercase.
 *
 * @args: Arguments recived from _printf.
 *
 * Return: Number of chars printed.
 */

int _print_hex(va_list *args)
{
	unsigned int num = va_arg(*args, unsigned int);
	int i = 0, count = 0;
	char hexDigits[] = "0123456789abcdef";
	char hex[16];

	if (num == 0)
		return (write(1, "0", 1));

	while (num != 0)
	{
		hex[i++] = hexDigits[num % 16];
		num = num / 16;
	}

	while (i--)
		count += write(1, &hex[i], 1);

	return (count);
}

/**
 * _print_hexa - Prints an int in hexadecimal uppercase.
 *
 * @args: Arguments recived from _printf.
 *
 * Return: Number of chars printed.
 */

int _print_hexa(va_list *args)
{
	unsigned int num = va_arg(*args, unsigned int);
	int i = 0, count = 0;
	char hexDigits[] = "0123456789ABCDEF";
	char hex[16];

	if (num == 0)
		return (write(1, "0", 1));

	while (num != 0)
	{
		hex[i++] = hexDigits[num % 16];
		num = num / 16;
	}

	while (i--)
		count += write(1, &hex[i], 1);

	return (count);
}

/**
 * _print_ptr - Prints the memory adress of a pointer.
 *
 * @args: Arguments recived from _printf.
 *
 * Return: Number of chars printed.
 */

int _print_ptr(va_list *args)
{
	void *ptr = va_arg(*args, void *);
	unsigned long numadr;
	int i = 0, count = 0;
	char hexDigits[] = "0123456789abcdef";
	char adress[16];

	if (ptr == NULL)
		return (write(1, "(nil)", 5));

	numadr = (unsigned long)ptr;

	if (numadr == 0)
		return (write(1, "0x0", 3));

	while (numadr != 0)
	{
		adress[i++] = hexDigits[numadr % 16];
		numadr = numadr / 16;
	}

	count += write(1, "0x", 2);

	while (i--)
		count += write(1, &adress[i], 1);

	return (count);
}
