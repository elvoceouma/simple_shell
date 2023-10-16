#include "shell_tsou.h"

/**
 * long_to_string - converts-number2string.
 * @number: number2b_converten_2_string.
 * @string: buffer to save tsou num-as_string.
 * @base: base to convert numz
 * Return: Nul/zerooh.
 */
void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0';

	if (string[0] == '-')
		inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '-';

	string[index] = '\0';
	str_reverse(string);
}


/**
 * _atoi - convert_string_2_integer.
 * @s: pointer to str_original.
 * Return: int_string or/ 0.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;
	while (!('0' <= *s && *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while ('0' <= *s && *s <= '9' && *s != '\0')
	{

		number = (number * 10) + (*s - '0');
		s++;
	}
	return (number * sign);
}
/**
 * count_characters - countscharacterz.in_string.
 * @string: pointer-2-string' original.
 * @character: string with.charz to be counted
 * Return: int of stringto return or/ 0.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
