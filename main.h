#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/* utils.c */
int _strlen(const char *);
int print(char *);
char *itoa(long int, int);

/* printf.c */
int _printf(const char *, ...);

/* handler.c */
int handler(const char *, va_list);
int percent_handler(const char *, va_list, int *);

/* printers */
int _string(va_list);
int _char(va_list);
int _integer(va_list);
int _binary(va_list);
int _rot(va_list);
int _unsigned(va_list);
int _octal(va_list);
int _hexadecimal_low(va_list);
int _hexadecimal_upp(va_list);
int _pointer(va_list);
int _rev_string(va_list);

/* _putchar.c */
int _putchar(char);
int buffer(char);

/**
 * struct _format - Typedef struct
 *
 * @type: Format
 * @f: The function associated
 **/
typedef struct _format
{
	char type;
	int (*f)(va_list);
} format;


#endif