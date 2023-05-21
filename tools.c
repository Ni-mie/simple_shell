#include "shell.h"
/**
* count_str - counts the length of a string
* @str: the string iput
* Return: Returns the length of the string
*/
int count_str(char *str)
{
	int counter = 0;

	while (*str)
	{
		counter = counter + 1;
		str++;
	}
	return (counter);
}

/**
 * display_str - its a function that display a string using putchar
 *  @str: String input
 */

void display_str(char *str)
{
	int i = 0, num;

	num = count_str(str);

	for (i = 0; i < num; i++)
		_putchar(str[i]);
}

/**
* count_num - it gets the length of an integer
* @num: Iy takes an integer as input value
* Return: Returns the length of the integer
*/
int count_num(long int num)
{
	int counter = 0;

	if (num < 0)
		num = -(num);
	while (num / 10 != 0)
	{
		counter++;
		num /= 10;
	}
	counter += 1;
	return (counter);
}

/**
* mypow - it get the power of a number
* @num: The integer
* @power: The power
* Return: Return the power of the integer i.e 2 ^ 2 = 4
*/
int mypow(int num, int power)
{
	int calc = 0;

	if (power <= 0)
		return (1);
	calc = num * mypow(num, power - 1);
	return (calc);
}


/**
 * _putchar - writes characters
 * @c: character to be printed
 * Return: Always success.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
