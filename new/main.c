/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrandpa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:12:32 by tgrandpa          #+#    #+#             */
/*   Updated: 2019/03/18 20:12:34 by tgrandpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
		ft_putchar(str[i++]);
}

void		map_length_height(int *x, int *y, char *filename)
{
	int 	fd;
	char 	x_or_y;

	fd = open(filename, O_RDONLY);
	while (read(fd, &x_or_y, 1))
	{
		if (x_or_y >= '0' && x_or_y <= '9')
			*y = *y * 10 + x_or_y - '0';
		else
			break ;
	}
	lseek(fd, 3, 1);
	while (read(fd, &x_or_y, 1))
	{
		if (x_or_y == '\n')
			break ;
		*x = *x + 1;
	}
	close(fd);
}

void		ft_putmatr(char **map_table, int map_height)
{
	int		i;

	i = 0;
	while (i < map_height)
	{
		ft_putstr(map_table[i++]);
		ft_putchar('\n');
	}
}

char		**matr(char *filename)
{
	int		map_length;
	int		map_height;
	int		fd;
	int		i;
	char	**map_table;

	map_length = 0;
	map_height = 0;
	i = 0;
	map_length_height(&map_length, &map_height, filename);
	fd = open(filename, O_RDONLY);
	map_table = (char**)malloc(sizeof(*map_table) * map_height);
	lseek(fd, 5, 1);
	while (i < map_height)
	{
		map_table[i] = (char*)malloc(sizeof(**map_table) * map_length + 1);
		read(fd, map_table[i], map_length + 1);
		map_table[i][map_length] = '\0';
		i++;
	}
	close(fd);
	return (map_table);
}

void	rec()
{
	
}

int			main(int argc, char **argv)
{
	matr(argv[1]);
	return (0);
}