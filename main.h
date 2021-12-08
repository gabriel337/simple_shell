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
void free_grid(char **args);
int print_env(void);
char *_strncat(char *dest, char *src, int len);
char *read_dir( struct dirent *s, char *filename, int len, char *file_path);
char *get_env(char **args);
char *_strncat(char *dest, char *src, int len);
char *_read_line(void);
char **_split_line(char *line);
int _execute(char **args);
int _launch(char **args);
char *build(char *token, char *value);
int path_cmd(char **cmd);
int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _exit_strcmp(char *s1);
void _puts(char *str);
int _getchar(void);
int _strlen(char *s);
#endif
