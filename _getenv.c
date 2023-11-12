#include "main.h"
/**
 * _getenv = returns the value of a given environmental variable
 * @varname: name of given environmental variable
 * 
 * Return: pointer to value of variable or NULL if no match
 */
char *_getenv(const char *varname)
{
	int i = 0, j;
	char *temp;

	while (environ[i] != NULL)
	{
		j = 0;
		while (varname[j] != '\0')
		{
			if (environ[i][j] != varname[j])
				break;
			j++;
		}
		if (environ[i][j] == '=')
		{
			printf("environ[i] + j + 1: %s\n", environ[i] + j + 1);
			temp = _strdup(environ[i] + j + 1);
			printf("temp: %p\n", temp);
			printf("temp content: %s\n", temp);
			return (temp);
		}
		i++;
	}
	return (NULL);
}
