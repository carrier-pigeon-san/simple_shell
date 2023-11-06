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
			/*
			 * FLAG
			 */
		}
		printf("%s\n", cmdLine);
	}
	free(cmdLine);
	return (0);
}
void *_expand(void *loc, unsigned int initial_size, unsigned int current_size)
{
	size_t c;
	void *loc2;
	unsigned char *byte_loc, *byte_loc2;

	loc2 = malloc(sizeof(char) * current_size);
	if (loc2 == NULL)
		return (NULL);

	byte_loc = (unsigned char *)loc;
	byte_loc2 = (unsigned char *)loc2;

	for (c = 0; c < initial_size; c++)
		byte_loc2[c] = byte_loc[c];

	return (loc2);
}

