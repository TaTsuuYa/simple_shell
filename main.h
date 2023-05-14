#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

char *FILE_NAME;

/* parser */
char **parser(char *command);

/* executor */
int executor(char **args, char **env);

/* logical operator handler */
void LogicalOPhandler(char *argv, char **env);

/* ------ utils ------ */
/* file test */
int file_test(char *command);

/* write error */
void write_err(char *file);

/* _strlen */
int _strlen(char *s);

/* argument counter */
int argcnt(char *command);

/* executable tester */
int isExecutable(char *command);

char *searchInPath(char *command, char **env);

/* path combiner */
void combinePath(char *path, char *command, char *dst);

#endif
