#include "main.h"
/**
 * _printf - produces output according to a format.
 *@format: character string.
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	unsigned int x, cnt = 0;

	unsigned int s_count;

	va_list args;

	va_start(args, format);

	for (x = 0; format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			_putchar(format[x]);
		}
		else if (format[x] == '%' && format[x + 1] == 'c')
		{
			_putchar(va_arg(args, int));
			x++;
		}
		else if (format[x] == '%' && format[x + 1] == 's')
		{
			s_count = _puts(va_arg(args, char *));
			x++;
			cnt += (s_count - 1);
		}
		else if (format[x + 1] == '%')
		{
			_putchar('%');
		}
		else if (format[x] == '%' && format[x + 1] == '\0')
		{
			return (-1);
		}
		else if (format[x] == '%' && format[x + 1] == 'd')
		{
		
			print_d(va_arg(args, int *));
		}
		return (0);
		cnt += 1;
	}
	va_end(args);
	return (cnt);
}
/**
 * _puts - print string
 *@c: string
 * Return: number opf byte
 */
int _puts(char *c)
{
	int count = 0;

	if (c)
	{
		for (count = 0; c[count] != '\0'; count++)
		{
			_putchar(c[count]);
		}
	}
	return (count);
}
/**
 * _putchar - print a character
 *@y: char input as parameter
 * Return: 1(success)
 */
int _putchar(char y)
{
	return (write(1, &y, 1));
}
/**
 * print_d - checks for a digit (0 through 9).
 *@c: character 
 * Return: Always 0.
 */
int print_d(int *c)
{
	int x = 0;

	if (c)
        for (x = 48; c[x] < 58; x++)
        {
                _putchar(c[x]);
        }
        _putchar('\n');
	return (0);
}
/**
 * print_ld - prints the last digit of a number
 * @n: the int to extract the last digit from
 * Return: value of the last digit
 */
int print_ld(int *n)
{
        int a;

        if (n < 0)
        n = -n;

        a = n % 10;

        if (a < 0)
                a = -a;

        _putchar(a + '0');

        return (a);
}
