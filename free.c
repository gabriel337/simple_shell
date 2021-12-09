#include "main.h"

/**
 * free_grid - frees a 2D array
 * @args: arguments
 */
void free_grid(char **args)
{
	int i = 0;

	while (args[i] != NULL)
	{
		free(args[i++]);
	}
	free(args);
}
