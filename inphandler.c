#include "header.h"
/**
  * execute_input - main function to execute cmd
  * @input: input to execute
  * @handle: name of program
  * Return: returns -1 on failure
  */
int execute_input(char *input, char *handle)
{
	char *args[8];
	char *token;
	int i, pid;
	int flag, exit_flag;

	token = strtok(input, " \n\t");
	i = 0;
	while (token != NULL && i < 8)
	{
		token[strcspn(token, "\n")] = '\0';
		args[i] = token;
		token = strtok(NULL, " \n\t");
		i++;
	}
	args[i] = NULL;
	if (args[0] == NULL)
		return (0);
	if (strcmp(args[0], "exit") == 0)
	{
		exit_flag = 0;
		if (args[1] != NULL)
		{
			exit_flag = atoi(args[1]);
		}
		_exit(exit_flag);
	}
	pid = run_branch(args, handle);
	if (pid == -1)
		return (-1);
	flag = buffer_branch_procedure(pid);
	if (WIFEXITED(flag))
	{
		exit_flag = WEXITSTATUS(flag);
		return (exit_flag);
	}
		return (-1);
}
