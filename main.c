/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:47:18 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/09 12:30:52 by lvasseur         ###   ########.fr       */
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

int		w_changes(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' && str[i])
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

t_param	*int_reader(t_param *truc, char **av)
{
	int		i;
	int		y;
	int		fd;
	int		w;

	i = truc->nbx + 1;
	if ((truc->tab = (int**)malloc(sizeof(int*) * (truc->nby * 2))) == NULL)
		return (NULL);
	while (--i)
		if ((truc->tab[i - 1] = (int*)malloc(sizeof(int) * truc->nbx)) == NULL)
			return (NULL);
	fd = open(av[1], O_RDONLY);
	i = -1;
	while (++i < truc->nby)
	{
		get_next_line(fd, av);
		w = 0;
		y = 0;
		while (y < truc->nbx)
		{
			truc->tab[i][y++] = ft_atoi(&av[0][w]);
			w += w_changes(&av[0][w]);
		}
	}
	return (truc);
}

void	pixel_puter(t_param *truc, char **av)
{
	int		x;
	int		y;

	truc = int_reader(truc, av);
	y = 0;
	truc->padding = 0;
	truc->zoom = 1;
	truc = segment_tracer(truc);
	/*while (y < truc->nby)
	{
		x = 0;
		while (x < truc->nbx)
		{
			truc->x2 =  50 + (50 * x) + (truc->tab[y][x] * 2);
			truc->y2 = 50 + (50 * y) - (truc->tab[y][x] * 2);
			truc = segment_tracer(truc);
			truc->x1 = truc->x2;
			truc->y1 = truc->y2;
			x++;
		}
		y++;
	}*/
	mlx_put_image_to_window(truc->id, truc->win, truc->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_param	*truc;
	int		fd;

	if ((truc = (t_param*)malloc(sizeof(t_param))) == NULL)
		return (0);
	//if (ac != 2)
	//	return (0);


	truc->x1 = atoi(av[2]);
	truc->y1 = atoi(av[3]);
	truc->x2 = atoi(av[4]);
	truc->y2 = atoi(av[5]);


	truc->zoom = 1;
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, av);
	truc->nbx = nb_of_nbs(*av);
	truc->nby = 1;
	while (get_next_line(fd, av))
		truc->nby = truc->nby + 1;
	close(fd);
	truc->id = mlx_init();
	truc->win = mlx_new_window(truc->id, 800, 600, "FDF");
	truc->img = mlx_new_image(truc->id, 800, 600);
	truc->data_addr = mlx_get_data_addr(truc->img, &truc->bpx,
			&truc->size, &truc->idgaf);
	pixel_puter(truc, av);
	mlx_loop(truc->id);
	return (0);
}
