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
	} while(status);
	return EXIT_SUCCESS;
}

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

		if (c == EOF)
		{
			printf("\n");
			exit(EXIT_FAILURE);
		}
		else if(c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;

		if (position >= bufsize)
		{
			bufsize += 100 ;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				exit(EXIT_FAILURE);
			}
		}
	}
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
	else if(strcmp(args[0], "exit") == 0)
		exit(EXIT_SUCCESS);

	return (_launch(args));
}

int _launch(char **args)
{
	pid_t pid, wpid;
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
	{
		do {

			wpid = waitpid(pid, &status, WNOHANG);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
