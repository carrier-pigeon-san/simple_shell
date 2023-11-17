#include "main.h"

/**
 * check_exit - sets the variable that holds the exit
 * status of a child process
 * @child_exitp: address of child_exit variable
 * @statep: address of state
*/
void check_exit(int *child_exitp, int *statep)
{
	if (WIFEXITED(*statep))
		*child_exitp = WEXITSTATUS(*statep);
	else
		*child_exitp = 0;
}
/**
 * parse_token - returns a pathname to a given executable file if it exists
 * @token: first token of command read from stdin
 * @cmd_arr: command array
 * @cmdstr: command string
 * @cmdLine: command line
 * @child_exitp: pointer to child exit status
 * Return: pathname or NULL if fails
 */
char *parse_token(char *token, char **cmd_arr,
					char *cmdstr, char *cmdLine, int *child_exitp)
{
	struct stat st;
	char *pathname, *dir;
	int i = 0, exit_s = 0;

	if (_strcmp(cmd_arr[0], "exit") == 0)
	{
		if (cmd_arr[1] != NULL)
			exit_s = _atoi(cmd_arr[1]);
		else
			exit_s = *child_exitp;
		while (cmd_arr[i] != NULL)
			free(cmd_arr[i++]);
		free(cmd_arr);
		free(cmdstr);
		free(cmdLine);
		fflush(stdin);
		fflush(stdout);
		_exit(exit_s);
	}

	if (stat(token, &st) == 0)
		return (pathname = _strdup(token));
	dir = get_path(token);
	if (dir == NULL)
		return (NULL);
	pathname = cat_file_path(token, dir);
	if (pathname == NULL)
		return (NULL);

	free(dir);
	return (pathname);
}
/**
 * parse_cmd - processes string read from the standard input stream
 * @cmdstr: string read from standard input stream
 * @av_0: name of first argument to main
 * @cmdLine: command line
 * @child_exitp: pointer to child exit status
 * Return: void
 */
void parse_cmd(char *cmdstr, char *av_0, char *cmdLine, int *child_exitp)
{
	int state, i;
	char **cmd_arr = make_list(cmdstr, " ");
	char *pathname = parse_token(cmd_arr[0], cmd_arr, cmdstr,
									cmdLine, child_exitp);
	pid_t proc, exit_state;

	(void)av_0;

	if (pathname)
	{
		proc = fork();
		if (proc == 0)
		{
			if (execve(pathname, cmd_arr, environ) == -1)
				perror("Error");
			_exit(255);
		}
		else if (proc > 0)
		{
			exit_state = wait(&state);
			check_exit(child_exitp, &state);
			if (exit_state == proc)
			{
				if (!WIFEXITED(state))
					perror("Proc-term error");
			}
			else
				perror("Wait error");
		}
		else
			perror("Fork error");
		free(pathname);
	}
	else
		perror(av_0);
	for (i = 0; cmd_arr[i] != NULL; i++)
		free(cmd_arr[i]);
	free(cmd_arr);
	free(cmdstr);
}
