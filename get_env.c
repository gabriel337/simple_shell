#include "main.h"

/**
 * get_env - gets environment
 * Return: 0
 */
int  get_env(void)
{
	unsigned int count = 0;

	while (environ[count] != NULL)
	{
		write(STDOUT_FILENO, environ[count], _strlen(environ[count]));
		write(STDOUT_FILENO, "\n", 1);
		count++;
	}
	return (0);
}
