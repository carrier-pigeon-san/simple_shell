#include "main.h"
/**
 * make_list - builds an array of strings from tokenizing a string
 * @strOG: original string
 * @breaker: string of delimiter characters
 *
 * Return: an array of tokens of the original string
 */
char **make_list(char *strOG, char *breaker)
{
	char **vector;
	char *element;
	size_t len = 1;
	int c = 0;

	vector = malloc(sizeof(char *) * len);
	if (vector == NULL)
		return (NULL);

	element = _strtok(strOG, breaker);

	while (element != NULL)
	{
		vector = _expand(vector, sizeof(char *) * len, sizeof(char *) * (len + 1));
		if (vector == NULL)
			return (NULL);
		vector[c] = element;
		element = _strtok(NULL, breaker);
		len++;
		c++;
	}

	/*
	*vector = _expand(vector, sizeof(char *) * len, sizeof(char *) * (len + 1));
	*if (vector == NULL)
	*	return (NULL);
	*/
	vector[c] = NULL;

	return (vector);
}
