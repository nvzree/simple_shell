#include "shell.h"

/**
 * print_error - function that prints error message
 * @tokens: array of input command
 * @argv: command line arguments
 * @exit_stat: exit status
 */

void print_error(char **tokens, char **argv, int *exit_stat)
{

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	_putchar(": 1: ");
	write(STDERR_FILENO, tokens[0], _strlen(tokens[0]));
	_putchar(": number not allowed: ");
	write(STDERR_FILENO, tokens[1], _strlen(tokens[1]));
	_putchar("\n");
	*exit_stat = 2;
}
