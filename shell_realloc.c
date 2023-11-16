#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@t: the pointer to the memory area
 *@c: the byte to fill *s with
 *@m: the amount of bytes to be filled
 *Return: (t) a pointer to the memory area s
 */
char *_memset(char *t, char c, unsigned int m)
{
	unsigned int x;

	for (x = 0; x < m; x++)
		t[x] = c;
	return (t);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **b = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(b);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to da ol'block nameen.
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
