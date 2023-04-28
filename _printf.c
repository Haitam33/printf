#include "main.h"

int _printf(const char *format, ...)
{

	va_list vl;
	long int i = 0, j = 0;
	char buff[100] = {0}, tmp[100];
	char *str_arg;

	va_start(vl, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				/* Convert char */
				case 'c':
					{
						buff[j] = (char)va_arg(vl, long int);
						j++;
						break;
					}
					/* Convert decimal */
				case 'd':
					{
						_itoa((int)va_arg(vl, long int), tmp, 10);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
					/* unsigned integer */
				case 'u':
					{
						_itoa((unsigned int)va_arg(vl, long int), tmp, 10);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
					/* Convert integer*/
				case 'i':
					{
						_itoa((int)va_arg(vl, long int), tmp, 10);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
					/* Convert hex Lowercase*/
				case 'x':
					{
						_itoa(va_arg(vl, long int), tmp, 16);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
					/* Convert hexadecimal Uppercase */
				case 'X':
					{
						_itoau(va_arg(vl, long int), tmp, 16);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
					/* Convert octal */
				case 'o':
					{
						_itoa(va_arg(vl, long int), tmp, 8);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
					/* case string */
				case 's':
					{
						str_arg = va_arg(vl, char*);
						strcpy(&buff[j], str_arg);
						j += strlen(str_arg);
						break;
					}
					/* case % */
				case '%':
					{
						char *str;

						str = "%";
						strcpy(&buff[j], str);
						j++;
						break;
					}
					/* case adresse */
				case 'p':
					{
						char a[] = "0x";

						buff[j] = a[0];
						j++;
						buff[j] = a[1];
						j++;
						_itoa(va_arg(vl, long int), tmp, 16);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
					}
					/* case adresse */
				case 'r':
					{
						char *str;

						str = "%r";
						buff[j] = str[0];
						j++;
						buff[j] = str[1];
						j++;
						break;
					}
			}
		}
			else
					{
						buff[j] = format[i];
						j++;
					}
					i++;
			}
			fwrite(buff, j, 1, stdout);
			va_end(vl);
			return (j);
		}
