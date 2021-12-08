/**
 * _strcmp - will compare two string
 * @s1: first string
 * @s2: second string
 * Return: returns s1 minus s2
 */
int _exit_strcmp(char *s1)
{
	char *s2 = "exit";

	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}
