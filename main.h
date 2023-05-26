#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

/* parser */
char **parser(char *command, char **env);

/* executor */
int executor(char **args, char **env, int LINE);

/* logical operator handler */
void LogicalOPhandler(char *argv, char **env, int LINE);

/* handle built-ins */
int handle_builtins(char **args, char **env);

/* ------ utils ------ */
/* file test */
int file_test(char *command, char **env, int verbose);

/* write std */
ssize_t write_std(char *txt, int field);

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

/* print env */
void print_env(char **env);

void handleCD(char **args, char **env);

/* buit-in exit */
void builtin_exit(int mode, int status);

/* write int */
void write_int(int i, int field);

void no_file_msg(char **env, int LINE, char *cmd);

#endif

