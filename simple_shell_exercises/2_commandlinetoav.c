#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _strchr -  a function that locates a character
 * in a string
 * @s: pointer to start of string
 * @c: character to locate
 * Return: a pointer to the first occurrence of
 * the character c in the string s, or NULL if the
 * character is not found
 * Note - ignores character if it is at start or end
 * also ignores character if previous character is the
 * same
 */

char *_strchr(int *index_ptr, char *s, char *c)
{
	char *location = NULL;
	int i = *index_ptr;
	
	while (*(s + i) != '\0')
	{
		if (*(s + i) == *c)
		{
			if (i > 0 && *(s + i - 1)
				!= *c && *(s + i + 1)
					!= '\0')
			{
				location = s + i;
				break;
			}
		}

		i++;
	}
	*index_ptr = ++i;

	return (location);
}

/**
 * strchrcount - a function that counts the number of
 * times a character has been found in a string
 * @str: string to be searched through
 * @c: character to be searched for
 * Return: number of times the character has been found
 */

int strchrcount(char *str, char *c)
{
	int i = 0;
	int index = 0;
	char *str_local = _strchr(&index, str, c);

	while (str_local != NULL)
	{
		str_local = _strchr(&index, str, c);
		i++;
	}
	return (i);
}

/**
 * strtoarr - a function that splits a string and returns
 * an array of each word of the string
 * @str: string to be split
 * @delim: delimiter to be used
 * Return: an array of each word of the string str
 */

char **strtoarr(char *str, char *delim)
{
    int i = 0;
    char *temp;
    int nwords = strchrcount(str, delim) + 1;
    printf("nwords: %d\n", nwords);
    
    char **strarr = malloc(sizeof(char *) * nwords);
    if (strarr == NULL) {
        return NULL; // Handle memory allocation failure
    }

    temp = strtok(str, delim);

    while (temp != NULL)
    {
        *(strarr + i) = strdup(temp); // Allocate and copy the string
        temp = strtok(NULL, delim);
        i++;
    }

    return strarr;
}
	

/**
 * main - entry point
 * Return: always 0
 */

int main(void)
{
	int i = 0;
	char *delim = ",";
	char *str = ",hello,,hi,bye,h";
	char **strarr = strtoarr(str, delim);
	int nwords = strchrcount(str, delim);
	printf("commas found: %d\n", nwords);
	printf("words found: \n");

	while (i < nwords)
	{
		printf("%s \n", *(strarr + i));
	}

	free(strarr);

	return (0);
}
