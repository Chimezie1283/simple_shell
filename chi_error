#include "header.h"

char *errors_environ(char **args);
char *errors_one(char **args);
char *errors_two_exit(char **args);
char *errors_two_cd(char **args);
char *errors_two_synt(char **args);
/**
 * errors_environ - This creates an error message for shellto_env.
 * @args: This an array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *errors_environ(char **args)
{
	char *error, *hist_str;
	int lent;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	args--;
	lent = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
	error = malloc(sizeof(char) * (lent + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": Request denied\n");

	free(hist_str);
	return (error);
}

/**
 * errors_one - It creates an error message for shellto.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *errors_one(char **args)
{
	int lent;
	char *error;

	lent = _strlen(name) + _strlen(args[0]) + 13;
	error = malloc(sizeof(char) * (lent + 1));
	if (!error)
		return (NULL);

	_strcpy(error, "alias: ");
	_strcat(error, args[0]);
	_strcat(error, " empty path\n");

	return (error);
}

/**
 * errors_two_exit - This creates an error message for shellto_exit.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *errors_two_exit(char **args)
{
	char *error, *hist_str;
	int lent;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	lent = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
	error = malloc(sizeof(char) * (lent + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": exit: Unknown input: ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * errors_two_cd - This creates an error message for shellto_cd.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *errors_two_cd(char **args)
{
	char *error, *hist_str;
	int lent;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	lent = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (lent + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	if (args[0][0] == '-')
		_strcat(error, ": cd: Unknown entry ");
	else
		_strcat(error, ": cd: Request denied ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * errors_two_synt - This creates a message for syntax errors.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *errors_two_synt(char **args)
{
	char *error, *hist_str;
	int lent;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	lent = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 33;
	error = malloc(sizeof(char) * (lent + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": Program error: \"");
	_strcat(error, args[0]);
	_strcat(error, "\" Request denied\n");

	free(hist_str);
	return (error);
}
