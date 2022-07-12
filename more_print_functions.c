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
	int end, length, index;
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

	length = 0;
	while (rev[length] != '\0')
		length++;

	for (end = length - 1; end >= 0; end--)
	{
		*buffer = rev[end];
		buffer++;
	}
	return (length);
}
