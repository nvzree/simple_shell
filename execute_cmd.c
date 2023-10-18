#include "shell.h"

/**
 * execute_cmd - creates a child process and execute command
 * @command: executable command
 * @tokens: the array of arguments inputed
 * @exit_stat: exit status
 * Return: int
 */

int execute_cmd(char *command, char *tokens[], int *exit_stat)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("Error: fork");
		return (1);
	}

	if (child == 0)
	{
		execve(command, tokens, environ);
		*exit_stat = 2;
		perror("Error: execve");
		exit(2);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			*exit_stat = WEXITSTATUS(status);
		}
	}

	if (command != tokens[0])
		free(command);
	return (0);
}
