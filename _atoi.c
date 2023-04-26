#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2) ? 1 : 0;
}

/**
 * is_delim - checks if character is a delimiter
 * @c: the char to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	return (strchr(delim, c) != NULL) ? 1 : 0;
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s)
{
	int i, sign = 1, output = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		else if (isdigit(s[i]))
			output = output * 10 + (s[i] - '0');
		else if (output > 0)
			break;
	}

	return (sign * output);
}
