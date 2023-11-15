#include "main.h"
/**
 * _getline - reads an entire line from the standard input
 * @strptr: address to buffer
 *
 * Return: number of characters read
 */
ssize_t _getline(char **strptr)
{
	ssize_t rd_char;
	size_t bytes_read = 0, len = BYTES_SIZE;

	while (1)
	{
		rd_char = read(STDIN_FILENO, *strptr + bytes_read, sizeof(char));
		if (rd_char == -1)
		{
			if (*strptr != NULL)
				free(*strptr);
			return (-1);
		}
		else if (rd_char == 0)
		{
			if (bytes_read == 0)
			{
				free(*strptr);
				exit(0);
			}
			(*strptr)[bytes_read] = '\0';
			return (rd_char);
		}
		bytes_read++;
		if ((*strptr)[bytes_read - 1] == '\n')
		{
			(*strptr)[bytes_read] = '\0';
			return (rd_char);
		}
		if (bytes_read >= len)
		{
			char *new_buffer = _expand(*strptr, len, len + len);

			if (new_buffer == NULL)
			{
				free(*strptr);
				return (-1);
			}
			/*free(*strptr);*/
			*strptr = new_buffer;
			len += BYTES_SIZE;
		}
	}
	return (rd_char);
}
