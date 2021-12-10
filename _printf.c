#include "main.h"

/**
 * _printf - prints different formats
 * @format: start of the list
 * Return: returns result
 */
int _printf(const char *format, ...)
{
	unsigned int i, result = 0;
	va_list vl;

	if (format == NULL)
		return (-1);

	va_start(vl, format); /* pointing to format */

	if (vl == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{

		if (format[i] == '%' && format[i + 1] != '\0')  /*if i is the same as %
								*then verify the next char and call the function
								*/
		{
			result += get_print(format[i + 1], &vl);
			i++;
		}
		else /*if not then print each char (string)*/
		{
			if (format[i] == '%')
				return (-1);
			_putchar(format[i]);
			result++;
		}
	}
	va_end(vl);
	return (result);
}
