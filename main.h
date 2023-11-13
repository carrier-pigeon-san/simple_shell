#ifndef MAIN_H
#define MAIN_H

#define BYTES_SIZE 64

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <dirent.h>
#include <signal.h>
#include <errno.h>

ssize_t _getline(char **strptr);
void *_expand(void *loc, unsigned int initial_size, unsigned int new_size);
char *_strtok(char *str, const char *delim);
char **make_list(char *strOG, char *breaker);
char *_getenv(const char *varname);
char *_strdup(const char *strOG);
void parse_cmd(char *cmdstr, char *av_0);
char *get_path(const char *filename);
char *cat_file_path(const char *filename, char *filepath);

#endif /* MAIN_H */
