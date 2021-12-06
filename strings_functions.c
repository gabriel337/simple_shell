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

int _getchar(void)
{
        static char buf[BUFSIZ];
        static char *bufp = buf;
        static int i = 0;

        if (i == 0)
        {
                i = read(0, buf, 1);
                bufp = buf;
        }
        if ( --i >= 0 )
        {
                return  *bufp++;
        }

        return EOF;
}
