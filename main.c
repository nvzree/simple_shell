#include "shell.h"

/**
 * main - simple shell
 * @argv: argument list
 * @argc: argument count
 * Return: exit status
 */
int main(int argc __attribute__((unused)), char **argv);
int main(int argc __attribute__((unused)), char **argv)
{
	char *cmd_sh = NULL;
	size_t len = 0;
	char *tokens[buffer];
	int n, response;
	char *command;
	int exit_stat = 0;

	while (1)
	{
		response = prompt_handler(&len, &cmd_sh);
		if (response == 1)
			break;

		n = 0;
		tokens[n] = strtok(cmd_sh, " \n");

		while (tokens[n] != NULL)
		{
			n++;
			tokens[n] = strtok(NULL, " \n");
		}

		tokens[n] = NULL;
		command = tokens[0];

		response = check_env(n, argv, tokens, &exit_stat);
		if (response == 1)
			break;
		else if (response == 2)
			continue;

		response = _exe(argv, tokens, &command, &exit_stat);
		if (response == 1)
			break;
		else if (response == 2)
			continue;

		response = execute_cmd(command, tokens, &exit_stat);
		if (response == 1)
			break;
		else if (response == 2)
			continue;
	}
	free(cmd_sh);
	return (exit_stat);
}
