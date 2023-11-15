#include "shell.h"

/**
 * _env - prints the current environment
 * @info: Used to maintain constant function prototype.
 * Return: Always 0
 */
int _env(info_s *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments.
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_s *info, const char *name)
{
	list_s *node = info->env;
	char *a;

	while (node)
	{
		a = starts_with(node->str, name);
		if (a && *a)
			return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * _setenv - Initialize a new environment variable.
 * @info: Used to maintain constant function prototype.
 *  Return: Always 0
 */
int _setenv(info_s *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Used to maintain constant function prototype.
 *  Return: Always 0
 */
int _unsetenv(info_s *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Used to maintain constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_s *info)
{
	list_s *node = NULL;
	size_s x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}
