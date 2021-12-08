#include "main.h"

/**
 * free_grid - frees a 2D array
 * @args: arguments
 */
void free_grid(char **args)
{
	int i;

	while (!args)
		free(args[i++]);
	free(args);
}
