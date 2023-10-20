#include "shell.h"

/**
 * check_env - checks for environment functions
 * @n: number of arguments passed
 * @argv: command line arguments array
 * @tokens: list of command arguments
 * @exit_stat: exit status
 * Return: void
 */
int check_env(int n, char **argv, char **tokens, int *exit_stat);
int check_env(int n, char **argv, char **tokens, int *exit_stat)
{
	char **env = environ;

	if (n < 1)
	{
		return (2);
	}
	if (strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
		{
			if (atoi(tokens[1]))
			{
				if (atoi(tokens[1]) >= 0)
					*exit_stat = _atoi(tokens[1]);
				else
					print_error(tokens, argv, exit_stat);
			}
			else
			{
				print_error(tokens, argv, exit_stat);
			}
		}
		return (1);
	}

	if (strcmp(tokens[0], "env") == 0)
	{
		env = environ;
		while (*env != NULL)
		{
			_putchar(*env);
			_putchar("\n");
			env++;
		}
		return (2);
	}
	if (strcmp(tokens[0], "unsetenv") == 0)
	{
		_unsetenv(tokens[1]);
		return (2);
	}
	return (0);
}

/**
 * _exe - function that check for executable file errors
 * @argv: command line argument list
 * @tokens: array of user input
 * @command: full path of command inputed
 * @exit_stat: exit status
 * Return: int
 */
int _exe(char **argv, char **tokens, char **command, int *exit_stat);
int _exe(char **argv, char **tokens, char **command, int *exit_stat)
{
	char *path = _getenv("PATH");

	if (access(tokens[0], X_OK) == -1)
	{
		*command = which_path(tokens[0], path);
		if (access(*command, X_OK) == -1)
		{
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			_putchar(": 1: ");
			write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
			_putchar(": not found");
			_putchar("\n");
			*exit_stat = 127;
			return (2);
		}
	}

	return (0);
}
