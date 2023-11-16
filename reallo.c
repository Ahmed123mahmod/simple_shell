#include "main.h"
/**
 * _mememberset - fiel memmory
 * @f: pointer
 * @h: byte
 * @j:amount of byte
 * Return: pointer to mmemmory
*/
char *_mememberset(char *f, char h, unsigned int j)
{
	unsigned int o;

	for (o = 0; o < j; o++)
		f[o] = h;
	return (f);
}
/**
 * befree - free the str
 * @p: str to str
*/
void befree(char **p)
{
	char **g = p;

	if (!p)
		return;
	while (*p)
		free(*p++);
	free(g);
}
/**
 * _reallocl - work in the block memory
 * @pt: pointer
 * @old: size of block
 * @new: new size of block
 * Return: pointer
*/
void *_reallocl(void *pt, unsigned int old, unsigned int new)
{
	char *t;

	if (!pt)
		return (malloc(new));
	if (!new)
		return (free(pt), NULL);
	if (new == old)
		return (pt);

	t = malloc(new);
	if (!t)
		return (NULL);
	old = old < new ? old : new;
	while (old--)
		t[old] = ((char *)pt)[old];
	free(pt);
	return (t);
}
