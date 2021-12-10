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
#include <stdarg.h>


/*prototypes*/

/*free function*/
void free_grid(char **args);

/*print function*/

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
char *_strcat(char *dest, char *src);

/*path*/

char **get_path(char *tokens);

/*printf*/

int _printf(const char *format, ...);
int get_print(char c, va_list *vl);

int print_string(char *);
int print_int(int);

int accInt(va_list *);
int accString(va_list *);
int accChar(va_list *);
int accPercent(va_list *vl);
/**
 * struct flag - flag object
 * @letter: flag char
 * @print: print pointer
 */

typedef struct flag
{
	char letter;
	int (*print)(va_list *);
} find_flag;
#endif
