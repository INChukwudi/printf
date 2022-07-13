#include "main.h"

/**
 * print_u - prints an unsigned integer as unsigned decimal
 * @arg_list: points to the unsigned int
 * @buffer: buffer to store the result
 *
 * Return: number of characters in @buffer
 */
int print_u(va_list arg_list, char *buffer)
{
	int half1_digits = 1, half2_digits = 1;
	unsigned int num, half_num_1, half_num_2, copy_num;

	num = va_arg(arg_list, unsigned int);
	half_num_1 = num / 10000;
	copy_num = half_num_1;

	while ((copy_num / 10) > 0)
	{
		half1_digits++;
		copy_num /= 10;
	}

	buffer += half1_digits - 1;
	print_number(half_num_1, buffer);
	half_num_2 = num % 10000;
	copy_num = half_num_2;

	while ((copy_num / 10) > 0)
	{
		half2_digits++;
		copy_num /= 10;
	}

	buffer += half2_digits;
	print_number(half_num_2, buffer);

	return (half1_digits + half2_digits);
}

/**
 * print_o - prints an unsigned integer as in octal notation
 * @arg_list: points to the unsigned int
 * @buffer: stores the result
 *
 * Return: number of digits in @buffer
 */
int print_o(va_list arg_list, char *buffer)
{
	unsigned int num, copy_num, digits = 1;

	num = va_arg(arg_list, unsigned int);
	copy_num = num;

	while (copy_num / 8)
	{
		digits++;
		copy_num /= 8;
	}

	buffer += digits - 1;
	while (num / 8)
	{
		*buffer = (num % 8) + '0';
		buffer--;
		num /= 8;
	}

	*buffer = (num % 8) + '0';
	return (digits);
}
