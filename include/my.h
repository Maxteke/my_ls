/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** 
*/

#ifndef MY_H
#define MY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char);
char    *my_put_octal(int);
void    write_perm(char *, int);
void    put_perm(int);
void    put_type(int);
void    put_hl(int);
int	my_strlen(char *);
void	my_putstr(char *);
int	my_put_nbr(int);

#endif /*MY_H_*/
