#include "main.h"
/**
 * _strlenght - return the len of str
 * @l: length check of str
 * Return: int len of str
*/
int _strlenght(char *l)
{
	int i = 0;

	if (!l)
		return (0);
	while (*l++)
		i++;
	return (i);
}
/**
 * _strcm - do le graphic
 * @j: first strang
 * @i: sec strang
 * Return: pos if j > i, 0 if j = i, neg if j < ik
*/
int _strcm(char *j, char *i)
{
	while (*j && *i)
	{
		if (*j != *i)
			return (*j - *i);
		j++;
		i++;
	}
	if (*j == *i)
		return (0);
	else
		return (*j < *i ? -1 : 1);
}
/**
 * start_with - starat with hay stack
 * @hs: str for digging
 * @n: sub to find
 * Return: address of hs or NUll
*/
char *start_with(const char *hs, const char *n)
{
	while (*n)
		if (*n++ != *hs++)
			return (NULL);
	return ((char *)hs);
}
/**
 * _strhat - to see whatis inside
 * @d: destina buf
 * @sr: sourc buf
 * Return: pont to destination
*/
char *_strhat(char *d, char *sr)
{
	char *r = d;

	while (*d)
		d++;
	while (*sr)
		*d++ = *sr++;
	*d = *sr;
	return (r);
}
