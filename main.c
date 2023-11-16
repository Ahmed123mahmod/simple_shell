#include "main.h"
/**
 * main - entry a point
 * @ah: arg count
 * @af: vec count
 * Return: 1 for error, 0 for done
*/
int main(int ah, char **af)
{
	info_t info[] = { INFO_INIT };
	int g = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (g)
			: "r" (g));

	if (ah == 2)
	{
		g = open(af[1], O_RDONLY);
		if (g == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(af[0]);
				_eputs(": 0: canot open ");
				_eputs(af[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (1);
		}
		info->readfd = g;
	}
	pop_env_list(info);
	hist_read(info);
	shs(info, af);
	return (0);
}
