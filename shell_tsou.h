#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h> 
#include <stddef.h>
#include <errno.h> 
#include <sys/types.h> 
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h> 

#include "macros_tsou.h"

/************* TSOU STRUCTURES **************/

/**
 * struct info- struct for ze program's-data
 * @program_name: name of ze executable
 * @input_line: pointer to the input read for tsou_getline
 * @command_name: pointer to-the-1st command_typed by-the-user
 * @exec_counter: no_of excecuted-commands
 * @file_descriptor: file_descriptor to ze input_commands
 * @tokens: pointers-array of tokenized-input
 * @env: copy_of-the-environ
 * @alias_list: array_of-pointers with_aliases.
 */
typedef struct info
{
	char *program_name;
	char *input_line;
	char *command_name;
	int exec_counter;
	int file_descriptor;
	char **tokens;
	char **env;
	char **alias_list;
} data_of_program;

/**
 * struct builtins - struct_for ze_ builtins
 * @builtin: the_name of ze builtin
 * @function: the associated function to be called for_each-builtin
 */
typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;

/*************TSOU MAIN FUNCTIONS *************/


/*========  shell_tsou.c  ========*/

void inicialize_data(data_of_program *data, int arc, char *argv[], char **env);
void sisifo(char *prompt, data_of_program *data);
void handle_ctrl_c(int opr UNUSED);

/*======== tsou_getline.c  ========*/

int _getline(data_of_program *data);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);

/*======== expansions_tsou.c ========*/

void expand_variables(data_of_program *data);
void expand_alias(data_of_program *data);
int buffer_add(char *buffer, char *str_to_add);

/*======== str_token_tsou.c ========*/

void tokenize(data_of_program *data);
char *_strtok(char *line, char *delim);

/*======== execute_tsou.c ========*/

int execute(data_of_program *data);

/*======== builtin_list_tsou.c ========*/

int builtins_list(data_of_program *data);

/*======== find_in_path_tsou.c ========*/

char **tokenize_path(data_of_program *data);
int find_program(data_of_program *data);


/************** HELPERS FOR TSOU MEMORY MANAGEMENT **************/


/*======== helpers_free_tsou.c ========*/

void free_array_of_pointers(char **directories);
void free_recurrent_data(data_of_program *data);
void free_all_data(data_of_program *data);


/************** TSOU_BUILTINS **************/

/*======== builtin_more_tsou.c ========*/

int builtin_exit(data_of_program *data);
int builtin_cd(data_of_program *data);
int set_work_directory(data_of_program *data, char *new_dir);
int builtin_help(data_of_program *data);
int builtin_alias(data_of_program *data);


/*======== builtin_env_tsou.c ========*/

int builtin_env(data_of_program *data);
int builtin_set_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);


/************** HELPERS FOR TSOU ENVIRONMENT VARIABLES MANAGEMENT **************/


/* env_management_tsou.c */

char *env_get_key(char *name, data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);
void print_environ(data_of_program *data);


/* HELPERS FOR PRINTING/WRITING */


/*======== helper_print_tsou.c ========*/

int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_of_program *data);


/************** HELPERS FOR STRINGS MANAGEMENT TSOU **************/

/*======== helper_string_tsou.c ========*/

int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
char *str_concat(char *string1, char *string2);
void str_reverse(char *string);

/*======== helpers_numbers_tsou.c ========*/

void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);


/*======== alias_management_tsou.c ========*/
int print_alias(data_of_program *data, char *alias);
char *get_alias(data_of_program *data, char *alias);
int set_alias(char *alias_string, data_of_program *data);

#endif
