#include "shell.h"

char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strchr - This locates a character in the string.
 * @s: The string to be searched.
 * @c: The character to be located.
 *
 * Return: If c is found - a pointer to the first occurence.
 *         If c is not found - NULL.
 */
char *_strchr(char *s, char c)
{
	int indez;

	for (indez = 0; s[indez]; indez++)
	{
		if (s[indez] == c)
			return (s + indez);
	}

	return (NULL);
}

/**
 * _strspn - This gets the length of a substring.
 * @s: The string to be searched.
 * @accept: The prefix to be measured.
 *
 * Return: The number of bytes in s which
 *         consist only of bytes from accept.
 */
int _strspn(char *s, char *accept)
{
	int bytez = 0;
	int indez;

	while (*s)
	{
		for (indez = 0; accept[indez]; indez++)
		{
			if (*s == accept[indez])
			{
				bytez++;
				break;
			}
		}
		s++;
	}
	return (bytez);
}

/**
 * _strcmp - This function compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 = s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - This compares two strings.
 * @s1: Pointer to a string.
 * @s2: Pointer to a string.
 * @n: The first n bytes of the strings to compare.
 *
 * Return: Less than 0 if s1 is shorter than s2.
 *         0 if s1 and s2 match.
 *         Greater than 0 if s1 is longer than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t j;

	for (j = 0; s1[j] && s2[j] && j < n;ji++)
	{
		if (s1[j] > s2[j])
			return (s1[j] - s2[j]);
		else if (s1[j] < s2[j])
			return (s1[j] - s2[j]);
	}
	if (j == n)
		return (0);
	else
		return (-15);
}
