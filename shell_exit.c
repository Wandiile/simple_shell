#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@m: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int m)
{
	int x, a;
	char *t = dest;

	x = 0;
	while (src[x] != '\0' && x < m - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < m)
	{
		a = x;
		while (a < m)
		{
			dest[a] = '\0';
			a++;
		}
	}
	return (t);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@m: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int x, a;
	char *t = dest;

	x = 0;
	a = 0;
	while (dest[x] != '\0')
		x++;
	while (src[a] != '\0' && a < m)
	{
		dest[x] = src[a];
		x++;
		a++;
	}
	if (a < m)
		dest[x] = '\0';
	return (t);
}

/**
 **_strchr - locates a character in a string
 *@t: the string to be parsed
 *@b: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *t, char b)
{
	do {
		if (*t == b)
			return (t);
	} while (*t++ != '\0');

	return (NULL);
}
