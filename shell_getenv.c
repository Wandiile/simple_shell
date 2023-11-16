#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Used to maintain function prototype.
 * Return: Always 0
 */
char **get_environ(info_s *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Used to maintain function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_s *info, char *var)
{
	list_s *node = info->env;
	size_s x = 0;
	char *a;

	if (!node || !var)
		return (0);

	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable
 * @info: Used to maintain function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_s *info, char *var, char *value)
{
	char *buf = NULL;
	list_s *node;
	char *a;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}