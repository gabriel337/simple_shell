#include "main.h"

int launch(char **args)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("\nFailed forking child..");
		return(1);
	}
	else if (pid == 0)
	{

	if (execve(args[0], args, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
		printf("%u\n", pid);
	}
	return (1);
}
int main(int argc, char *argv[])
{
	char *b;
	char *token;
	size_t bufsize = argc;
	const char s[2] = " ";

	b = malloc(sizeof(char *) * argc);

	printf("$ ");

	getline(&b, &bufsize, stdin);

	launch(&b);


	token = strtok(b, s);
	

	while(token != NULL)
	{
		/*printf("%s\n", token);*/
		token = strtok(NULL, s);
	}
	return (0);
}
