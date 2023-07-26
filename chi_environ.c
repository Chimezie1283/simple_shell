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
	char yc = '\n';

	if (!environ)
		return (-1);

	for (indez = 0; environ[indez]; indez++)
	{
		write(STDOUT_FILENO, environ[indez], _strlen(environ[indez]));
		write(STDOUT_FILENO, &yc, 1);
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
	char **env_var = NULL, **new_env, *new_val;
	size_t size;
	int indez;

	if (!args[0] || !args[1])
		return (create_error(args, -1));

	new_val = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!new_val)
		return (create_error(args, -1));
	_strcpy(new_val, args[0]);
	_strcat(new_val, "=");
	_strcat(new_val, args[1]);

	env_var = _getenv(args[0]);
	if (env_var)
	{
		free(*env_var);
		*env_var = new_val;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		;

	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env)
	{
		free(new_val);
		return (create_error(args, -1));
	}

	for (indez = 0; environ[indez]; indez++)
		new_env[indez] = environ[indez];

	free(environ);
	environ = new_env;
	environ[indez] = new_val;
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
	char **env_var, **new_env;
	size_t size;
	int indez, indez2;

	if (!args[0])
		return (create_error(args, -1));
	env_var = _getenv(args[0]);
	if (!env_var)
		return (0);

	for (size = 0; environ[size]; size++)
		;

	new_env = malloc(sizeof(char *) * size);
	if (!new_env)
		return (create_error(args, -1));

	for (indez = 0, indez2 = 0; environ[indez]; indez++)
	{
		if (*env_var == environ[indez])
		{
			free(*env_var);
			continue;
		}
		new_env[indez2] = environ[indez];
		indez2++;
	}
	free(environ);
	environ = new_env;
	environ[size - 1] = NULL;

	return (0);
}
