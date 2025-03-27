#ifndef _MAIN_H
#define _MAIN_H

#include <stddef.h>
#include <stdarg.h>

int _printf(const char *, ...);

/**
 * struct id - Struct id to find.
 *
 * @id: The operator
 * @f: The function associated
 */

typedef struct id
{
	char id;
	int (*f)(va_list *);
} id_f;

int (*get_op_func(const char *))(va_list *);
int _putchar(char);
int _print_char(va_list *);
int _print_str(va_list *);
int _str_len(char *);
int _print_int(va_list *);

#endif
