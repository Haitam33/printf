#include <stdarg.h>
#include <limits.h>
#include <string.h>

char *str_rev (char *str)
{
        long int i;
        long int len = 0;
  char c;
  if (!str)
    return NULL;
  while(str[len] != '\0'){
    len++;
  }
for(i = 0; i < (len/2); i++)
{
     c = str[i];
     str [i] = str[len - i - 1];
     str[len - i - 1] = c;
}
return str;
}
char * _itoau(long int i, char *strout, int base)
{
  char *str = strout;
  int digit, sign = 0;
  if (i < 0) {
    sign = 1;
    i *= -1;
  }
  while(i) {
    digit = i % base;
    *str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
    i = i / base;
    str ++;
  }
  if(sign) {
  *str++ = '-';
  }
  *str = '\0';
  str_rev(strout);
  return strout;
}
char * _itoa(long int i, char *strout, int base)
{
  char *str = strout;
  int digit, sign = 0;
  if (i < 0) {
    sign = 1;
    i *= -1;
  }
  while(i) {
    digit = i % base;
    *str = (digit > 9) ? ('a' + digit - 10) : '0' + digit;
    i = i / base;
    str ++;
  }
  if(sign) {
  *str++ = '-';
  }
  *str = '\0';
  str_rev(strout);
  return strout;
}
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
        /* unsigned integer */
        case 'u': {
          _itoa((unsigned int)va_arg( vl,long int ), tmp, 10);
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
        /* Convert hex Lowercase*/
        case 'x': {
          _itoa(va_arg( vl,long int ), tmp, 16);
          strcpy(&buff[j], tmp);
          j += strlen(tmp);
          break;
        }
         /* Convert hexadecimal Uppercase */
        case 'X': {
          _itoau(va_arg( vl,long int ), tmp, 16);
          strcpy(&buff[j], tmp);
          j += strlen(tmp);
          break;
        }
        /* Convert octal */
        case 'o': {
          _itoa(va_arg( vl,long int ), tmp, 8);
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
        /* case adresse */
        case 'p': {
        char a[] = "0x";
        buff[j] = a[0];
        j++;
        buff[j] = a[1];
        j++;
        _itoa(va_arg( vl,long int ), tmp, 16);
          strcpy(&buff[j], tmp);
          j += strlen(tmp);
          break;
        }
        /* case adresse */
        case 'r': {
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
