#include "shell.h"

/**
 * _memset - fills a block of memory with a specified byte value.
 * @s: pointer to the memory area
 * @b: the byte value to fill the memory *s with..
 * @n: the number of bytes to fill..
 *
 * Return: A pointer to the memory area 's'
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - Frees a dynamically allocated array of strings
 * @pp: Pointer to the array of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates a previously allocated block of memory..
 * @ptr: pointer to the previously allocated block..
 * @old_size: size in bytes of the previous block..
 * @new_size: size in bytes of the new block..
 *
 * Return: Pointer to reallocated memory block, preserving its content
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
