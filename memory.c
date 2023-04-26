#include "shell.h"

/**
 * bfree - frees a pointer and nullifies the address
 * @ptr: the address of pointer to free
 *
 * Return: 1 if freed, otherwise return 0
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
