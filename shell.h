#ifndef _SHELL_H_
#define _SHELL_H_

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

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_s;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@error_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env

 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int error_num;
	int linecount_flag;
	list_s *env;
	char **environ;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_s;

#define INFO_INIT
{NULL, NULL, NULL, 0, 0, 0, 0,
NULL, NULL, NULL, NULL, NULL, 0, 0, NULL,
0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_s *);
} builtin_table;


/* shell_shloop.c */
int hsh(info_s *, char **);
int find_builtin(info_s *);
void find_cmd(info_s *);
void fork_cmd(info_s *);

/* shell_parser.c */
int is_cmd(info_s *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_s *, char *, char *);

/* shell_loophsh.c */
int loophsh(char **);

/* shell_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* shell_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* shell_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* shell_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);


/* shell_atoi.c */
int interactive(info_s *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);


/* shell_builtin.c */
int _exit(info_s *);
int _cd(info_s *);
int _help(info_s *);

/*shell_environ.c*/
char *_getenv(info_s *, const char *);
int _env(info_s *);
int _setenv(info_s *);
int _unsetenv(info_s *);
int populate_env_list(info_s *);


#endif

