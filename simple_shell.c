#include "main.h"

int main(int argc, char **argv)
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
	return EXIT_SUCCESS;
}

char *_read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

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

int _execute(char **args)
{
	int i;

	if (args[0] == NULL)
		return (1);
	return (_launch(args));
}

int _launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args) == -1, NULL)
			perror("launch");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("launch");
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
