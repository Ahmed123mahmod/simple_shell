#include "main.h"

/**
 * it_chain - using it foe test
 * @nofo: struct parame
 * @bu: char buffer
 * @d: address of position
 * Return: 1 if chain faluse, 0 otherwise
*/
int it_chain(info_t *nofo, char *bu, size_t *d)
{
	size_t f = *d;

	if (bu[f] == '|' && bu[f + 1] == '|')
	{
		bu[f] = 0;
		f++;
		nofo->cmd_buf_type = CMD_OR;
	}
		else if (bu[f] == '&' && bu[f + 1] == '&')
		{
			bu[f] = 0;
			f++;
			nofo->cmd_buf_type = CMD_AND;
		} else
			return (0);
		*d = f;
		return (1);
	}

/**
 * chain_check -  make dic
 * @fo: struct par
 * @uf: char buffer
 * @g: adress
 * @i: position
 * @length: len of buf
 * Return: void
*/
void chain_check(info_t *fo, char *uf, size_t *g, size_t i, size_t length)
{
	size_t k = *g;

	if (fo->cmd_buf_type == CMD_AND)
	{
		if (fo->status)
		{
			uf[i] = 0;
			k = length;
		}
	}
	if (fo->cmd_buf_type == CMD_OR)
	{
		if (!fo->status)
		{
			uf[i] = 0;
			k = length;
		}
	}
	*g = k;
}
/**
 * ali_replace - using to replace
 * @l: struct par
 * Return: 0 if not replace, 1 otherwise
*/
int ali_replace(info_t *l)
{
	int t;
	list_t *n;
	char *y;

	for (t = 0; t < 10; t++)
	{
		n = node_star_with(l->alias, l->argv[0], '=');
		if (!n)
			return (0);
		free(l->argv[0]);
		y = _strchr(n->str, '=');
		if (!y)
			return (0);
		y = _strduup(y + 1);
		if (!y)
			return (0);
		l->argv[0] = y;
	}
	return (1);
}

/**
 * vars_replace -  replace var
 * @info: struct par
 *
 * Return: 1 replaced, 0 otherwise
*/
int vars_replace(info_t *info)
{
	int u = 0;
	list_t *nde;

	for (u = 0; info->argv[u]; u++)
	{
		if (info->argv[u][0] != '$' || !info->argv[u][1])
			continue;
		if (!_strcm(info->argv[u], "$?"))
		{
			str_replace(&(info->argv[u]),
					_strduup(conv_num(info->status, 10, 0)));
			continue;
		}
		if (!_strcm(info->argv[u], "$$"))
		{
			str_replace(&(info->argv[u]),
					_strduup(conv_num(getpid(), 10, 0)));
				continue;
		}
		nde = node_star_with(info->env, &info->argv[u][1], '=');
		if (nde)
		{
			str_replace(&(info->argv[u]),
					_strduup(_strchr(nde->str, '=') + 1));
			continue;
		}
		str_replace(&info->argv[u], _strduup(""));
	}
	return (0);
}

/**
 * str_replace - string replace
 * @po: address of str
 * @op: fresh string
 * Return: 1 is replaced, 0 otherwise
*/
int str_replace(char **po, char *op)
{
	free(*po);
	*po = op;
	return (1);
}
