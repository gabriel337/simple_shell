#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	/*
	   int j;

	   for (j = 0; j < argc; j++)
	   printf("argv[%d]: %s\n", j, argv[j]);

	   exit(EXIT_SUCCESS);
	   */


	char  *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i;
	int status;

	
	for(i = 0; i < 5; i++)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			printf("\nFailed forking child..");
			return(1);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&status);
			printf("%u\n", pid);
		}
	}

	return (0);
}
