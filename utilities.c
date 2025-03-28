#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Calculates the length of a string.
 *
 * @str: String to evaluate.
 *
 * Return: The length of the string.
 */

int _strlen(char *str)
{
	unsigned int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * _strdup - Returns a pointer to a newly allocated space in memory,
 *	     which contains a copy of the string given as a parameter.
 *
 * @str: String to copy.
 *
 * Return: Pointer to a new string which is a duplicate of the string str.
 * If str = NULL returns NULL.
 * NULL if not enought memory.
 */

char *_strdup(char *str)
{
	unsigned int length;
	unsigned int i = 0;
	char *arr;

	if (str == NULL)
		return (NULL);

	length = _strlen(str);
	arr = malloc(sizeof(char) * (length + 1));

	if (arr == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		arr[i] = str[i];
	}
	arr[length] = '\0';

	return (arr);
}
