#include "main.h"

/**
 * accString - returns arguments to the list
 * @vl: variadic list
 * Return: value in the list
 */
int accString(va_list *vl)
{
	return (print_string(va_arg(*vl, char *)));
}

/**
 * accChar - return arguments to the list
 * @vl: variadic list
 * Return: value in the list
 */
int accChar(va_list *vl)
{
	return (_putchar(va_arg(*vl, int)));
}

/**
 * accInt - return arguments to the list
 * @vl: variadic list
 * Return: value in the list
 */
int accInt(va_list *vl)
{
	return (print_int(va_arg(*vl, int)));
}

/**
 * accPercent - return arguments to the list
 * @vl: variadic list
 * Return: value in the list
 */
int accPercent(va_list *vl)
{
	(void) vl;

	_putchar('%');
	return (1);
}
