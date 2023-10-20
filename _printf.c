#include "main.h"

void print_buffar(char buffar[], int *buffa_ind);

/**
 * _printf - print function
 * @format: format specifier.
 * Return: chars.
 */
int _printf(const char *formate, ...)
{
	int x, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buffa_ind = 0;
	va_list lists;
	char buffer[BUFF_SIZE];

	if (formate == NULL)
  {
		return (-1);
  }
	va_start(lists, format);

	for (x = 0; formate && formate[x] != '\0'; x++)
	{
		if (formate[x] != '%')
		{
			buffer[buffa_ind++] = formate[x];
			if (buffa_ind == BUFF_SIZE)
      {
				print_buffar(buffer, &buffa_ind);
			/* write(1, &formate[x], 1);*/
			printed_chars++;
      }
		}
		else
		{
			print_buffar(buffer, &buffa_ind);
			flags = get_flags(formate, &x);
			width = get_width(formate, &x, lists);
			precision = get_precision(formate, &x, lists);
			size = get_size(formate, &x);
			++x;
			printed = handle_print(format, &x, lists, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffar(buffer, &buffa_ind);

	va_end(lists);

	return (printed_chars);
}

/**
 * print_buffar - Prints the contents of the buffar
 * @buffar: Array of chars
 * @buffa_ind: Index at which to add next char, represents the length.
 */
void print_buffar(char buffar[], int *buffa_ind)
{
	if (*buffa_ind > 0)
		write(1, &buffer[0], *buffa_ind);

	*buffa_ind = 0;
}
