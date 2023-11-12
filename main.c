#include "main.h"

int main(void)
{
	char *filename = "cd";
	char *dir = get_path(filename);
	printf("%s\n", dir);
	return (0);
}
