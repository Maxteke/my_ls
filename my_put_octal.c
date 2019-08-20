/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** 
*/

#include "my.h"

char	*my_put_octal(int nb)
{
	char	*res;
	int	i;
	int	nb_backup;

	i = 0;
	nb_backup = nb;
	while (nb != 0)	{
		nb = nb / 8;
		i = i + 1;
	}
	res = malloc(sizeof(char) * i);
	res[i] = 0;
	while (nb_backup != 0)	{
		i = i - 1;
		res[i] = (nb_backup % 8) + 48;
		nb_backup = nb_backup / 8;
	}
	return (res);
}

void	write_perm(char *perm, int nb)
{
	if (perm[nb] == '0')
		my_putstr("---");
	else if (perm[nb] == '1')
		my_putstr("--x");
	else if (perm[nb] == '2')
		my_putstr("-w-");
	else if (perm[nb] == '3')
		my_putstr("-wx");
	else if (perm[nb] == '4')
		my_putstr("r--");
	else if (perm[nb] == '5')
		my_putstr("r-x");
	else if (perm[nb] == '6')
		my_putstr("rw-");
	else if (perm[nb] == '7')
		my_putstr("rwx");
}

void	put_perm(int nb)
{
	char	*perm = my_put_octal(nb);
	int	a = my_strlen(perm) - 3;
	int	i = 0;

	while (i < 3) {
		write_perm(perm, a);
		a++;
		i++;
	}
	my_putchar(' ');
	free(perm);
}

void	put_type(int nb)
{
	if (nb == 1)
		my_putchar('p');
	else if (nb == 2)
		my_putchar('c');
	else if (nb == 4)
		my_putchar('d');
	else if (nb == 6)
		my_putchar('b');
	else if (nb == 12)
		my_putchar('l');
	else if (nb == 14)
		my_putchar('s');
	else
		my_putchar('-');
}

void	put_hl(int nb)
{
	my_put_nbr(nb);
}
