#include "shell.h"

/**
 * prompt_handler - prints prompt to stdout and reads command input
 * @len: length of the input
 * @line: user command stored
 * Return: int
 */

int prompt_handler(size_t *len, char **cmd_sh)
{
	ssize_t cmd_count;
	int interactive_sh = isatty(STDIN_FILENO);
	cmd_sh = NULL;

	if (interactive_sh)
	{
		_putchar("simple_shell# ");
	}

	cmd_count = getline(cmd_sh, len, stdin);
	if (cmd_count == -1)
	{
		if (interactive_sh)
		{
			_putchar("\n");
		}

	return (1);
	}

	return (0);
}
