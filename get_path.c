#include "main.h"

char **get_path(char *tokens)
{
	int buffsize = 1024, position = 0;
	char *path_token;
	char **path_tokens;
	char *path = getenv("PATH");

	printf("<debug getpath>");
	path_tokens = malloc(buffsize * sizeof(char *));
	if (path_tokens == NULL)
	{
		_puts("ERROR\n");
		free(path_tokens);
		exit(EXIT_FAILURE);
	}

	path_token = strtok(path, ":");
	while (path_token != NULL)
	{
		path_tokens[position] = path_token;
		position++;
		path_token = strtok(NULL, ":");
	}
	path_tokens[position] = NULL;

	for(position = 0; *path_tokens[position] != '\0'; position++)
	{
		strcat(path_tokens[position], "/");
		strcat(path_tokens[position], tokens);
	}
	return (path_tokens);

}
