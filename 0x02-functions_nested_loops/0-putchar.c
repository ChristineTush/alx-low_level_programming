#include <unistd.h>
#include "main.h"
/**
 * main - Function main entry
 *
 * Program that prints _putchar, followed by a new line
 *
 * Return: always 0 (success)
 */

int main(void)
{
	char word[8] = "_putchar";
	int i;

	for (i = 0; i < 8; i++)
	{
		_putchar(word[i]);
	}
	_putchar('\n');

	return (0);
}
