#include "main.h"
/**
 * write_err - composes an error message and writes it to output stream
 * @prog_nm - program name
 * @commd: command passed to program
 * @commd_idx: command count
 *
 * Return: void
 */
void write_err(char *prog_nm, char *commd, int commd_idx)
{
	int i, j,;
	char *err_str = _strdup(prog_nm);
	char *str = malloc(sizeof(char) * 2);

	for (i = 0; commd_idx != 0; i++)
	{
		int num = commd_idx % 10;
		str = _expand(str, sizeof(char) * 2, size;
		commd_idx /= 10;
	}
	
	for (j = 0; err_str[j] != '\0'; j++)
		;

	err_str = _expand(err_str, j + 1, j + 3)

	for (; i >= 0; i--)
	{

	}

}
