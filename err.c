#include "main.h"
/**
 * _eputs - input string
 * @sr: print string
 * Return: non
*/
void _eputs(char *sr)
{
	int y = 0;

	if (!sr)
		return;
	while (sr[y] != '\0')
	{
		_eputchar(sr[y]);
		y++;
	}
}
/**
 * _eputchar - character
 * @ch: character is to be print
 * Return: sucess
*/
int _eputchar(char ch)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (ch != BUF_FLUSH)
		buf[x++] = ch;
	return (1);
}
/**
 * _putfd - given to ch
 * @ch: char
 * @f: file
 * Return: on success
*/
int _putfd(char ch, int f)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(f, buf, x);
		x = 0;
	}
	if (ch != BUF_FLUSH)
		buf[x++] = ch;
	return (1);
}
/**
 * _putsfd - input string
 * @sr: string
 * @f: file
 * Return: num of char
*/
int _putsfd(char *sr, int f)
{
int x = 0;

if (!sr)
	return (0);
while (*sr)
{
	x += _putfd(*sr++, f);
}
return (x);
}
