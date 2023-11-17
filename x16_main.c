#include "main.h"
/**
 * main - entry point to UNIX command interpreter
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 (Succes)
 */
int main(int ac, char **av)
{
	char *cmdLine, *dupcmd;
	ssize_t rd_cmd;
	int child_exit;

	(void)ac;

	cmdLine = malloc(sizeof(char) * BYTES_SIZE);
	if (cmdLine == NULL)
	{
		perror("Error");
		return (-1);
	}

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		rd_cmd = _getline(&cmdLine);
		if (rd_cmd == -1)
		{
			free(cmdLine);
			return (-1);
			/*FLAG*/
		}
		else if (rd_cmd > 0)
		{
			dupcmd = _strstrp(cmdLine);
			rm_nwln(dupcmd);
			if (*dupcmd == '\0')
			{
				free(dupcmd);
				continue;
			}
			parse_cmd(dupcmd, av[0], cmdLine, &child_exit);
		}
	}
	free(dupcmd);
	free(cmdLine);
	return (0);
}
