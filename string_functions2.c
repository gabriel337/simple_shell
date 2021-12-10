/**
 * _strcat - This function will concatenate two string
 * @dest: destination char
 * @src: source char
 * Return: returns the two chars
 */
char *_strcat(char *dest, char *src)
{
	char *cat = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (cat);
}
