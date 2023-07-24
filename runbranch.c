#include "header.h"
/**
 * run_branch - function runs the branch
 * @args: double pointer to array of args
 * @handle: pointer to handle
 * Return: -1 on failure, otherwise branch process ID
 */
int run_branch(char **args, char *handle)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		prog(args, handle);
		perror(handle);
		exit(EXIT_FAILURE);
	}
	return (pid);
}
