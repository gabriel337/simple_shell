#include "main.h"

int main()
{
	char str[80];
	const char s[2] = " ";
	char *b = str;
	char *token;
	size_t bufsize = 80;

	printf("$ ");

	getline(&b, &bufsize, stdin);

	/* get the first token */
	token = strtok(str, s);

	/* walk through other tokens */
	while( token != NULL ) {
		printf( "%s\n", token );

		token = strtok(NULL, s);
	}

	return(0);
}
