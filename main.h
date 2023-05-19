#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

/* parser */
char **parser(char *command);

/* executor */
int executor(char **args, char **env);

/* logical operator handler */
void LogicalOPhandler(char *argv, char **env);

/* ------ utils ------ */
/* file test */
int file_test(char *command, char **env, int verbose);

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
void combinePath(char *path, char *command, char *dst, unsigned int pathSize);

/* _strtok */
char *_strtok(char *str);

/* _strcmp */
int _strcmp(char *s1, char *s2);

/* _atoi */
int _atoi(char *s);

char *getVarValue(char *var, char **env);
int _strncmp(char *s1, char *s2, unsigned int n);
#endif
