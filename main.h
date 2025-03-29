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

/**
 * struct parameters - Struct to handle _printf flags.
 *
 * @flag: Flags to handle format.
 * @width: Parameter to handle minimum output width.
 * @precs: Parameter to specify number of digits of decimals
 * or max string length.
 * @length: Length modifiers for numbers variables bigger than int.
 * @dataid: Data type passed to function.
 */

/**typedef struct parameters
 *{
 *char *flag;
 *	char *width;
 *	char *precs;
 *	char *length;
 *	char *dataid;
 *} Params;
 */

int (*get_op_func(const char *))(va_list *);
int _putchar(char);
int _print_char(va_list *);
int _print_str(va_list *);
int _strlen(char *);
int _print_int(va_list *);
int _print_binary(va_list *);
int _print_uint(va_list *);
int _print_rev(va_list *);
int _print_rot13(va_list *);
int _print_oct(va_list *);
int _print_hex(va_list *);
int _print_hexa(va_list *);
int _print_ptr(va_list *);
char *_strdup(char *);

#endif
