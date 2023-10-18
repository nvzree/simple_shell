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
	return write(STDOUT_FILENO, c, _strlen(c));
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

char *_strcpy(char *dest, const char *src)
{
	int i = -1;

	 while (src[i] != '\0')
	 {
		i++;
		dest[i] = src[i];
	 }

	return (dest);
}
