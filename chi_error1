#include "header.h"

char *errors_127(char **args);
char *errors_128(char **args);

/**
 * errors_127 - This creates message for permission denied.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *errors_127(char **args)
{
	char *error, *hist_str;
	int lent;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

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
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": Permission declined\n");

	free(hist_str);
	return (error);
}

/**
 * errors_128 - This creates message for command not found.
 * @args: An array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *errors_128(char **args)
{
	char *error, *hist_str;
	int lent;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	lent = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 16;
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
	_strcat(error, ": Request not found\n");

	free(hist_str);
	return (error);
}
