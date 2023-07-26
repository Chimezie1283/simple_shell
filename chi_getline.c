#include "header.h"

void *_realloc(void *potr, unsigned int old_size, unsigned int new_size);
void give_linepotr(char **linepotr, size_t *n, char *bufa, size_t b);
ssize_t _getline(char **linepotr, size_t *n, FILE *stream);

/**
 * _realloc - This reallocates a memory block using malloc/free.
 * @potr: The pointer to the memory allocated.
 * @old_size: The size of the allocated space for ptr.
 * @new_size: The size for the new memory block.
 *
 * Return: If new_size == old_size - potr.
 *         If new_size == 0 and potr is not NULL - NULL.
 *         Otherwise - The pointer to the reallocated memory block.
 */
void *_realloc(void *potr, unsigned int old_size, unsigned int new_size)
{
	void *memory;
	char *potr_copy, *fila;
	unsigned int indez;

	if (new_size == old_size)
		return (potr);

	if (potr == NULL)
	{
		memory = malloc(new_size);
		if (memory == NULL)
			return (NULL);

		return (memory);
	}

	if (new_size == 0 && potr != NULL)
	{
		free(potr);
		return (NULL);
	}

	potr_copy = potr;
	memory = malloc(sizeof(*potr_copy) * new_size);
	if (memory == NULL)
	{
		free(potr);
		return (NULL);
	}

	fila = memory;

	for (indez = 0; indez < old_size && indez < new_size; indez++)
		fila[indez] = *potr_copy++;

	free(potr);
	return (memory);
}

/**
 * give_linepotr - This reassigns the linepotr variable in _getline.
 * @linepotr: A buffer that store an input string.
 * @n: The size of linepotr.
 * @bufa: The string to assign to linepotr.
 * @b: The size of buffer.
 */
void give_linepotr(char **linepotr, size_t *n, char *bufa, size_t b)
{
	if (*linepotr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*linepotr = bufa;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*linepotr = bufa;
	}
	else
	{
		_strcpy(*linepotr, bufa);
		free(bufa);
	}
}

/**
 * _getline - This reads input from a stream.
 * @linepotr: A buffer to store the input.
 * @n: The size of lineptr.
 * @stream: The stream to read from.
 *
 * Return: The number of bytes read.
 */
ssize_t _getline(char **linepotr, size_t *n, FILE *stream)
{
	static ssize_t inpt;
	ssize_t reat;
	char c = 'x', *bufa;
	int r;

	if (inpt == 0)
		fflush(stream);
	else
		return (-1);
	inpt = 0;

	bufa = malloc(sizeof(char) * 120);
	if (!bufa)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && inpt == 0))
		{
			free(bufa);
			return (-1);
		}
		if (r == 0 && inpt != 0)
		{
			inpt++;
			break;
		}

		if (inpt >= 120)
			bufa = _realloc(bufa, inpt, inpt + 1);

		bufa[inpt] = c;
		inpt++;
	}
	bufa[inpt] = '\0';

	give_linepotr(linepotr, n, bufa, inpt);

	reat = inpt;
	if (r != 0)
		inpt = 0;
	return (reat);
}
