#include "main.h"

char *str_rev(char *str)
{
	long int i;
	long int len = 0;
	char c;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
	{
	  len++;
	}
for (i = 0; i < (len / 2); i++)
{
	c = str[i];
	str[i] = str[len - i - 1];
	str[len - i - 1] = c;
}
return (str);
}
