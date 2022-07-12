#include "main.h"

/**
 * converter - matches the conversion specifier with the
 *             corresponding print function
 * @symbol: conversion specifier symbol to match
 *
 * Return: void function pointer to function matched by symbol
 */
int (*converter(const char *symbol))(va_list list, char *buffer)
{
	formatter_t func[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i},
		{"%", print_percent}
	};
	int i;

	for (i = 0; i < 5; i++)
	{
		if (*symbol == *(func[i].symbol))
			return (func[i].f);
	}

	write(2, "Conversion specifier lacks type at end of format", 48);
	exit(1);
	return (NULL);
}
