#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_read_line(void);
char **_split_line(char *line);
int _execute(char **args);
int _launch(char **args);
#endif
