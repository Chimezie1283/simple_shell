#include "header.h"

int numba_lent(int numba);
char *_itoa(int numba);
int creates_err(char **args, int err);

/**
 * numba_lent - This counts the digit length of a number.
 * @num: The number to iterate.
 *
 * Return: The digit length.
 */
int numba_lent(int numba)
{
	unsigned int numba1;
	int lent = 1;

	if (numba < 0)
	{
		lent++;
		numba1 = numba * -1;
	}
	else
	{
		numba1 = numba;
	}
	while (numba1 > 9)
	{
		lent++;
		numba1 /= 10;
	}

	return (lent);
}

/**
 * _itoa - This converts an integer to a string.
 * @numba: The integer.
 *
 * Return: The converted string.
 */
char *_itoa(int numba)
{
	char *bufa;
	int lent = num_lent(numba);
	unsigned int numba1;

	bufa = malloc(sizeof(char) * (lent + 1));
	if (!bufa)
		return (NULL);

	bufa[lent] = '\0';

	if (numba < 0)
	{
		numba1 = numba * -1;
		bufa[0] = '-';
	}
	else
	{
		numba1 = numba;
	}

	lent--;
	do {
		bufa[lent] = (numba1 % 10) + '0';
		numba1 /= 10;
		lent--;
	} while (numba1 > 0);

	return (bufa);
}


/**
 * creates_err - This writes a custom error message to stderr.
 * @args: An array of arguments.
 * @err: The error value.
 *
 * Return: The error value.
 */
int creates_err(char **args, int err)
{
	char *error;

	switch (err)
	{
	case -1:
		error = errors_environ(args);
		break;
	case 1:
		error = error_one(args);
		break;
	case 2:
		if (*(args[0]) == 'e')
			error = errors_two_exit(++args);
		else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
			error = errors_two_synt(args);
		else
			error = errors_two_cd(args);
		break;
	case 127:
		error = errors_127(args);
		break;
	case 128:
		error = errors_128(args);
		break;
	}
	write(STDERR_FILENO, error, _strlen(error));

	if (error)
		free(error);
	return (err);

}
