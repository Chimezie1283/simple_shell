#include "header.h"

int shellto_env(char **args, char __attribute__((__unused__)) **vront);
int shellto_setenv(char **args, char __attribute__((__unused__)) **vront);
int shellto_unsetenv(char **args, char __attribute__((__unused__)) **vront);

/**
 * shellto_env - This prints the current environment.
 * @args: An array of arguments passed to the shell.
 * @vront: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - -1.
 *	   Otherwise - 0.
 *
 * Description: Prints one variable per line in the
 *              format 'variable'='value'.
 */
int shellto_env(char **args, char __attribute__((__unused__)) **vront)
{
	int indez;
	char nc = '\n';

	if (!environ)
		return (-1);

	for (indez = 0; environ[indez]; indez++)
	{
		write(STDOUT_FILENO, environ[indez], _stringlen(environ[indez]));
		write(STDOUT_FILENO, &nc, 1);
	}

	(void)args;
	return (0);
}

/**
 * shellto_setenv - This adds an environmental variable.
 * @args: An array of arguments passed to the shell.
 * @vront: A double pointer to the beginning of args.
 * Description: args[1] is the name of the new or existing PATH variable.
 *              args[2] is the value to set the new or changed variable to.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellto_setenv(char **args, char __attribute__((__unused__)) **vront)
{
	char **env_var = NULL, **new_environ, *new_value;
	size_t size;
	int indez;

	if (!args[0] || !args[1])
		return (create_error(args, -1));

	new_value = malloc(_stringlen(args[0]) + 1 + _stringlen(args[1]) + 1);
	if (!new_value)
		return (create_error(args, -1));
	_stringcpy(new_value, args[0]);
	_stringcat(new_value, "=");
	_stringcat(new_value, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_value;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 2));
	if (!new_environ)
	{
		free(new_value);
		return (create_error(args, -1));
	}

	for (indez = 0; environ[indez]; indez++)
		new_environ[indez] = environ[indez];

	free(environ);
	environ = new_environ;
	environ[indez] = new_value;
	environ[indez + 1] = NULL;

	return (0);
}

/**
 * shellto_unsetenv - This Deletes an environmental variable.
 * @args: An array of arguments passed to the shell.
 * @vront: A double pointer to the beginning of args.
 * Description: args[1] is the PATH variable to remove.
 *
 * Return: If an error occurs - -1.
 *         Otherwise - 0.
 */
int shellto_unsetenv(char **args, char __attribute__((__unused__)) **vront)
{
	char **env_var, **new_environ;
	size_t size;
	int indez, indez2;

	if (!args[0])
		return (create_error(args, -1));
	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * size);
	if (!new_environ)
		return (create_error(args, -1));

	for (indez = 0, indez2 = 0; environ[indez]; indez++)
	{
		if (*env_var == environ[indez])
		{
			free(*env_var);
			continue;
		}
		new_environ[indez2] = environ[indez];
		indez2++;
	}
	free(environ);
	environ = new_environ;
	environ[size - 1] = NULL;

	return (0);
}
