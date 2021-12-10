#include "main.h"

/**
 * main - Entry point
 * @argc: arguments count
 * @argv: agruments value
 * Return: returns success
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *line;
	int status = 0;
	int i = 1;
	struct stat st;
	char *prog_name = argv[0];

	do {
		/*prompt*/
		line = _read_line();
		
		if (_strcmp(line, "env") == 0)
		{
			print_env();
			status = 1;
			free(line);
			continue;
		}

		else if (_strcmp(line, "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (line[0] == '\0')
		{
			free(line);
			status = 1;
			continue;
		}
		argv = _split_line(line);

		if (stat(argv[0], &st) == -1)
		{
			/*argv = get_path(argv[0]);*/



			_printf("%s: %i: %s: not found\n", prog_name, i, line);
			status = 1;
			i++;
			free(line);
			free(argv);
			continue;

		}
		status = _launch(argv);
		i++;
		free(line);
		free(argv);
	} while (status);
	return (EXIT_SUCCESS);
}

/**
 * _read_line - gets input from the user
 * Return: string with the input
 */
char *_read_line(void)
{
	int bufsize = 1024;
	int position = 0;
	char *buffer = malloc(sizeof(char) * bufsize);
	int c;

	if (!buffer)
	{
		perror("readline");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = _getchar();
		if (c == EOF)
		{
			free(buffer);
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
	}
}

/**
 * _split_line - splits the string into tokens
 * @line: string to be splitted
 * Return: pointer to the divided string
 */
char **_split_line(char *line)
{
	int bufsize = 1024, position = 0;
	char *token;
	char **tokens;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		_puts("Error\n");
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " ");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		token = strtok(NULL, " ");
	}
	tokens[position] = NULL;
	return (tokens);

}

/**
 * _execute - checks for errors before launching the command
 * @args: string with commands
 * Return: 1 if launch was success

 int _execute(char **args)
 {

 if (args[0] == NULL)
 {
 return (1);
 }
 will stdout environment
 if it doesn't recognize command
 return (_launch(args));
 }*/

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
		{
			perror("launch");
		}
		free_grid(args);
		exit(EXIT_FAILURE);
	}

	else if (pid < 0)
		perror("launch");
	else
		wait(&status);
	return (1);
}
