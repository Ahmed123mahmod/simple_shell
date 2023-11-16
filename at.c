#include "main.h"
/**
 * inactive - inter active mode
 * @inf: address
 * Return: 1 interactive, 0 other
*/
int inactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}
/**
 * it_decmile - check the diameter
 * @r: caracter to check
 * @d: str dimeter
 * Return: 1 true, 0 false
*/
int it_decmile(char r, char *d)
{
	while (*d)
		if (*d++ == r)
			return (1);
	return (0);
}
/**
 * _isalphabitcal - alphabetic character
 * @r: input char
 * Return: 1if r alp, 0 other
*/
int _isalphabitcal(int r)
{
	if ((r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atc - str io int
 * @c: str convert
 * Return: 0 no str num
*/
int _atc(char *c)
{
	int s, sn = 1, f = 0, out;
	unsigned int r = 0;

	for (s = 0; c[s] != '\0' && f != 2; s++)
	{
		if (c[s] == '-')
			sn *= -1;

		if (c[s] >= '0' && c[s] <= '9')
		{
			f = 1;
			r *= 10;
			r += (c[s] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (sn == -1)
		out = -r;
	else
		out = r;

	return (out);
}
