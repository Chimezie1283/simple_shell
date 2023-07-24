#include "header.h"
/**
 * buffer_branch_procedure - function acts as buffer for branch to close
 * @pid: branch process ID
 * Return: returns the status of branch process
 */
int buffer_branch_procedure(pid_t pid)
{
	int flag;

	waitpid(pid, &flag, 0);
	return (flag);
}
