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

char		**matr(int *map_length, int *map_height, char *filename)
{
	int		fd;
	int		i;
	char	**map_table;

	i = 0;
	map_length_height(map_length, map_height, filename);
	fd = open(filename, O_RDONLY);
	map_table = (char**)malloc(sizeof(*map_table) * *map_height);
	lseek(fd, 5, 1);
	while (i < *map_height)
	{
		map_table[i] = (char*)malloc(sizeof(**map_table) * *map_length + 1);
		read(fd, map_table[i], *map_length + 1);
		map_table[i][*map_length] = '\0';
		i++;
	}
	close(fd);
	return (map_table);
}

/*void	all_files(int ac, char **av)
{
	int		i;
	int		map_length;
	int		map_height;
	char	**map_table;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			map_height = 0;
			map_length = 0;
			map_table = matr(&map_length, &map_height, av[i]);
			ft_putmatr(map_table, map_height);
			i++;
		}
	}
}*/

int			*max_sqr_loc(char **map_table, int map_height, int map_length, int max_sqr_pos)
{
	int		t;
	int		i;
	int		j;
	int		z;
	int		*a;
	int		find_max_sqr;

	t = 0;
	z = 0;
	i = 0;
	j = 0;
	a = (int*)malloc(sizeof(*a) * 3);
	while (max_sqr_pos)
	{
		i = z;

		j = t++;
		if ((j + max_sqr_pos - 1) == map_length)
		{
			if ((i + max_sqr_pos) == map_height)
			{
				i = z = -1;
				max_sqr_pos--;
			}
			i = ++z;
			j = t = 0;
			t++;
		}
		//printf("i = %d, j = %d\n", i, j);
		while (i < max_sqr_pos + z)
		{
			while (j < max_sqr_pos + t)
			{
				if(map_table[i][j] == 'o')
				{
					break ;
					find_max_sqr = 0;
				}
				j++;
			}
			i++;
			j = 0;
			if (find_max_sqr == 0)
				break;
			find_max_sqr = 1;
		}
		if (find_max_sqr)
		{
			a[0] = i;
			a[1] = j;
			a[2] = max_sqr_pos;
			break ;
		}
	}

	return a;
}

int			main(int argc, char **argv)
{
	int		map_length;
	int		map_height;
	int		z, t;
	int		max_sqr_pos;
	int 	*x;
	char	**map_table;

	map_height = 0;
	map_length = 0;
	map_table = matr(&map_length, &map_height, argv[1]);
	// ft_putmatr(map_table, map_height);
	//printf("y = %d x = %d", map_height, map_length);
	if (map_height < map_length)
		max_sqr_pos = map_height;
	else
		max_sqr_pos = map_length;
	//printf("%d\n", max_sqr_pos);
	x = max_sqr_loc(map_table, map_height, map_length, max_sqr_pos);
	for (int i = 0; i < 3; i++)
		printf("%d \n", x[i]);
	/*while (max_square)
	{
		z = 0;
		t = 0;
		for (int i = z; i < max_square + z; i++)
		{
			for (int j = t; j < max_square - t; j++)
			{

			}

			if (max_square + z == map_length)
				break ;
			z++;
		}
		max_square--;	
	}*/
	return (0);
}




















