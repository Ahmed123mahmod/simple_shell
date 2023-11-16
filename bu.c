#include "main.h"
/**
 * _stab - shell exit
 * @inf: struc arg
 * Return: 0 exit status
*/
int _stab(info_t *inf)
{
	int exch;

	if (inf->argv[1])
	{
		exch = _err(inf->argv[1]);
		if (exch == -1)
		{
			inf->status = 2;
			print_err(inf, "illegal num: ");
			_eputs(inf->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inf->err_num = _err(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}
/**
 * _cd - chang current dir
 *  @inf: struct arg
 *  Return: always 0
*/
int _cd(info_t *inf)
{
	char *s, *d, buf[1024];
	int chd;

	s = getcwd(buf, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!inf->argv[1])
{
	d = _putenv(inf, "HOME=");
	if (!d)
		chd = chdir((d = _putenv(inf, "PWD=")) ? d : "/");
	else
		chd = chdir(d);
}
else if (_strcm(inf->argv[1], "-") == 0)
{
	if (!_putenv(inf, "OLDPWD="))
	{
		_puts(s);
		_putchar('\n');
		return (1);
	}
	_puts(_putenv(inf, "OLDPWD=")), _putchar('\n');
	chd = chdir((d = _putenv(inf, "OLDPWD=")) ? d : "/");
}
else
chd = chdir(inf->argv[1]);
if (chd == -1)
{
	print_err(inf, "canot cd to ");
	_eputs(inf->argv[1]), _eputchar('\n');
}
else
{
	_setenv2(inf, "OLDPWD", _putenv(inf, "PWD="));
	_setenv2(inf, "PWD", getcwd(buf, 1024));
}
return (0);
}
/**
 * _help - current directory
 * @inf: struct arg
 * Return: Always 0
*/
int _help(info_t *inf)
{
	char **array;

	array = inf->argv;
	_puts("help call works. fun no yet implimment \n");
	if (0)
		_puts(*array);
	return (0);
}
