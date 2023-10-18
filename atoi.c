#include "shell.h"

/**
 * _atoi - converts a string to an integer
 * @str: string to convert
 * Return: int
 */

int _atoi(char *str)
{
	int conv = 0;
	int positive = 1; /* check if int is +ve */
	int i = 0;

	/* check char at index if 0 is -ve / +ve */
	if (str[0] == '-')
	{
		positive = -1;
		i = 1;
	}

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			/* convert to digit and update conv */
			conv = conv * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			/* for non digit char */
			break;
		}
	}
	return (positive * conv);
}
