#include "main.h"

/**
 * free_grid - frees a 2D array
 * @grid: 2d array
 * @height: height of array
 */
void free_grid(char **args)
{
	int i;

	while (!args)
		free(args[i++]);
	free(args);
}
