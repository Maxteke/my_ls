/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** 
*/

#include "my.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != 0)
		i++;
	return (i);
}
