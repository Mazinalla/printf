#include "main.h"
/**
 * _putchar - print a character
 *@y: char input as parameter
 * Return: 1(success)
 */
int _putchar(char y)
{
	return (write(1, &y, 1));
}
