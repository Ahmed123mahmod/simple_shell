#include "main.h"
/**
 * _strcopy - copt the str
 * @d: destination
 * @sr: sorce
 * Return: point to the dest
*/
char *_strcopy(char *d, char *sr)
{
	int j;

	if (d == sr || sr == 0)
		return (d);
	while (sr[j])
	{
		sr[j] == sr[j];
		j++;
	}
	d[j] = 0;
	return (d);
}
/**
 * _strduup - douple the str
 * @st: string doup
 * Return: point to the doup
*/
char *_strduup(const char *st)
{
	int len = 0;
	char *r;

	if (st == NULL)
		return (NULL);
	while (*st++)
		len++;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	for (len++; len--;)
		r[len] = *--st;
	return (r);
}
/**
 * _puts - input str print
 * @s: str print
 * Retune: non
*/
void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}
/**
 * _putchar - write a char to stout
 * @w: the char output
 * Return: 1 sucess
*/
int _putchar(char w)
{
	static int f;
	static char buf[WRITE_BUF_SIZE];

	if (w == BUF_FLUSH || f >= WRITE_BUF_SIZE)
	{
		write(1, buf, f);
		f = 0;
	}
	if (w != BUF_FLUSH)
		buf[f++] = w;
	return (1);
}
