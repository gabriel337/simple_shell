#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints string
 * @str: string to be check
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _strcmp - will compare two string
 * @s1: first string
 * @s2: second string
 * Return: returns s1 minus s2
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _getchar - gets characters
 * Return: buffptr
 */
int _getchar(void)
{
	char buffer[100];
	char *buffptr = buffer;
	int readline = 0;

	if (readline == 0)
	{
	readline = read(0, buffer, 1);
	buffptr = buffer;
	}
	if (--readline >= 0)
		return  (*buffptr++);

	return (EOF);
}

/**
 * _strlen - will return length of string
 * @s: variable use
 * Return: returns char
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
