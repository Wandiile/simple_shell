#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - writes the character b to stderr
 * @b: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char b)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || c >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (b != BUF_FLUSH)
		buf[b++] = b;
	return (1);
}

/**
 * _putfd - writes the character b to given file descriptor
 * @b: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char b, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (b == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (b != BUF_FLUSH)
		buf[x++] = b;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
		return (0);
	while (*str)
	{
		x += _putfd(*str++, fd);
	}
	return (x);
}
