#include "monty.h"
/**
 * _isdigit - function checks for digits
 * @c: pointer to the value
 * Return: 0 always success, otherwise 1
 */
int _isdigit(char *c)
{
	char *temp = c;

	if (c == NULL)
		return (0);

	if (*temp == '-')
		temp++;

	for (; *temp != '\0'; temp++)
	{
		if (*temp < '0' || *temp > '9')
			return (0);
	}
	return (1);
}
