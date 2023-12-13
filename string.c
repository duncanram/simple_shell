#include "shell.h"

/**
 * _strlen - computes length of a string
 * @s: string whose length is to be determined
 *
 * Return: integer length of the string
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - Compares 2 strings lexicographically.
 * @s1: The 1st string.
 * @s2: The 2nd string..
 *
 * Return: A negative value if s1 < s2,
 *         A positive value if s1 > s2,
 *         Zero if s1 == s2.
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks if the 'needle' starts with the 'haystack'..
 * @haystack:  string to search..
 * @needle: substring to find..
 *
 * Return: address of the next character of 'haystack' if found, or NULL.
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates 2 strings.
 * @dest: destination buffer.
 * @src:  source buffer..
 *
 * Return: pointer to the destination buffer..
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
