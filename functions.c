#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char *c)
{
	return (write(STDOUT_FILENO, c, _strlen(c)));
}

/**
 * _strlen - returns length of a string
 * @s: string character
 * Return: lenght of string
 */

int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * *_strcpy -  copies the string pointed to by src
 * @dest: char type string
 * @src: char type string
 * Return: Pointer to `dest`
 */

char *_strcpy(char *dest, char *src)
{
	int len;
	int i;

	for (len = 0; len != '\0'; len++)
	{

	}

	for (i = 0; i <= src[len]; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: append source to this destination
 * @src: source to append from
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int dest_len = _strlen(dest);

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];
	}
	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * _strncmp - compare n character of str1 and str2
 * @str1: string 1
 * @str2: string 2
 * @n: number of characters
 * Return: 0 on success
 */

int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (str1[i] != str2[i])
		return (-1);
		i++;
	}
	return (0);
}
