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
/**
 * rm_nwln - removes the newline character at the end of a given string
 * @str: newline terminated string
 *
 * Return: void
 */
void rm_nwln(char *str)
{
	char *new_str;

	if (str == NULL)
		return;
	new_str = str;
	while (*str != '\n')
	{
		*new_str = *str;
		new_str++;
		str++;
	}
	*new_str = '\0';
}

/**
 * _strstrp- returns a pointer to a duplicate of a given string
 * with spaces before it removed
 * @strOG: given string to be duplicates
 *
 * Return: pointer to a duplicate of a given string or NULL if failed
 */
char *_strstrp(const char *strOG)
{
	char *dup = NULL;
	int c, l = 0, m = 0, n = 0, space_found = 0;

	if (strOG == NULL)
		return (NULL);

	while(strOG[m] != '\0')
	{
		if (strOG[m] != 32 || (strOG[m] == 32 && space_found))
		{
			if (space_found == 0)
				l = m;
			space_found = 1;
			n++;
		}
		m++;
	}	

	dup = malloc(sizeof(char) * (n + 1));
	if (dup == NULL)
	{
		perror("Malloc failure");
		return (NULL);
	}

	for (c = 0; c < n; c++)
	{
		dup[c] = strOG[l];
		l++;
	}

	dup[c] = '\0';
	return (dup);
}
