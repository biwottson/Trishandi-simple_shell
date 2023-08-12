#ifndef _SHELL_H_
#define _SHELL_H_

/* Include necessary libraries */
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

/* Macros for buffer sizes and command chaining */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* Macros for conversion and system usage */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2
#define USE_GETLINE 0
#define USE_STRTOK 0

/* Constants for history file and maximum history size */
#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

/* External environment variable */
extern char **environ;

/* Data structure for a singly linked list */
typedef struct liststr
{
    int num;
    char *str;
    struct liststr *next;
} list_t;

/* Data structure for passing information to functions */
typedef struct passinfo
{
    char *arg;
    char **argv;
    char *path;
    int argc;
    unsigned int line_count;
    int err_num;
    int linecount_flag;
    char *fname;
    list_t *env;
    list_t *history;
    list_t *alias;
    char **environ;
    int env_changed;
    int status;
    char **cmd_buf;
    int cmd_buf_type;
    int readfd;
    int histcount;
} info_t;

/* Function prototypes */
char *_strdup(const char *str);
size_t _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strchr(char *s, char c);
char **_split_line(char *line, const char *delim);
void _free_str_array(char **array);
void print_error(char *command_name, int count, char *error_message);
int _strcmp(const char *s1, const char *s2);
char *search_path(char *command, char *path);
char *_getenv(const char *name);
void execute_command(char *command, char **args);
void handle_signal(int signum);
void interactive_mode(void);
void non_interactive_mode(FILE *stream);

#endif /* _SHELL_H_ */
