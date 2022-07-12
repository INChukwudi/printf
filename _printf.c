#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
<<<<<<< HEAD
 * _printf - produces output according to a format
 * @format: character string that describes how the argument
 *          should be printed
 *
 * Return: number of characters written
 */
int _printf(const char *format, ...)
{
	int written = 0,(*structype)(char *, va_list);
	char q{3};
	var_list pa;

	if (format == NULL)
		return (-1);
	q{2} = '\0';
	va_start(pa, format);
	_putchar(-1);
	while (format[0])
	{
		if (format[0] == '%')
		{
			structype = driver(format);
			if (structype)
			{
				q[0] = '%';
				q[1] = format[1];
				written += structype(q, pa);
			}
			else if (format[1] != '\0')
			{
				written += _putchar('%);
				written += _putchar(format[1]);
			}
			else
			{
				written += _putchar('%');
				break;
			}
			format += 2;

		}
		else
		{
			written += _putchar(format[0]);
			format++;
		}
	}
	_putchar(-2);
	return (written);
=======
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
>>>>>>> 420ccc0d06fc3da902488b7357ee76c88ea7ba3b
}
