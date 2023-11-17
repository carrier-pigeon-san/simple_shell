#include "main.h"
/**
 * cat_delim - appends delimiter to a string
 * @str: given str
 * @e: length of str
 *
 * Return: void
 */
void cat_delim(char str[], size_t *e)
{
	str[*e] = ':';
	(*e)++;
	str[*e] = ' ';
	(*e)++;
}
/**
 * num2str - converts integer to string;
 * @str: buffer
 * @cmdi: given integer
 * @c: character count
 *
 * Return: string of digits
 */
char *num2str(int cmdi, size_t *c)
{
	size_t i, n, p, s = 1;
	char temp;
	char *str = malloc(sizeof(char) * s);

	if (str == NULL)
		exit(EXIT_FAILURE);
	for (; cmdi != 0; (*c)++, s++)
	{
		int num = cmdi % 10;

		str = _expand(str, sizeof(char) * s, sizeof(char) * (s + 1));
		if (str == NULL)
			exit(EXIT_FAILURE);
		str[*c] = num + '0';
		cmdi /= 10;
	}
	str[*c] = '\0';
	for (i = 0, n = p = *c, p--; i < n / 2; p--, i++)
	{
		temp = str[i];
		str[i] = str[p];
		str[p] = temp;
	}

	return (str);
}
char *strscat(char *dest, char *src, size_t s)
{
	int c, i;
	char *msg = malloc(sizeof(char) * s);

	if (msg == NULL)
		return (NULL);

	for (c = 0; dest[c] != '\0'; c++)
		msg[c] = dest[c];
	for (i = 0; src[i] != '\0'; i++, c++)
		msg[c] = src[i];
	msg[c] = '\0';
	if (dest)
		free(dest);
	return (msg);
}
/**
 * write_err - composes an error message and writes it to output stream
 * @prog_nm: program name
 * @commd: command passed to program
 * @commd_idx: command count
 *
 * Return: void
 */
void write_err(char *prog_nm, char *commd, int commd_idx)
{
	size_t size, c, e, j = 0;
	char *err_msg = NULL, *numstr;
	char *delim = ": ", *msg = "not found\n";

	(void)commd;

	numstr = num2str(commd_idx, &j);
	c = _strlen(commd);
	e = _strlen(prog_nm);

	size = e + 3;
	err_msg = strscat(_strdup(prog_nm), delim, size);
	size += j;
	err_msg = strscat(err_msg, numstr, size);
	size += 2;
	err_msg = strscat(err_msg, delim, size);
	size += c;
	err_msg = strscat(err_msg, commd, size);
	size += 2;
	err_msg = strscat(err_msg, delim, size);
	size += 10;
	err_msg = strscat(err_msg, msg, size);

	write (STDERR_FILENO, err_msg, _strlen(err_msg));
	free(numstr);
	free(err_msg);
}
