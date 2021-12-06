#include "main.h"

/**
 * get_env - gets environment
 * Return: 0
 */
int  get_env(void)
{
	int count = 0;

	while (environ[count] != NULL)
	{
		printf("%s\n", environ[count]);
		count++;
	}
	return (0);
}
