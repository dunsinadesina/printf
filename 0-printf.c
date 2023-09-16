#include "main.h"
/**
 * _printf - printf function
 * @format: argument
 * Return: integer
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i;
	unsigned int length;

	va_start(args, format);

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				length = _strlen(s);
				write(1, s, length);
				i += length;
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				i++;
			}
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}
/**
 * _strlen - length of string function
 * @str: string argument
 * Return: integer
 */
int _strlen(const char *str)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}
