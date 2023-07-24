#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_COMMAND_LENGTH 100
#define PATH "/bin"
int prog(char **args, char *handle);
int execute_input(char *input, char *);
void dunamicMode(char *argv[]);
void batching(char *argv[]);
int run_branch(char **args, char *handle);
int buffer_branch_procedure(pid_t pid);
extern char **environ;
#endif
