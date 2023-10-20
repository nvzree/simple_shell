#include "shell.h"

/**
 * _strcmp - compares two string
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: int that tells num spaces in between
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _path - Checks for path
 * @path: 'path'
 * Return: 1 if true, 0 if false
 */

int _path(char *path)
{
	struct stat buf;

	return ((stat(path, &buf) == 0));
}


/**
 * which_path - Find full path name
 * @filename: file name
 * @path: path
 * Return: returns the full path name if found and 0 if not found.
 */

char *which_path(char *filename, char *path)
{
	char *path_copy;
	char *tokens[1024];
	char *path_name;
	int i = 0;

	if (path == NULL)
	{
		return (NULL);
	}
	path_copy = strdup(path);

	/* Tokenize the path */
	tokens[i] = strtok(path_copy, ":");

	for (i = 0; tokens[i] != NULL; i++)
	{
		path_name = malloc(strlen(tokens[i]) + strlen(filename) + 2);
		_strcpy(path_name, tokens[i]);
		_strcat(path_name, "/");
		_strcat(path_name, filename);

		if (_path(path_name))
		{
			free(path_copy);
			return (path_name);
		}

		free(path_name);
		tokens[i] = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * _getenv - get env variable given name
 * @var: name of the environment variable to get
 * Return: returns environment variable value on success
 */

char *_getenv(char *var)
{
	int var_len = _strlen(var);
	int i = 0;

	while (environ[i] != NULL)
	{
		if (_strncmp(var, environ[i], var_len) == 0 && environ[i][var_len] == '=')
		{
			return (environ[i] + var_len + 1);
		}
		i++;
	}

	return (NULL);
}

/**
 * _unsetenv - remove environment variable
 * @var: variable name to remove
 * Return: 0 on success
 */
int _unsetenv(char *var);
int _unsetenv(char *var)
{
	char **env = environ;
	int len, var_len;
	int environ_num = 0;
	int i = 0, j;
	char **arr;

	if (var == NULL)
		return (-1);
	while (*env != NULL)
	{
		environ_num++;
		env++;
	}

	arr = malloc((environ_num + 1) * sizeof(char *));
	if (arr == NULL)
		return (-1);

	env = environ;
	var_len = _strlen(var);
	while (*env != NULL)
	{
		if (_strncmp(var, *env, var_len) != 0 || (*env)[var_len] != '=')
		{
			len = _strlen(*env);
			arr[i] = malloc((len + 1) * sizeof(char));
			if (arr[i] == NULL)
			{
				for (j = 0; j < i; j++)
				{
					free(arr[j]);
				}
				free(arr);
				return (-1);
			}
			_strcpy(arr[i], *env);
			i++;
		}
		env++;
	}
	arr[i] = NULL;
	environ = arr;
	return (0);
}
