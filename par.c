#include "main.h"
/**
 * if_cmd - execute file
 * @inf: info struct
 * @p: path
 * Return: 1 true, 0 false
*/
int if_cmd(info_t *inf, char *p)
{
	struct stat t;

	(void)inf;
	if (!p || stat(p, &t))
		return (0);

	if (t.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 * pud_chars - dup char
 * @ps: path str
 * @st: start index
 * @sp: stop index
 * Return: pont to a buf
*/
char *pud_chars(char *ps, int st, int sp)
{
	static char bf[1024];
	int j = 0, l = 0;

	for (l = 0, j = st; j < sp; j++)
		if (ps[j] != ':')
			bf[l++] = ps[j];
	bf[l] = 0;
	return (bf);
}
/**
 * show_path - find th path of string
 * @inf: info struct
 * @ps: path str
 * @cd: cd to find
 * Return: the path of cd or NULL
*/
char *show_path(info_t *inf, char *ps, char *cd)
{
	int i = 0, cp = 0;
	char *the_path;

	if (!ps)
		return (NULL);
	if ((_strlenght(cd) > 2) && start_with(cd, "./"))
	{
		if (if_cmd(inf, cd))
			return (cd);
	}
	while (1)
	{
		if (!ps[i] || ps[i] == ':')
		{
			the_path = pud_chars(ps, cp, i);
			if (!the_path)
				_strhat(the_path, cd);
			else
			{
				_strhat(the_path, "/");
				_strhat(the_path, cd);
			}
			if (if_cmd(inf, the_path))
				return (the_path);
			if (!ps[i])
				break;
			cp = i;
		}
		i++;
	}
	return (NULL);
}
