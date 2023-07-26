#include "header.h"

void helps_every(void);
void helps_alias(void);
void helps_cd(void);
void helps_exit(void);
void helps_help(void);

/**
 * helps_every - This displays all builtin shellto commands.
 */
void helps_every(void)
{
	char *masg = "Shellto\nThese are internally displayed shell command.\n";

	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "Type 'assist' see list.\nType 'assist name' search ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "more details of function 'name'.\n\n  alias   \t";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "alias [NAME[='VALUE'] ...]\n  cd    \tcd   ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "[DIRECTORY]\n  exit    \texit [STATUS]\n  env     \tenv";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "\n  setenv  \tsetenv [VARIABLE] [VALUE]\n  unsetenv\t";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "unsetenv [VARIABLE]\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
}

/**
 * helps_alias - This displays information on shellto command 'alias'.
 */
void helps_alias(void)
{
	char *masg = "alias: alias [NAME[='VALUE'] ...]\n\texecutes aliases.\n";

	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "\n\talias: Displays all aliases, each per line, in ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "format NAME='VALUE'.\n\talias name [name2 ...]:prints";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = " aliases name, name2, etc. each per line, in the ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "form NAME='VALUE'.\n\talias NAME='VALUE' [...]: Definition";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = " alias for each NAME and a given VALUE. If NAME ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "alias exist, replace its value with VALUE.\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
}

/**
 * helps_cd - This displays information on shellto command 'cd'.
 */
void helps_cd(void)
{
	char *masg = "cd: cd [DIRECTORY]\n\tcurrent directory changes for the";

	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = " executes DIRECTORY.\n\n\twhen argument is empty, the ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "executes command as cd $HOME. when argument '-' is";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = " provided, then command is executed as cd $OLDPWD.\n\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "\tThen update is made to environment variables PWD and OLDPWD ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "when change of directory is executed.\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
}

/**
 * helps_exit - This displays information on shellto command 'exit'.
 */
void helps_exit(void)
{
	char *masg = "exit: exit [STATUS]\n\tExit shell.\n\n\tThe ";

	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "STATUS use integer as argument exit shell.";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = " When no argument, command is interpreted as";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = " exit 0.\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
}

/**
 * helps_help - This displays information on shellto command 'help'.
 */
void helps_help(void)
{
	char *masg = "help: help\n\tdisplays all Shellto commands.\n";

	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "\n      assist [BUILTIN NAME]\n\tDetailed information on each ";
	write(STDOUT_FILENO, masg, _strlen(masg));
	masg = "programmed command.\n";
	write(STDOUT_FILENO, masg, _strlen(masg));
}
