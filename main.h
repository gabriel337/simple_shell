#ifndef MAIN_H
#define MAIN_H

/*environment variable*/
extern char **environ;

/*libraries*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>
#include <dirent.h>

/*prototypes*/

/*free function*/
void free_grid(char **args);

/*print function*/
int print_env(void);

/*simple shell*/
char *_read_line(void);
char **_split_line(char *line);
int _execute(char **args);
int _launch(char **args);

/*string helpers*/
int _putchar(char c);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
int _getchar(void);
int _strlen(char *s);
#endif
