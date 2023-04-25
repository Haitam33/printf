#include <stdarg.h>
#include <limits.h>
#include "main.h"

int _printf(char * str, ...)
{
  va_list vl;
  long int i = 0, j=0;
  char buff[100]={0}, tmp[100];
  char * str_arg;

  va_start( vl, str );
  while (str && str[i])
  {
    if(str[i] == '%'){
      i++;
      switch (str[i]) {
        /* Convert char */
        case 'c': {
          buff[j] = (char)va_arg( vl,long int );
          j++;
          break;
        }
        /* Convert decimal */
        case 'd': {
          _itoa((int)va_arg( vl,long int ), tmp, 10);
          strcpy(&buff[j], tmp);
          j += strlen(tmp);
          break;
        }
	/* Convert integer*/
        case 'i': {
          _itoa((int)va_arg( vl,long int ), tmp, 10);
          strcpy(&buff[j], tmp);
          j += strlen(tmp);
          break;
        }
        /* case string */
        case 's': {
          str_arg = va_arg( vl, char* );
          strcpy(&buff[j], str_arg);
          j += strlen(str_arg);
          break;
        }
		/* case % */
        case '%': {
        char *str;

        str = "%";
        strcpy(&buff[j], str);
        j++;
          break;
        }
      }
    }
	else {
      buff[j] =str[i];
      j++;
    }
    i++;
  }
  fwrite(buff, j, 1, stdout);
  va_end(vl);
  return j;
}
