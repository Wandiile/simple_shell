#include "shell.h"

/**
 * **strtow - splits a string into words.
 * @str: the input string
 * @b: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *b)
{
	int x, a, j, n, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!b)
		b = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], b) && (is_delim(str[x + 1], b) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (x = 0, a = 0; a < numwords; a++)
	{
		while (is_delim(str[i], d))
			x++;
		j = 0;
		while (!is_delim(str[x + j], b) && str[x + j])
			j++;
		t[a] = malloc((j + 1) * sizeof(char));
		if (!t[a])
		{
			for (j = 0; j < a; j++)
				free(t[j]);
			free(t);
			return (NULL);
		}
		for (n = 0; n < j; n++)
			t[a][n] = str[x++];
		t[a][n] = 0;
	}
	t[a] = NULL;
	return (t);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @b: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char b)
{
	int x, a, j, n, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != b && str[x + 1] == b) ||
		    (str[x] != b && !str[x + 1]) || str[x + 1] == b)
			numwords++;
	if (numwords == 0)
		return (NULL);
	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (x = 0, a = 0; a < numwords; a++)
	{
		while (str[x] == b && str[x] != b)
			x++;
		j = 0;
		while (str[x + j] != b && str[x + j] && str[x + j] != b)
			j++;
		s[a] = malloc((j + 1) * sizeof(char));
		if (!t[a])
		{
			for (j = 0; j < a; j++)
				free(t[j]);
			free(t);
			return (NULL);
		}
		for (n = 0; n < j; n++)
			t[a][n] = str[x++];
		t[a][n] = 0;
	}
	t[a] = NULL;
	return (t);
}
