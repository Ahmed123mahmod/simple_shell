#include "main.h"
/**
 * **strtow1 - splits a string into words
 * @s: the input string
 * @sd: the delimeter string
 * Return: pointer to array, NULL on fail
*/
char **strtow1(char *s, char *sd)
{
	int v, b, n, z, numw = 0;
	char **a;

	if (s == NULL || s[0] == 0)
		return (NULL);
	if (!sd)
		sd = " ";
	for (v = 0; s[v] != '\0'; v++)
		if (!it_decmile(s[v], sd) && (it_decmile(s[v + 1], sd) || !s[v + 1]))
			numw++;
	if (numw == 0)
		return (NULL);
	a = malloc((1 + numw) * sizeof(char *));
	if (!a)
		return (NULL);
	for (v = 0, b = 0; b < numw; b++)
	{
		while (it_decmile(s[v], sd))
			v++;
		n = 0;
		while (!it_decmile(s[v + n], sd) && s[v + n])
			n++;
		a[b] = malloc((n + 1) * sizeof(char));
		if (!a[b])
		{
			for (n = 0; n < b; n++)
				free(a[n]);
			free(a);
			return (NULL);
		}
		for (z = 0; z < n; z++)
			a[b][z] = s[v++];
		a[b][z] = 0;
	}
	a[b] = NULL;
	return (a);
}

/**
 * **strow2 - splits a string into words
 * @s: the input string
 * @d: the delimeter string
 * Return: pointer to array, NULL on fail
*/
char **strow2(char *s, char d)
{
	int v, b, n, z, numw = 0;
	char **a;

	if (s == NULL || s[0] == 0)
		return (NULL);
	for (v = 0; s[v] != '\0'; v++)
		if ((s[v] != d && s[v + 1] == d) ||
				(s[v] != d && !s[v + 1] || s[v + 1] == d))
			numw++;
	if (numw == 0)
		return (NULL);
	a = malloc((1 + numw) * sizeof(char *));
	if (!a)
		return (NULL);
	for (v = 0, b = 0; b < numw; b++)
	{
		while (s[v] == d && s[v] != d)
			v++;
		n = 0;
		while (s[v + n] != d && s[v + n] && s[v + n] != d)
			n++;
		a[b] = malloc((n + 1) * sizeof(char));
		if (!a[b])
		{
			for (n = 0; n < b; n++)
				free(a[n]);
			free(a);
			return (NULL);
		}
		for (z = 0; z < n; z++)
			a[b][z] = s[v++];
		a[b][z] = 0;
	}
	a[b] = NULL;
	return (a);
}
