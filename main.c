/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:47:18 by lvasseur          #+#    #+#             */
/*   Updated: 2016/12/22 13:13:58 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		nb_of_nbs(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			nb++;
		}
		else
			while (str[i] == ' ')
				i++;
	}
	return (nb);
}

void	pixel_puter(void *id, void *win, char **av, int x, int y)
{
	
}

int		main(int ac, char **av)
{
	void	*id;
	void	*win;
	int		fd;
	int		x;
	int		y;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, av);
	x = nb_of_nbs(*av);
	y = 1;
	while (get_next_line(fd, av))
		y++;
	id = mlx_init();
	win = mlx_new_window(id, 50 * x, 50 * y, "FDF");
	pixel_puter(id, win, av, x, y);
	mlx_loop(id);
	return (0);
}
