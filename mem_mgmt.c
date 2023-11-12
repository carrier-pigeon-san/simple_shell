#include "main.h"
/**
 * _expand - reassigns a larger memory location to a pointer
 * @loc: target pointer
 * @initial_size: old size of pointer
 * @new_size: new size of pointer post reassignment
 *
 * Return: larger pointer initialized with contents of target pointer
 */
void *_expand(void *loc, unsigned int initial_size, unsigned int new_size)
{
	size_t c;
	void *loc2;
	unsigned char *byte_loc, *byte_loc2;

	loc2 = malloc(sizeof(char) * new_size);
	if (loc2 == NULL)
		return (NULL);

	if (loc)
	{
		byte_loc = (unsigned char *)loc;
		byte_loc2 = (unsigned char *)loc2;

		for (c = 0; c < initial_size; c++)
			byte_loc2[c] = byte_loc[c];
		free(loc);
	}

	return (loc2);
}
