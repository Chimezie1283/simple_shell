#include "header.h"

char *error_128(char **args);
char *error_129(char **args);

/**
 * error_128 - This creates an error message for permission denied.
 * @args: The array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_128(char **args)
{
	char *errorz, *hist_str;
	int lent;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	lent = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
	errorz = malloc(sizeof(char) * (lent + 1));
	if (!errorz)
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
	return (errorz);
}

/**
 * error_129 - This creates an error message.
 * @args: The array of arguments passed to the command.
 *
 * Return: The error string.
 */
char *error_129(char **args)
{
	char *errorz, *hist_str;
	int lent;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	lent = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 16;
	errorz = malloc(sizeof(char) * (lent + 1));
	if (!errorz)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": unknown command\n");

	free(hist_str);
	return (errorz);
}
