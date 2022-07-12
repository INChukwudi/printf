#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string that describes how the argument
 *          should be printed
 *
 * Return: number of chearcters printed
 */
int _printf(const char *format, ...)
{
	int index, ret_value = 0;
	va_list args;

	va_start(args, format);

	for (index = 0; *(format + index) != '\0'; index++)
	{
		if (*(format + index) == '%')
		{
			index++;

			if (*(format + index) != '%')
			{
				converter(format + index)(args);
				continue;
			}
		}

		write(1, (format + index), 1);
		ret_value++;
	}

	return (ret_value);
}
