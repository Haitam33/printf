#include "main.h"
/**
 * _itoa - convert integer to character
 * @i: input
 * @strout: char
 * @base: integer
 * Return: strout
 */

char *_itoa(long int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('a' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	str_rev(strout);
	return (strout);
}
