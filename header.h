#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 100
#define PATH "/bin"

#define END_OF_FILE -2
#define EXIT -3

int prog(char **args, char *handle);
int execute_input(char *input, char *);
void dunamicMode(char *argv[]);
void batching(char *argv[]);
int run_branch(char **args, char *handle);
int buffer_branch_procedure(pid_t pid);
extern char **environ;

/* This is the global environemnt */
extern char **environ;
/* This is the global program name */
char *name;
/* This is the global history counter */
int hist;


/**
 * struct list_z - This defines the linked list.
 * @dir: The directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_z
{
	char *dir;
	struct list_z *next;
} list_t;

/**
 * struct builtin_z - This defines the built-in commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_z
{
	char *name;
	int (*f)(char **argv, char **vront);
} builtin_t;

/**
 * struct alias_s - This defines the aliases.
 * @name: This is the name of the alias.
 * @value: This is the value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_z
{
	char *name;
	char *value;
	struct alias_z *next;
} alias_t;

/* This is the global aliase list */
alias_t *aliases;

/* These are builtins prototypes*/
int (*get_builtins(char *command))(char **args, char **vront);
int shellto_exit(char **args, char **vront);
int shellto_env(char **args, char __attribute__((__unused__)) **vront);
int shellto_setenv(char **args, char __attribute__((__unused__)) **vront);
int shellto_unsetenv(char **args, char __attribute__((__unused__)) **vront);
int shellto_cd(char **args, char __attribute__((__unused__)) **vront);
int shellto_alias(char **args, char __attribute__((__unused__)) **vront);
int shellto_help(char **args, char __attribute__((__unused__)) **vront);

/* These prototypes helps the builtins */
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/* These prototypes helps the main */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_location(char *command);
list_t *get_path_dir(char *path);
int execute(char **args, char **vront);
void free_list(list_t *head);
char *_itoa(int num);

/* These prototypes are the string functions */
int _strspn(char *s, char *accept);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* These prototypes helps the input */
int call_args(char **args, char **vront, int *exe_ret);
void handle_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int run_args(char **args, char **vront, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **vront);
char **replace_aliases(char **args);

/* These prototypes handles errors */
char *error_2_cd(char **args);
int create_error(char **args, int err);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_syntax(char **args);
char *error_126(char **args);
char *error_127(char **args);

/* These prototypes helps the linkedlist */
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

void helps_all(void);
void helps_alias(void);
void helps_cd(void);
void helps_exit(void);
void helps_help(void);
void helps_env(void);
void helps_setenv(void);
void helps_unsetenv(void);
void helps_history(void);

int proct_file_commands(char *file_path, int *exe_ret);
#endif /*END OF THE HEADER_H FILE */
