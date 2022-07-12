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
<<<<<<< HEAD
<<<<<<< HEAD
	void (*f)(va_list arg_list);
} formatter_t;

int _printf(const char *format, ...);
void (*converter(const char *))(va_list arg_list);
void print_number(int n);
void print_c(va_list arg_list);
void print_s(va_list arg_list);
void print_d(va_list arg_list);
void print_i(va_list arg_list);
=======
	int (*f)(va_list arg_list, char *buffer);
} formatter_t;

int _printf(const char *format, ...);
=======
	int (*f)(va_list arg_list, char *buffer);
} formatter_t;

int _printf(const char *format, ...);
>>>>>>> parent of 420ccc0... Add files via upload
int (*converter(const char *))(va_list arg_list, char *buffer);
void print_number(int n, char *buffer);
int print_c(va_list arg_list, char *buffer);
int print_s(va_list arg_list, char *buffer);
int print_d(va_list arg_list, char *buffer);
int print_i(va_list arg_list, char *buffer);
int print_percent(va_list arg_list, char *buffer);
<<<<<<< HEAD
>>>>>>> parent of 420ccc0... Add files via upload
=======
>>>>>>> parent of 420ccc0... Add files via upload

#endif /* _MAIN_H_ */
