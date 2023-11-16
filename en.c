#include "main.h"
/**
 * _env - current env
 * @inf: struct arg
 * Return: 0 Always
*/
int _env(info_t *inf)
{
	print_list_str2(inf->env);
	return (0);
}
/**
 * _putenv - value env
 * @inf: struct arg
 * @n: var
 * Return: var
*/
char *_putenv(info_t *inf, const char *n)
{
	list_t *no = inf->env;
	char *f;

	while (no)
	{
		f = start_with(no->str, n);
		if (f && *f)
			return (f);
		no = no->xt;
	}
	return (NULL);
}
/**
 * _setenv - new env
 * @inf: struct argument
 * Return: Always 0
*/
int _setenv(info_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("not crrect num argument\n");
		return (1);
	}
	if (_setenv2(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}
/**
 * _unsetenv - remove env
 * @inf: stru arg
 * Return: 0 Always
*/
int _unsetenv(info_t *inf)
{
	int x;

	if (inf->argc == 1)
	{
		_eputs("few argu\n");
			return (1);
	}
	for (x = 1; x <= inf->argc; x++)
		_unsetenv2(inf, inf->argv[x]);

	return (0);
}
/**
 * pop_env_list -populates list
 * @inf: struvt arg
 * Return: Always 0
*/
int pop_env_list(info_t *inf)
{
	list_t *n = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_nod_end2(&n, environ[x], 0);
	inf->env = n;
	return (0);
}
