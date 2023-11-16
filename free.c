#include "main.h"
/**
 * ffree - frees a pointer and NULLs
 * @p: adress of pointer
 *
 * Return: 1 free, 0 otherwise
*/
int ffree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
