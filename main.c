#include "main.h"

int main(void)
{
	char *filename = "pwd";
	char *direx = get_path(filename);
	if (direx)
	{
		printf("%s\n", direx);
		free(direx);
	}
	else
		perror("Unable to get path.\n");
	return (0);
}
