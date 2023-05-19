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

/* print env */
void print_env(char **env);

#endif
