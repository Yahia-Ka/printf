#include "main.h"

/**
 * handler - Format controller
 * @str: String format
 * @list: List of arguments
 *
 * Return: Total size of arguments with the total size of the base string
 **/
int handler(const char *str, va_list list)
{
	int size, i, aux;

	size = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == '%')
		{
			aux = percent_handler(str, list, &i);
			if (aux == -1)
				return (-1);

			size += aux;
			continue;
		}

		_putchar(str[i]);
		size = size + 1;
	}


	return (size);
}

/**
 * percent_handler - Controller for percent format
 * @str: String format
 * @list: List of arguments
 * @i: Iterator
 *
 * Return: Size of the numbers of elements printed
 **/
int percent_handler(const char *str, va_list list, int *i)
{
	int size, j, number_formats;
	format formats[] = {
		{'s', _string}, {'c', _char},
		{'d', _integer}, {'i', _integer},
		{'b', _binary}, {'u', _unsigned},
		{'o', _octal}, {'x', _hexadecimal_low},
		{'X', _hexadecimal_upp}, {'p', _pointer},
		{'r', _rev_string}, {'R', _rot}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}

	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (size = j = 0; j < number_formats; j++)
	{
		if (str[*i] == formats[j].type)
		{
			size = formats[j].f(list);
			return (size);
		}

	}

	_putchar('%'), _putchar(str[*i]);

	return (2);
}