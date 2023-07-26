#include "header.h"

void helps_environ(void);
void helps_setenviron(void);
void helps_unsetenviron(void);
void helps_hist(void);

/**
 * helps_environ - This displays information on shellto command.
 */
void helps_environ(void)
{
	char *masg = "env: env\n\tDisplays current environment.\n";

	write(STDOUT_FILENO, masg, _strlen(masg));
}

/**
 * helps_setenviron - This displays information on shellto command.
 */
void helps_setenviron(void)
{
	char *masg = "setenv: setenv [VARIABLE] [VALUE]\n\tmakes a new";

	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "displays or modifies environment variable.\n\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "\tif error occurs, displays message to stderr.\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
}

/**
 * helps_unsetenviron - This displays information on shellto command.
 */
void helps_unsetenviron(void)
{
	char *masg = "unsetenv: unsetenv [VARIABLE]\n\tDeletes ";

	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "environment variable.\n\n\tif error, displays a ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "prints to stderr.\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
}
