#include <stdarg.h>
#include "main.h"

/**
 * print_string - parse string
 * @str: string to print
 */

void print_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _printf - implement printf in c
 * @format: character string
 * Return: 0 on success
 */

int _printf(const char *format, ...)
{
	int count = 0;
	char ch, ch2;
	va_list param_list;

	va_start(param_list, format);
	while (format[count] != '\0')
	{
		ch = format[count];

		if (ch != '%')
		{
			_putchar(ch);
		}
		else
		{
			ch2 = format[count + 1];
			count++;

			if (ch2 == 'c')
			{
				_putchar(va_arg(param_list, int));
			}
			else if (ch2 == '%')
			{
				_putchar('%');
			}
			else
			{
				char *st = va_arg(param_list, char*);

				print_string(st);
			}
		}
		count++;
	}

	return (0);
}
