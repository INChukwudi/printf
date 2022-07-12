#include "main.h"

/**
 * _printf - produces output according to a format
<<<<<<< HEAD
 * @format: character string that describes how the argument
 *          should be printed
=======
 * @format: character that describes how arg be printed
>>>>>>> parent of 420ccc0... Add files via upload
 *
 * Return: number of chearcters printed
 */
int _printf(const char *format, ...)
{
	int index, ret_value, length = 0, add = 1;
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
			if (*(format + index + 1) == '\0')
			{
				ret_value = -1;
				break;
			}
			if (converter(format + index + 1))
			{
				index++;
				add = converter(format + index)(args, buffer);
				length += add;
				buffer += add;
				ret_value = length;
				continue;
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
