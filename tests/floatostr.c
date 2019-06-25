/*
** EPITECH PROJECT, 2021
** POOL
** File description:
** Created by abderrahim.cherkaoui@epitech.eu,
*/

#include <stdlib.h>
#include <stdio.h>

static int	int_len(int val)
{
	int len = 0;

	if (val < 0) {
		val = -val;
		len = 1;
	}
	while (val > 0) {
		val /= 10;
		len++;
	}
	return (len);
}

char *float_to_str(float nb)
{
	char	*number;
	int 	int_1 = (int)nb;
	float 	rest = nb - (float)int_1;
	int 	alloc = int_len(int_1);

	alloc += 10;
	if ((number = malloc(sizeof(char) * (alloc))))
		snprintf(number , alloc, "%f", nb);
	else
		return (NULL);
	return (number);
}

int main ()
{
	float test = -0.000005 ;

	printf("convert %f\n", test);
	printf("to %s\n", float_to_str(test) == NULL ? "NULL" :
		float_to_str(test));

}