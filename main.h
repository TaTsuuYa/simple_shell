#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

/* parser */
char **parser(char *command);
int argcnt(char *command);

/* executor */
int executor(char **args, char **env);

/* logical operator handler */
void LogicalOPhandler(char *argv, char **env);

#endif
