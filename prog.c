#include "header.h"
/**
 * prog - function creates paths and check
 * @args: double pointer to args
 * @handle: pointer to program name
 * Return: int of status for success or fail
 */
int prog(char **args, char *handle)
{
	int status;
	char path[20] = PATH;

	if ((int) strcspn(args[0], "/") == 0)
	{
		status = execve(args[0], args, environ);
	}
	else if ((int) strcspn(args[0], ".") == 0)
	{
		status = execve(args[0], args, environ);
	}
	else
	{
		strcat(path, "/");
		strcat(path, args[0]);
		status = execve(path, args, environ);
	}
	if (status == -1)
	{
		if (errno == ENOENT)
		{
			fprintf(stderr, "%s: %d: %s: not found\n", handle, errno, args[0]);
			fflush(stderr);
			exit(127);
		}
		else
			perror("execve");
		exit(EXIT_FAILURE);
	}
	return (status);
}
