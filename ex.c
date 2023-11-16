#include "main.h"
/**
 * *_strcpy - str copy
 * @d: destination
 * @sc: source
 * @z: char that copy
 * Return: con str
*/
char *_strcpy(char *d, char *sc, int z)
{
	int x, y;
	char *s = d;

	x = 0;
	while (sc[x] != '\0' && x < z - 1)
	{
		d[x] = sc[x];
		x++;
	}
	if (x < z)
	{
		y = x;
		while (y < z)
		{
			d[y] = '\0';
			y++;
		}
	}
	return (s);
}
/**
 * *_strcat - two string
 * @d: frist str
 * @sc: sec str
 * @z: max byts
 * Return: str contatct
*/
char *_strcat(char *d, char *sc, int z)
{
	int x, y;
	char *s = d;

	x = 0;
	y = 0;
	while (d[x] != '\0')
		x++;
	while (sc[y] != '\0' && y < z)
	{
		d[x] = sc[y];
		x++;
		y++;
	}
	if (y < z)
		d[x] = '\0';
	return (s);
}
/**
 * *_strchr - char in string
 * @f: parsed str
 * @g: char lokking for
 * Return: pointer to memory
*/
char *_strchr(char *f, char g)
{
	do {
		if (*f == g)
			return (f);
	} while (*f++ != '\0');
	return (NULL);
}
