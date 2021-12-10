#include "main.h"

/**
 * print_string - prints string
 * @str: string to be printed
 * Return: returns the string
 */
int print_string(char *str)
{
	unsigned int i;

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}


/**
 * print_int - prints numbers
 * @num: number to be printed
 * Return: num
 */
int print_int(int num)
{
	int count = 1;
	unsigned int i;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}
	i = num;

	if (i > 9)
	{
		count += print_int(i / 10);
	}
	_putchar(i % 10 + '0');
	return (count);
}

