#include "main.h"
/**
 * shs - shell loop
 * @inf: parameter
 * @argv: argumebt vector
 * Return: 0 true, 1 fail
*/
int shs(info_t *inf, char **argv)
{
	ssize_t f = 0;
	int built = 0;

	while (f != -1 && built != -2)
	{
		infor_clear(inf);
		if (inactive(inf))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		f = put_input(inf);
		if (f != -1)
		{
			infor_set(inf, argv);
			built = find_built(inf);
			if (built == -1)
				find_cmd(inf);
		}
		else if (inactive(inf))
			_putchar('\n');
		infor_free(inf, 0);
	}
	hist_write(inf);
	infor_free(inf, 1);
	if (!inactive(inf) && inf->status)
		exit(inf->status);
	if (built == -2)
	{
		if (inf->err_num == -1)
			exit(inf->status);
		exit(inf->err_num);
	}
	return (built);
}
/**
 * find_built - built in command
 * @inf: prameter
 * Return: -1 builtin not found , 0 sucess, -2 exit()
*/
int find_built(info_t *inf)
{
	int j, built_in = -1;
	built_table builtintb1[] = {
		{"exit", _stab},
		{"env", _env},
		{"help", _help},
		{"history", _history},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cd},
		{"alias", _alias},
		{NULL, NULL}
	};

	for (j = 0; builtintb1[j].type; j++)
		if (_strcm(inf->argv[0], builtintb1[j].type) == 0)
		{
			inf->line_cou++;
			built_in = builtintb1[j].fun(inf);
			break;
		}
	return (built_in);
}
/**
 * find_cmd - finf command
 * @inf: parameter
 * Return: void
*/
void find_cmd(info_t *inf)
{
	char *p = NULL;
	int x, y;

	inf->pass = inf->argv[0];
	if (inf->linecou_flag == 1)
	{
		inf->line_cou++;
		inf->linecou_flag = 0;
	}
	for (x = 0, y = 0; inf->arg[x]; x++)
		if (!it_decmile(inf->arg[x], " \t\n"))
			y++;
	if (!y)
		return;

	p = show_path(inf, _putenv(inf, "PATH="), inf->argv[0]);
	if (p)
	{
		inf->pass = p;
		fork_cmd(inf);
	}
	else
	{
		if ((inactive(inf) || _putenv(inf, "PATH=")
					|| inf->argv[0][0] == '/') &&
				if_cmd(inf, inf->argv[0]))
			fork_cmd(inf);
		else if (*(inf->arg) != '\n')
		{
			inf->status = 127;
			print_err(inf, "dosenot found\n");
		}
	}
}
/**
 * fork_cmd - fork an ececutaple
 * @inf: parametre
 * Return: void
*/
void fork_cmd(info_t *inf)
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		perror("erroe");
		return;
	}
	if (child == 0)
	{
		if (execve(inf->pass, inf->argv, get_env(inf)) == -1)
		{
			infor_free(inf, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(inf->status));
		if (WIFEXITED(inf->status))
		{
			inf->status = WEXITSTATUS(inf->status);
			if (inf->status == 126)
				print_err(inf, "NO Permission\n");
		}
	}
}
