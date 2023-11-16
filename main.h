#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define CONVERT_UNSIGNED  0
#define CONVERT_LOWERCASE   1

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE   ".simple_shell_his"
#define HIST_MAX    4096

extern char **environ;

/**
 * struct list - link list
 * @num: num file
 * @str: string
 * @xt: pointer
*/
typedef struct list
{
	int num;
	char *str;
	struct list *xt;
} list_t;

/**
 * struct pass - pass into function
 * @arg: a string
 * @argv: an array
 * @pass: a str for path
 * @argc: argu count
 * @line_cou: the error of count
 * @err_num: the error code of exit
 * @linecou_flag: count of flags
 * @sname: file name
 * @env: linked list
 * @environ: custom modified copy
 * @hist: history node
 * @alias: alias history
 * @env_change: if env changed
 * @status: the return status
 * @cmd_buf: address of pointer
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd
 * @histcount: the history line number count
*/
typedef struct pass
{
	char *arg;
	char **argv;
	char *pass;
	int argc;
	unsigned int line_cou;
	int err_num;
	int linecou_flag;
	char *sname;
	list_t *env;
	list_t *hist;
	list_t *alias;
	char **environ;
	int env_change;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct built - contains a builtin string and related function
 * @type: the builtin command flag
 * @fun: function
*/
typedef struct built
{
	char *type;
	int (*fun)(info_t *);
} built_table;

int shs(info_t *, char **);
int find_built(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

int if_cmd(info_t *, char *);
char *pud_chars(char *, int, int);
char *show_path(info_t *, char *, char *);

int loopshs(char **);

void _eputs(char *);
int _eputchar(char);
int _putfd(char e, int se);
int _putsfd(char *str, int sd);

int _strlenght(char *);
int _strcm(char *, char *);
char *start_with(const char *, const char *);
char *_strhat(char *, char *);

char *_strcopy(char *, char *);
char *_strduup(const char *);
void _puts(char *);
int _putchar(char);

char *_strcpy(char *, char *, int);
char *_strcat(char *, char *, int);
char *_strchr(char *, char);

char **strtow1(char *, char *);
char **strow2(char *, char);

char *_mememberset(char *, char, unsigned int);
void befree(char **);
void *_realloc1(void *, unsigned int, unsigned int);

int ffree(void **);

int inactive(info_t *);
int it_decmile(char, char *);
int _isalphabitcal(int);
int _atc(char *);

int _err(char *);
void print_err(info_t *, char *);
int print_f(int, int);
char *conv_num(long int, int, int);
void remove_comm(char *);

int _stab(info_t *);
int _cd(info_t *);
int _help(info_t *);

int _history(info_t *);
int _alias(info_t *);

ssize_t put_input(info_t *);
int _gettheline(info_t *, char **, size_t *);
void sigHand(int);

void infor_clear(info_t *);
void infor_set(info_t *, char **);
void infor_free(info_t *, int);

char *_putenv(info_t *, const char *);
int _env(info_t *);
int _setenv(info_t *);
int _unsetenv(info_t *);
int pop_env_list(info_t *);

char **get_env(info_t *);
int _unsetenv2(info_t *, char *);
int _setenv2(info_t *, char *, char *);

char *get_hist_file(info_t *info);
int hist_write(info_t *info);
int hist_read(info_t *info);
int build_hist_list(info_t *info, char *buf, int linecou);
int hist_renum(info_t *info);

list_t *add_nod(list_t **, const char *, int);
list_t *add_nod_end2(list_t **, const char *, int);
size_t print_list_str2(const list_t *);
int delete_node(list_t **, unsigned int);
void list_free(list_t **);

size_t lenght_list(const list_t *);
char **list_of_strs(list_t *);
size_t print_some_list(const list_t *);
list_t *node_star_with(list_t *, char *, char);
ssize_t node_get(list_t *, list_t *);

int it_chain(info_t *, char *, size_t *);
void chain_check(info_t *, char *, size_t *, size_t, size_t);
int ali_replace(info_t *);
int vars_replace(info_t *);
int str_replace(char **, char *);
#endif
