#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void execArgs(char** parsed)
{

	// Forking a child
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("\nFailed forking child..");
		return;

	}
	
	else if (pid == 0)
	{
		if (execvp(parsed[0], parsed) < 0)
		{
			printf("\nCould not execute command..");
		}
		exit(0);
	}
	
	else
	{
		// waiting for child to terminate
		wait(NULL);
		return;
	}
}


int main(void)
{

	char *parsedArgs[100];
	execArgs(parsedArgs);

return (0);
}
