#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to printed
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int num = n;
	char negative = '-';
	char digit;

	if (n < 0)
	{
		write(1, &negative, 1);
		num = -num;
	}

	if ((num / 10) > 0)
		print_number(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

/**
 * print_c - prints a char to stdout
 * @arg_list: points to the char to be printed
 *
 * Return: void
 */
void print_c(va_list arg_list)
{
	char ch;

	ch = va_arg(arg_list, int);

	if (!ch)
	{
		exit(1);
	}
	write(1, &ch, 1);
}

/**
 * print_d - prints an integer
 * @arg_list: points to the integer to be printed
 *
 * Return: void
 */
void print_d(va_list arg_list)
{
	int d;

	d = va_arg(arg_list, int);
	print_number(d);
}

/**
 * print_i - prints an integer
 * @arg_list: points to the integer to be printed
 *
 * Return: void
 */
void print_i(va_list arg_list)
{
	int i;

	i = va_arg(arg_list, int);
	print_number(i);
}

/**
 * print_s - prints a string
 * @arg_list: points to the string to be printed
 *
 * Return: void
 */
void print_s(va_list arg_list)
{
	char *string;
	int index;

	string = va_arg(arg_list, char *);

	if (!string)
		exit(2);

	for (index = 0; *(string + index); index++)
		write(1, (string + index), 1);
}
