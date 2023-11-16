#include "main.h"
/**
 * parse_token - returns a pathname to a given executable file if it exists
 * @token: first token of command read from stdin
 *
 * Return: pathname or NULL if fails
 */
char *parse_token(char *token)
{
	struct stat st;
	char *pathname, *dir;

	if (_strcmp(token, "exit") == 0)
	{
		kill(getpid(), SIGINT);
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
 *
 * Return: void
 */
void parse_cmd(char *cmdstr, char *av_0)
{
	int state, i;
	char **cmd_arr = make_list(cmdstr, " ");
	char *pathname = parse_token(cmd_arr[0]);
	pid_t proc, exit_state;

	(void)av_0;

	if (pathname)
	{
		proc = fork();
		if (proc == 0)
		{
			if (execve(pathname, cmd_arr, environ) == -1)
				perror("Error");
			/* FLAG */
			_exit(255);
		}
		else if (proc > 0)
		{
			exit_state = wait(&state);
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
	{
		perror(av_0);
	}
	for (i = 0; cmd_arr[i] != NULL; i++)
		free(cmd_arr[i]);
	free(cmd_arr);
	free(cmdstr);
}
