#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>

int executor(char **args, char **env);
void LogicalOPhandler(char *argv, char **env);
char **parser(char *command);

#endif
