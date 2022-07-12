#include "main.h"

/**
 * converter - matches the conversion specifier with the
 *             corresponding print function
 * @symbol: conversion specifier symbol to match
 *
 * Return: void function pointer to function matched by symbol
 */
void (*converter(const char *symbol))(va_list list)
{
	formatter_t func[] = {
		{"c", print_c},
		{"s", print_s},
		{"d", print_d},
		{"i", print_i}
	};
	int i;

	for (i = 0; i < 4; i++)
	{
		if (*symbol == *(func[i].symbol))
			return (func[i].f);
	}

	write(2, "Conversion specifier lacks type at end of format", 48);
	exit(1);
}
