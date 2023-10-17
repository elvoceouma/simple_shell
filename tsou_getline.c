#include "shell_tsou.h"

/**
* _getline - read one line from tsou prompt.
* @data: struct for tsou program's data
*
* Return: come back counting bytes.
*/
int _getline(data_of_program *data)
{
	char buff[BUFFER_SIZE] = {'\0'};
	static char *array_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	if (!array_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		for (i = 0; array_commands[i]; i++)
		{
			free(array_commands[i]);
			array_commands[i] = NULL;
		}

		bytes_read = read(data->file_descriptor, &buff, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		i = 0;
		do {
			array_commands[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));
			i = check_logic_ops(array_commands, i, array_operators);
		} while (array_commands[i++]);
	}

	data->input_line = array_commands[0];
	for (i = 0; array_commands[i]; i++)
	{
		array_commands[i] = array_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}

	return (str_length(data->input_line));
}


/**
* check_logic_ops - checks-and_split for && and || operators
* @array_commands: array of tsou commands.
* @i: index in the array_commands to-be_checked
* @array_operators: array of the logical_ operators for tsou previous command
* Return: indexoflast command in the array-commands.
*/
int check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = str_duplicate(array_commands[i]);
			array_commands[i + 1] = str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
		{
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = str_duplicate(array_commands[i]);
			array_commands[i + 1] = str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
