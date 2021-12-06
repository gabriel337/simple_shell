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

/*prototypes*/
int get_env(void);
char *_read_line(void);
char **_split_line(char *line);
int _execute(char **args);
int _launch(char **args);
char *build(char *token, char *value);
int path_cmd(char **cmd);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
void _puts(char *str);
#endif
