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
