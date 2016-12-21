/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:47:18 by lvasseur          #+#    #+#             */
/*   Updated: 2016/12/21 17:08:00 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_puter(void *id, void *win, char **av, int x, int y)
{
	int		g;

	g = 0;
	while (g < y)
	{
		
		g++;
	}
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
	x = ft_strlen(*av);
	y = 1;
	while (get_next_line(fd, av))
		y++;
	id = mlx_init();
	win = mlx_new_window(id, 15 * x, 50 * y, "FDF");
	pixel_puter(id, win, av, x, y);
	mlx_loop(id);
	return (0);
}
