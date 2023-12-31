#include "main.h"
/**
 * get_path - returns the directory to which a file belongs
 * @filename: name of file
 *
 * Return: absolute path to which file belongs or NULL
 */
char *get_path(const char *filename)
{
	int i, n;
	char *pathval, *temp = NULL;
	char **dirs;
	struct stat slink;
	struct dirent *d_ent;
	DIR *dir;

	pathval = _getenv("PATH");
	dirs = make_list(pathval, ":");

	for (i = 0; dirs[i] != NULL; i++)
	{
		if (lstat(dirs[i], &slink) == 0)
			if (S_ISLNK(slink.st_mode))
				continue;
		dir = opendir(dirs[i]);
		if (dir == NULL)
			return (NULL);
		for (; (d_ent = readdir(dir)) != NULL;)
		{
			for (n = 0; filename[n] != '\0'; n++)
				if (filename[n] != d_ent->d_name[n])
					break;
			if (d_ent->d_name[n] == '\0')
			{
				temp = _strdup(dirs[i]);
				break;
			}
		}
		closedir(dir);
	}
	free(pathval);
	for (i = 0; dirs[i] != NULL; i++)
		free(dirs[i]);
	free(dirs);
	if (temp)
		return (temp);
	return (NULL);
}
/**
 * cat_file_path - appends a file name to its directory
 * @filename: name of file
 * @pathname: path to file
 *
 * Return: absolute path to given file
 */
char *cat_file_path(const char *filename, char *pathname)
{
	int idx, count;
	char *path_cp = _strdup(pathname);

	for (idx = 0; path_cp[idx] != '\0'; idx++)
		;

	for (count = 0, idx++; filename[count] != '\0'; count++, idx++)
	{
		if (count == 0)
			path_cp[idx - 1] = '/';
		path_cp = _expand(path_cp, sizeof(char) * idx, sizeof(char) * (idx + 1));
		if (path_cp == NULL)
			return (NULL);
		/*FLAG*/
		path_cp[idx] = filename[count];
	}
	path_cp = _expand(path_cp, sizeof(char) * idx, sizeof(char) * (idx + 1));
	if (path_cp == NULL)
		return (NULL);
	/* FLAG */

	path_cp[idx] = '\0';
	return (path_cp);
}
