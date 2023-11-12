#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * strarrdup - a function that duplicates an array of
 * strings with an offset
 * @arrc: length of array to duplicate
 * @arrv: array of strings to duplicate assumed to be NULL
 * terminated
 * @offset: offset to apply
 * Note - the duplicate array will be NULL terminated
 * Return: the array on success, NULL on fail
 */

char **strarrdup(int arrc, char *arrv[], int offset)
{
	int i = offset;
	char **arrdup = malloc(sizeof(char *) * (arrc + 1 - offset));

	if (arrdup == NULL)
		return (NULL);

	while (*(arrv + i) != NULL)
	{
		*(arrdup + (i - offset)) = *(arrv + i);
		i++;
	}

	*(arrdup + (i - offset)) = NULL;

	return (arrdup);
}


/**
 * main - program that executes the command ls -l /tmp
 * in 5 different child processes. Each child should be
 * created by the same process (the father).
 * Wait for a child to exit before creating a new child.
 * @argc: length of command line arguments
 * @argv: array of command line arguments
 * @envp: environment arguments
 * Return: 0
 */

int main(int argc, char *argv[], char *envp[])
{
	int i = -1;
	pid_t childpid = 1;
	char **exec_argv;
	int status;
	int child_count = 5;

	if (argc < 2)
	{
		printf("Usage: %s <file-to-be-exec> <args-to-file>\n", argv[0]);
		return (-1);
	}

	exec_argv = strarrdup(argc, argv, 1);

	if (exec_argv == NULL)
		return (-1);

	while (i < child_count)
	{
		if (childpid == -1)
			return (-1);
		else if (childpid == 0)
		{
			if (execve(exec_argv[0], exec_argv, envp) == -1)
				return (-1);
		}

		else if (childpid > 0)
		{
			if (i > -1)
				wait(&status);
			if (i < child_count - 1)
				childpid = fork();
		}
		i++;
	}
	free(exec_argv);
	printf("%u: Parent exit\n", getpid());
	return (0);
}
