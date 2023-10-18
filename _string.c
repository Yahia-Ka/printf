#include "main.h"

/**
 * _string - Print string
 * @list: list.
 *
 * Return: String length.
 */

int _string(va_list list)
{
	char *p;
	int p_len;

	p = va_arg(list, char*);
	p_len = print((p != NULL) ? p : "(null)");

	return (p_len);
}