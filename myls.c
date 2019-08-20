/*
** EPITECH PROJECT, 2017
** my_ls
** File description:
** 
*/

#include "my.h"

char	*put_slash(char *dirname, char *filename)
{
	int	i = 0;
	int	size_d;
	int	size_f;
	char	*path;
	int	a = 0;

	size_d = my_strlen(dirname);
	size_f = my_strlen(filename);
	path = malloc(sizeof(char) * size_d + size_f + 2);
	while (dirname[i] != 0) {
		path[i] = dirname[i];
		i++;
	}
	if (dirname[i] != '/') {
		path[i] = '/';
		i++;
	}
	while (filename[a] != 0) {
		path[i] = filename[a];
		i++;
		a++;
	}
	path[i] = 0;
	return (path);
}

int	my_ls_l(char *dirname, char *filename)
{
	char	*path;
	struct stat stats;
	struct passwd *pwd;
	struct group *gr;

	path = put_slash(dirname, filename);
	if(stat(path, &stats) == -1)
		return (84);
	pwd = getpwuid(stats.st_uid);
	gr = getgrgid(stats.st_gid);
	put_perm(stats.st_mode);
	put_hl(stats.st_nlink);
	my_putchar(' ');
	my_putstr(pwd->pw_name);
	my_putchar(' ');
	my_putstr(gr->gr_name);
	my_putchar(' ');
	my_put_nbr(stats.st_size);
	my_putchar(' ');
	free(path);
}

void my_ls(int ac, char **av)
{
    DIR *my_dir;
	struct dirent *struc;

	my_dir = opendir(av[ac-1]);
	while ((struc = readdir(my_dir)) != NULL) {
		if (av[1][1] == 'l') {
			put_type(struc->d_type);
			my_ls_l(av[ac - 1], struc->d_name);
		}
		else
			my_putchar(' ');
		my_putstr(struc->d_name);
		my_putchar('\n');
	}
	closedir(my_dir);
}

int	main(int ac, char **av)
{
	if (ac < 2)
        return (84);
    my_ls(ac, av);
}
