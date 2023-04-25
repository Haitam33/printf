#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>
#include <stddef.h>

int _printf(const char *format, ...);
char *str_rev (char *str);
char * _itoau(long int i, char *strout, int base);
char * _itoa(long int i, char *strout, int base);

#endif /* MAIN_H */
