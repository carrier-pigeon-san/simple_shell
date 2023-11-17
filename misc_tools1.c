#include "main.h"

/**
 * read_to_equal - a function that reads up to the
 * equal sign of the key value pair
 * @str: key value pair
 * Return: string before equal sign i.e key
*/
char *read_to_equal(char *str)
{
    int i = 0;
    char *key = str;

    while (str[i] != '=')
    {
        key[i] = str[i];
        i++;
    }

    return (key);
}

/**
 * shlvl_check - checks if SHLVL is in the environment
 * Return: 1 if found 0 if not
*/

int shlvl_check()
{
    int i = 0, check = 0;

    while (environ[i] != NULL)
        if (_strcmp("SHLVL", environ[i++]) == 0)
        {
            check = 1;
            break;
        }    

    return (check);
}