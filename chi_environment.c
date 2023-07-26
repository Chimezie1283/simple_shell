#include "header.h"

char **_coppienv(void);
void frees_env(void);
char **_getenv(const char *var);

/**
 * _coppienv - This creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */
char **_coppienv(void)
{
	char **new_env;
	size_t size;
	int indez;

	for (size = 0; environ[size]; size++)
		;

	new_env = malloc(sizeof(char *) * (size + 1));
	if (!new_env)
		return (NULL);

	for (indez = 0; environ[indez]; indez++)
	{
		new_env[indez] = malloc(_strlen(environ[indez]) + 1);

		if (!new_env[indez])
		{
			for (indez--; indez >= 0; indez--)
				free(new_env[indez]);
			free(new_env);
			return (NULL);
		}
		_strcpy(new_env[indez], environ[indez]);
	}
	new_env[indez] = NULL;

	return (new_env);
}

/**
 * frees_env - This frees the the environment copy.
 */
void frees_env(void)
{
	int indez;

	for (indez = 0; environ[indez]; indez++)
		free(environ[indez]);
	free(environ);
}

/**
 * _getenv - This gets an environmental variable.
 * @vary: This the name of the environmental variable gotten.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(const char *vary)
{
	int indez, lent;

	lent = _strlen(vary);
	for (indez = 0; environ[indez]; indez++)
	{
		if (strncmp(vary, environ[indez], lent) == 0)
			return (&environ[indez]);
	}

	return (NULL);
}
