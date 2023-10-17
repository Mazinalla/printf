#include <stdio.h>
#include <unistd.h>
/**
 * putchar - print a character
 * @c: char input as parameter
 * Return: 1(success)
 */
int _putchar(char y)
{
        return (write(1, &y, 1));
}
