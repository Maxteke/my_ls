/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** my_putchar
*/

#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}
