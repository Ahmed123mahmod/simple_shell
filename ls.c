#include "main.h"
/**
 * lenght_list - show the length
 * @l: pointer
 * Return: list size
*/
size_t lenght_list(const list_t *l)
{
	size_t j = 0;

	while (l)
	{
		l = l->xt;
		j++;
	}
	return (j);
}
/**
 * list_of_strs - an array
 * @hed: pointer
 * Return: string array
*/
char **list_of_strs(list_t *hed)
{
	list_t *n = hed;
	size_t f = lenght_list(hed), k;
	char **strs;
	char *str;

	if (!hed || !f)
		return (NULL);
	str = malloc(sizeof(char *) * (f + 1));
	if (!strs)
		return (NULL);
	for (f = 0; n; n = n->xt, f++)
	{
		str = malloc(_strlenght(n->str) + 1);
		if (!str)
		{
			for (k = 0; k < f; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}
		str = _strcopy(str, n->str);
		strs[f] = str;
	}
	strs[f] = NULL;
	return (strs);
}
/**
 * print_some_list - print elements
 * @k: pointer
 * Return: list size
*/
size_t print_some_list(const list_t *k)
{
	size_t g = 0;

	while (k)
	{
		_puts(conv_num(k->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(k->str ? k->str : "(nil)");
		_puts("\n");
		k = k->xt;
		g++;
	}
	return (g);
}
/**
 * node_star_with - node str
 * @n: pointer
 * @p: string
 * @x: next char
 * Return: node or null
*/
list_t *node_star_with(list_t *n, char *p, char x)
{
	char *f = NULL;

	while (n)
	{
		f = start_with(n->str, p);
		if (f && ((x == -1) || (*f == x)))
			return (n);
		n = n->xt;
	}
	return (NULL);
}
/**
 * node_get - index of node
 * @h: pointer
 * @n: node
 * Return: node or -1
*/
ssize_t node_get(list_t *h, list_t *n)
{
	size_t j = 0;

	while (h)
	{
		if (h == n)
			return (j);
		h = h->xt;
		j++;
	}
	return (-1);
}
