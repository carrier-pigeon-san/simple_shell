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
 * exit_param_handler - handles an exit parameter
 * @av_0: program name
 * @exit_param: exit param provided
 * Return: exit status
*/

int exit_param_handler(char *av_0, char *exit_param)
{
	int temp = _atoi(exit_param);

	if (temp > 0)
		return (temp);
	else if (temp == 0 && exit_param[0] == 48)
		return (temp);
	else if (temp == 0 && exit_param[0] != 48)
		fprintf(stderr, "%s: 1: exit: Illegal number: %s\n", av_0, exit_param);
	else
		fprintf(stderr, "%s: 1: exit: Illegal number: %d\n", av_0, temp);
	return (2);
}

char * _print_env()
{
	int i = 0;

	if (!shlvl_check())
		printf("SHLVL=0\n");
	while (environ[i] != NULL)
		printf("%s\n", environ[i++]);
	
	return "Printed";
}
/**
 * parse_token - returns a pathname to a given executable file if it exists
 * @token: first token of command read from stdin
 * @cmd_arr: command array
 * @cmdstr: command string
 * @cmdLine: command line
 * @child_exitp: pointer to child exit status
 * @av_0: argument name
 * Return: pathname or NULL if fails
 */
char *parse_token(char *token, char **cmd_arr,
					char *cmdstr, char *cmdLine, int *child_exitp,
						char *av_0)
{
	struct stat st;
	char *pathname, *dir;
	int i = 0, exit_s = 0;

	if (_strcmp(cmd_arr[0], "exit") == 0)
	{
		if (cmd_arr[1] != NULL)
			exit_s = exit_param_handler(av_0, cmd_arr[1]);
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
	else if (_strcmp(cmd_arr[0], "env") == 0)
		return (_print_env());

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
									cmdLine, child_exitp, av_0);
	pid_t proc, exit_state;

	(void)av_0;

	if (pathname && _strcmp(pathname, "Printed") != 0)
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
	else if (pathname == NULL)
		perror(av_0);
	for (i = 0; cmd_arr[i] != NULL; i++)
		free(cmd_arr[i]);
	free(cmd_arr);
	free(cmdstr);
}
