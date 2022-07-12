#include "main.h"

/**
 * print_percent - print a percent sign (%)
 * @arg_list: poits to the percent sign (%)
 * @buffer: buffer to store the character in
 *
 * Return: 1
 */
int print_percent(va_list __attribute__((__unused__)) arg_list, char *buffer)
{
	*buffer = '%';

	return (1);
}

/**
 * print_r - prints a string in reverse
 * @arg_list: points to the string to be printed in reverse
 * @buffer: buffer stroing the string
 *
 * Return: number of chracted in @buffer
 */
int print_r(va_list arg_list, char *buffer)
{
	int end, length = 0, index;
	char *rev;
	char *null = "(null)";

	rev = va_arg(arg_list, char *);
	if (rev == NULL)
	{
		for (index = 0; *(null + index); index++)
		{
			*buffer = *(null + index);
			buffer++;
		}
		return (6);
	}

	while (rev[length] != '\0')
		length++;

	for (end = length - 1; end >= 0; end--)
	{
		*buffer = rev[end];
		buffer++;
	}
	return (length);
}

/**
 * print_r_13 - prints the rot13'ed string
 * @arg_list: points to the string to be printed
 * @buffer: buffer storing the rot13'ed string
 *
 * Return: number of cahracters in @buffer
 */
int print_r_13(va_list arg_list, char *buffer)
{
	char *alpha, *rot13_alpha, *ch;
	char *null = "(null)";
	int i, j, length = 0;

	ch = va_arg(arg_list, char *);
	if (ch == NULL)
	{
		for (i = 0; *(null + i); i++)
		{
			*buffer++ = *(null + i);
		}
		return (6);
	}
	alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	rot13_alpha = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	for (i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] == ' ')
		{
			*buffer++ = ' ';
			length++;
			continue;
		}
		for (j = 0; alpha[j] != '\0'; j++)
		{
			if (ch[i] == alpha[j])
			{
				*buffer++ = rot13_alpha[j];
				break;
			}
			if (alpha[j] == 'Z')
			{
				*buffer++ = ch[i];
			}
		}
		length++;
	}
	return (length);
}
