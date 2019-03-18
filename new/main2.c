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

void		matr(char *filename)
{
	int		m_length;
	int		m_height;
	int		fd;

	m_length = 0;
	m_height = 0;
	map_length_height(&m_length, &m_height, filename);
	fd = open(filename, O_RDONLY);
}

/*int		rec(char c)
{
	if (c == 'a')
		return 1;
	else
	{
		write(2, "map error\n", 11);
		read(0, &c, 1);
		return rec(c);
	}
}
*/

int		*test()
{
	int *a;
	a = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; i++)
		a[i] = i * i;
	return a;
}
int			main(int argc, char **argv)
{
	char k[100];
	char *s = k;
	int *x;

	x = test();
	//while(read(0, k, 1))
	//{
	//	k = k + 1;
	//}
	//printf("%s\n", s);

	//rec(argv[1]);
	//int x = 1;
	//char str[100];
	//int ret;
	//if (x == 1)
	//write(2, "map error", 10);
	//ret = read(2, str, 100);
	//str[ret] = '\0';
	//printf("str = %s\n", str);
		// matr(argv[1]);
	return (0);
}