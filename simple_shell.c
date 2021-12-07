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
		/*promt*/
		_puts("$ ");
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
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		perror("readline");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = _getchar();
		if (c == EOF)
		{
			_puts("logout successful");
			_putchar('\n');
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
			buffer[position] = c;
		position++;
		/* If we have exceeded the buffer, reallocate.*/
		if (position >= bufsize)
		{
			bufsize += 100;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				perror("readline");
				exit(EXIT_FAILURE);
			}
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
	char **tokens;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		_puts("Error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		/* if need more memory space, then add*/
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));

			if (!tokens)
			{
				perror("Error\n");
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
	struct stat st;

	if (args[0] == NULL)
		return (1);

	/*will stdout environment*/
	else if (strcmp(args[0], "printenv") == 0)
	{
		/*function to get environment*/
		get_env();
		return (1);
	}

	/*exit program if "exit" is inputed*/
	else if (strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	/*if it doesn't recognize command*/
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
		if (execve(args[0], args, environ) == -1)
			perror("launch");
		exit(EXIT_FAILURE);
	}

	else if (pid < 0)
		perror("launch");
	else
		wait(&status);

	return (1);
}
