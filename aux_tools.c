#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if strings are equal
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int r_value = 0;

	while ((*(s1 + i) != '\0') && (*(s2 + i) != '\0'))
	{
		if ((*(s1 + i) > *(s2 + i)) || (*(s1 + i) < *(s2 + i)))
		{
			r_value = *(s1 + i) - *(s2 + i);
			break;
		}
		i++;
	}
	return (r_value);
}
