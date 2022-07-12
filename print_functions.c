#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to printed
 * @buffer: buffer to store the character printed
 *
 * Return: void
 */
void print_number(int n, char *buffer)
{
	int num = n;

	if ((num / 10) > 0)
		print_number((num / 10), buffer - 1);

	*buffer = (num % 10) + '0';
}

/**
 * print_c - prints a char to stdout
 * @arg_list: points to the char to be printed
 * @buffer: buffer to store the char to be printed
 *
 * Return: always 1
 */
int print_c(va_list arg_list, char *buffer)
{
	unsigned char ch;

	ch = va_arg(arg_list, int);
	if (ch == '\0')
		return (1);

	*buffer = ch;
	return (1);
}

/**
 * print_d - prints an integer
 * @arg_list: points to the integer to be printed
 * @buffer: buffer to store the integer to be printed
 *
 * Return: number of characters stored in @buffer
 */
void print_d_i(va_list arg_list)
{
	int d, copy_d, digits = 1;

	d = va_arg(arg_list, int);

	if (d < 0)
	{
		*buffer = '-';
		digits++;

		if (d == -2147483648)
		{
			*(buffer + 1) = '2';
			digits++;
			d = 147483648;
		}
		else
			d = -d;
	}

	copy_d = d;

	while ((copy_d / 10) > 0)
	{
		digits++;
		copy_d /= 10;
	}

	buffer += digits - 1;
	print_number(d, buffer);
	return (digits);
}

/**
 * print_s - prints a string
 * @arg_list: points to the string to be printed
 * @buffer: buffer to store the string
 *
 * Return: number of characters in @buffer
 */
void print_s(va_list arg_list)
{
	char *string;
	char *null = "(null)";
	int index;

	string = va_arg(arg_list, char *);

	if (string == NULL)
	{
		for (index = 0; *(null + index); index++)
		{
			*buffer = *(null + index);
			buffer++;
		}

		return (6);
	}

	for (index = 0; *(string + index); index++)
	{
		*buffer = *(string + index);
		buffer++;
	}

	return (index);
}
