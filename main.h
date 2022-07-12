#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct formatter - new type for a formatter
 * @symbol: conversion specifier
 * @f: function pointer to print function that matches @symbol
 */
typedef struct formatter {
	char *symbol;
	void (*f)(va_list arg_list);
} formatter_t;

int _printf(const char *format, ...);
void (*converter(const char *))(va_list arg_list);
void print_number(int n);
void print_c(va_list arg_list);
void print_s(va_list arg_list);
void print_d(va_list arg_list);
void print_i(va_list arg_list);

#endif /* _MAIN_H_ */
