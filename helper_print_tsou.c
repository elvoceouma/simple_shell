#include "shell_tsou.h"

/**
 * _print - writes a array of chars in the std_output
 * @string: pointer to tsou array_of-characters
 * Return: the no_of-bytes writed or .
 * On error, -1 is returned, and errer_number set.
 */
int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}
/**
 * _printe - writes a array.of_characters in the std-error
 * @string: pointer to tsou array of chars
 * Return: the no_of-bytes writed or made
 * On error, -1 brought back, and errorno is set.
 */
int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}

/**
 * _print_error - writes a array.of_characters in the std-error
 * @data: a pointer to tsou program's data'
 * @errorcode: erro_codee printed
 * Return: the no_of;bytes writed or .
 * On error, -1 returned of, and erorrno is set.
 */
int _print_error(int errorcode, data_of_program *data)
{
	char n_as_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, n_as_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(n_as_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
