#include "shell.h"

/**
 * get_environ - retrieves a copy of the string array
 * containing environment variables.
 * @info: a structure containing potential arguments. This structure ensures
 *        a consistent function prototype
 *
 * This function is responsible for returning a copy of the
 * string array that holds
 * environment variables. It always returns 0.
 *
 * Return: always returns 0
 */

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - deletes an environment variable.
 * @info: a structure containing potential arguments. This structure ensures
 *        a consistent function prototype
 * @var: the string representing the environment variable to be removed.
 *
 * This function is used to delete an environment variable specified by 'var'.
 * It returns 1 upon successful deletion, and 0 otherwise
 *
 * Return: 1 on successful deletion, 0 otherwise
 */

int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - creates a new environment variable or modifies an existing one.
 * @info: a structure containing potential arguments. This structure ensures
 *        a consistent function prototype.
 * @var: the string representing the environment variable property.
 * @value: the string representing the value of the environment variable.
 *
 * This function is used to initialize a new environment
 * variable or modify an existing one.
 * It always returns 0.
 *
 * Return: always returns 0
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

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
		p = starts_with(node->str, var);
		if (p && *p == '=')
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