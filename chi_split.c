#include "header.h"

int tok_lent(char *stry, char *delim);
int kount_tok(char *stry, char *delim);
char **_strtok(char *lines, char *delim);

/**
 * tok_lent - This locates delimiter index to mark the end
 *             of the first token a string.
 * @stry: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the intitial token pointed to the string.
 */
int tok_lent(char *stry, char *delim)
{
	int indez = 0, lent = 0;

	while (*(stry + indez) && *(stry + indez) != *delim)
	{
		lent++;
		indez++;
	}

	return (lent);
}

/**
 * kount_tok - This function counts number of
 *                words contained within a string.
 * @stry: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */
int kount_tok(char *stry, char *delim)
{
	int indez, toks = 0, lent = 0;

	for (indez = 0; *(stry + indez); indez++)
		lent++;

	for (indez = 0; indez < lent; indez++)
	{
		if (*(stry + indez) != *delim)
		{
			toks++;
			indez += tok_lent(stry + indez, delim);
		}
	}

	return (toks);
}

/**
 * _strtok - This function tokenizes string.
 * @lines: The string.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *lines, char *delim)
{
	char **potr;
	int indez = 0, toks, t, letters, l;

	toks = kount_tok(lines, delim);
	if (toks == 0)
		return (NULL);

	potr = malloc(sizeof(char *) * (toks + 2));
	if (!potr)
		return (NULL);

	for (t = 0; t < toks; t++)
	{
		while (lines[indez] == *delim)
			indez++;

		letters = tok_lent(lines + indez, delim);

		potr[t] = malloc(sizeof(char) * (letters + 1));
		if (!potr[t])
		{
			for (indez -= 1; indez >= 0; indez--)
				free(potr[indez]);
			free(potr);
			return (NULL);
		}

		for (l = 0; l < letters; l++)
		{
			potr[t][l] = lines[indez];
			indez++;
		}

		potr[t][l] = '\0';
	}
	potr[t] = NULL;
	potr[t + 1] = NULL;

	return (potr);
}
