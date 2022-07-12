#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character that describes how the arg be printed
 *
 * Return: number of chearcters printed
 */
int _printf(const char *format, ...)
{
	int index, ret_value, length = 0, add = 0, percent = 0;
	char *buffer, *buffer_pointer;
	va_list args;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL || format == NULL)
		return (-1);
	buffer_pointer = buffer;

	va_start(args, format);
	for (index = 0; *(format + index); index++)
	{
		if (*(format + index) == '%')
		{
			percent++;
			if (converter(format + index + 1))
			{
				index++;
				add = converter(format + index)(args, buffer);
				length += add;
				buffer += add;
				ret_value = length;
				continue;
			}
			if (percent == 1 && *(format + index + 1))
			{
				ret_value = -1;
				break;
			}
		}
		*buffer = *(format + index);
		length++;
		buffer++;
		ret_value = length;
	}
	write(1, buffer_pointer, length);
	va_end(args);
	free(buffer_pointer);
	return (ret_value);
}
