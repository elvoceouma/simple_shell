/* main - Entry point for the simple shell program */
/* Return: Always 0 */

#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_LEN 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024
#define MAX_PATH 1024

/* Function Prototypes */
char **split_line(char *line);
void exec_command(char **args);
char *find_command(const char *command);
void execute_command(char **args);
void read_command(char *line, char **args);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
void _setenv(char **args);
void _unsetenv(char **args);
int _cd(char *path);
void _ls(char **path);
void print_mode(mode_t mode);

int main(void)
{
    /* Our main function code goes here */
	return (0);
}

#endif /* SIMPLE_SHELL_H */
