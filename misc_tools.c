#include "main.h"
/**
 * _strdup - returns a pointer to a duplicate of a given string
 * @strOG: given string to be duplicates
 *
 * Return: pointer to a duplicate of a given string or NULL if failed
 */
char *_strdup(const char *strOG)
{
	char *dup = NULL;
	int c, n;

	if (strOG == NULL)
		return (NULL);

	for (n = 0; strOG[n] != '\0'; n++)
		;
	n++;
	dup = malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
	{
		perror("Malloc failure");
		return (NULL);
	}

	for (c = 0; c < n; c++)
		dup[c] = strOG[c];
	dup[c] = '\0';

	return (dup);
}
