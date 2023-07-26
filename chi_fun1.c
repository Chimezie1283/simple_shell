#include "header.h"

/**
 * _strlen - This returns the length of a string.
 * @f: The pointer to the characters string.
 *
 * Return: The length of the character string.
 */
int _strlen(const char *f)
{
	int lent = 0;

	if (!f)
		return (lent);
	for (lent = 0; f[lent]; lent++)
		;
	return (lent);
}

/**
 * _strcpy - This function copies a string of src,
 *           to the buffer.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t l;

	for (l = 0; src[l] != '\0'; l++)
		dest[l] = src[l];
	dest[l] = '\0';
	return (dest);
}

/**
 * _strcat - This function adds two strings.
 * @dest: A Pointer to destination string.
 * @src: A Pointer to source string.
 *
 * Return: Pointer to destination string.
 */
char *_strcat(char *dest, const char *src)
{
	char *destpress;
	const char *srcpress;

	destpress = dest;
	srcpress =  src;

	while (*destpress != '\0')
		destpress++;

	while (*srcpress != '\0')
		*destpress++ = *srcpress++;
	*destpress = '\0';
	return (dest);
}

/**
 * _stringcat - This function adds two strings where m number
 *            of bytes are copied from src.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @m: n bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_stringcat(char *dest, const char *src, size_t m)
{
	size_t dest_lent = _strlen(dest);
	size_t j;

	for (j = 0; j < m && src[j] != '\0'; j++)
		dest[dest_lent + j] = src[j];
	dest[dest_lent + j] = '\0';

	return (dest);
}
