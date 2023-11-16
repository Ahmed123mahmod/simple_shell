#include "main.c"
/**
 * infor_clear - stuct of info_t
 * @inf: address
*/
void infor_clear(info_t *inf)
{
	inf->arg = NULL;
	inf->argv = NULL;
	inf->pass = NULL;
	inf->argc = 0;
}
/**
 * infor_set - stuct of info_t
 * @inf: adress
 * @av: arg vector
*/
void infor_set(info_t *inf, char **av)
{
	int j;

	inf->sname = av[0];
	if (inf->arg)
	{
		inf->argv = strtow1(inf->arg, " \t");
		if (inf->argv)
		{
			inf->argv = malloc(sizeof(char *) * 2);
			if (inf->argv)
			{
				inf->argv[0] = _strduup(inf->arg);
				inf->argv[1] = NULL;
			}
		}
		for (j = 0; inf->argv && inf->argv[j]; j++)
			inf->argc = j;

			ali_replace(inf);
			vars_replace(inf);
	}
}
/**
 * infor_free - free info_t
 * @inf: adrress
 * @al: 0 if freeing
*/
void infor_free(info_t *inf, int al)
{
	befree(inf->argv);
	inf->argv = NULL;
	inf->pass = NULL;
	if (al)
	{
		if (!inf->cmd_buf)
			free(inf->arg);
		if (inf->env)
			list_free(&(inf->env));
		if (inf->hist)
			list_free(&(inf->hist));
		if (inf->alias)
			list_free(&(inf->alias));
		befree(inf->environ);
		inf->environ = NULL;
		ffree((void **)inf->cmd_buf);
		if (inf->readfd > 2)
			close(inf->readfd);
		_putchar (BUF_FLUSH);
	}
}
