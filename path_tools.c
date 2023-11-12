#include "main.h"
/**
 * is_path - returns the directory to which a file belongs
 * @filename: name of file
 *
 * Return: absolute path to which file belongs or NULL
 */
char *get_path(const char *filename)
{
	int i, n;
	char *pathval, *temp = NULL;
	char **dirs;

	pathval = _getenv("PATH");
	printf("%s\n", pathval);
	dirs = make_list(pathval, ":");

	for (i = 0; dirs[i] != NULL; i++)
	{
		struct dirent *d_ent;
		DIR *dir = opendir(dirs[i]);
		if (dir == NULL)
			return (NULL);
		for (; (d_ent = readdir(dir)) != NULL;)
		{
			for (n = 0; filename[n] != '\0'; n++)
				if (filename[n] != d_ent->d_name[n])
					break;
			if (d_ent->d_name[n] == '\0')
			{
				temp = dirs[i];
				closedir(dir);
				break;
			}
		}
		closedir(dir);
	}
	for (i = 0; dirs[i] != NULL; i++)
		free(dirs[i]);
	free(dirs);
	free(pathval);
	if (temp)
		return (temp);
	return (NULL);
}
