#include "main.h"
/**
 * main - entry point to UNIX command interpreter
 *
 * Return: 0 (Succes)
 */
int main()
{
	char *cmdLine;
	ssize_t rd_cmd;

	cmdLine = malloc(sizeof(char) * BYTES_SIZE);
	if (cmdLine == NULL)
		return (-1);

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		rd_cmd = _getline(&cmdLine);
		if (rd_cmd == -1)
		{
			free (cmdLine);
			exit(EXIT_FAILURE);
			/*FLAG*/
		}
		if (rd_cmd > 0)
			parse_cmd(cmdLine, *av);
		printf("%s\n", cmdLine);
	}
	free(cmdLine);
	return (0);
}
