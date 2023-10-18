#include "main.h"

/**
 * _octal - Print a unsigned octal
 * @list: Number to print
 *
 * Return: Length of the number
 **/
int _octal(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 8);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}