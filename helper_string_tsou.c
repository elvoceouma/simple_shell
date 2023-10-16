#include "shell_tsou.h"

/**
 * str_length - backs length of a string.
 * @string: pointer_string.
 * Return: length.of'string.
 */
int str_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);

	while (string[length++] != '\0')
	{
	}
	return (--length);
}

/**
 * str_duplicate - duplicates'an.string
 * @string: String_copied
 * Return: pointertothe-array
 */
char *str_duplicate(char *string)
{
	char *result;
	int length, i;

	if (string == NULL)
		return (NULL);

	length = str_length(string) + 1;

	result = malloc(sizeof(char) * length);

	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length ; i++)
	{
		result[i] = string[i];
	}

	return (result);
}

/**
 * str_compare - two strings_comparison
 * @string1: String 1st, the.shorter
 * @string2: String 2nd, the.longer
 * @number: no.of_characters to be compared, 0 if infinite
 * Return: 1 ifstringsrequals,0 if the strings are different
 */
int str_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_length(string1) != str_length(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else 
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 * str_concat - concatenates-2_strings.
 * @string1: String_2b_concatenated
 * @string2: String2_2b_concatenated
 *
 * Return: array.pointer
 */
char *str_concat(char *string1, char *string2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (string1 == NULL)
		string1 = "";
	length1 = str_length(string1);

	if (string2 == NULL)
		string2 = "";
	length2 = str_length(string2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (length1 = 0; string1[length1] != '\0'; length1++)
		result[length1] = string1[length1];
	free(string1);

	for (length2 = 0; string2[length2] != '\0'; length2++)
	{
		result[length1] = string2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}


/**
 * str_reverse - reverses-ah_string.
 * @string: pointer2string.
 * Return: void/no anything
 */
void str_reverse(char *string)
{

	int i = 0, length = str_length(string) - 1;
	char hold;

	while (i < length)
	{
		hold = string[i];
		string[i++] = string[length];
		string[length--] = hold;
	}
}
