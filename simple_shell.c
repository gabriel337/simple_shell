#include "main.h"

/**
 * main - Entry point
 * Return: Success
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("$ ");
		line = _read_line();
		args = _split_line(line);
		status = _execute(args);
		free(line);
		free(args);
	} while (status);
	return (EXIT_SUCCESS);
}

/**
 * _read_line - gets input from the user
 * Return: string with the input
 */
char *_read_line(void)
{
	int bufsize = 100;
	int position = 0;
	char *buffer;
	int c;

	buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
		exit(EXIT_FAILURE);
	while (1)
	{
		c = getchar();
		if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else if (c == EOF)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
			buffer[position] = c;
		position++;
		if (position >= bufsize)
		{
			bufsize += 100;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
				exit(EXIT_FAILURE);
		}
	}
}

/**
 * _split_line - splits the string into tokens
 * @line: string to be splitted
 * Return: pointer to the divided string
 */
char **_split_line(char *line)
{
	int bufsize = 64, position = 0;
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		printf("Error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				printf("Error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * _execute - checks for errors before launching the command
 * @args: string with commands
 * Return: 1 if launch was success
 */
int _execute(char **args)
{
	int i;
	struct stat st;

	if (args[0] == NULL)
		return (1);
	else if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (stat(*args, &st) == -1)
	{
		perror("execute");
		return (1);
	}
	return (_launch(args));
}

/**
 * _launch - launches the command
 * @args: string with commands
 * Return: 1 success
 */
int _launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1, NULL)
			perror("launch");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("launch");
	else
		wait(NULL);

	return (1);
}
