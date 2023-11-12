#include "main.h"
/**
 * _strtok - breaks a string into a sequence of tokens
 * @str: string to be tokenized
 * @delim: string containing delimeter characters
 *
 * Return: pointer to next token
 */
char *_strtok(char *str, const char *delim)
{
	int i, c, flag;
	char *temp;
	static char *cache;

	if (str != NULL)
		cache = str;
	if (*cache == '\0')
		return (NULL);
	for (c = 0; cache[c] != '\0'; c++)
	{
		flag = 0;
		for (i = 0; delim[i] != '\0'; i++)
			if (cache[c] == delim[i])
			{
				if (c == 0)
				{
					cache++;
					c--;
					continue;
				}
				flag = 1;
				break;
			}
		if (*cache == '\0')
			return (NULL);
		if (flag)
			break;
	}
	temp = malloc(sizeof(char) * (c + 1));
	if (temp == NULL)
		return (NULL);
	/* FLAG */
	for (i = 0; i < c; i++)
		if (cache[i])
			temp[i] = cache[i];
	temp[i] = '\0';
	cache += c + 1;
	return (temp);
}

