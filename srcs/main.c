/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:47:18 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/24 16:24:38 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		nb_of_nbs(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
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

int		calc_space(t_param *truc)
{
	if (truc->nbx > truc->nby && 700 / (truc->nbx + 5) > 3)
		return (700 / (truc->nbx + 5));
	else if (700 / (truc->nby + 5) > 3)
		return (700 / (truc->nby + 5));
	return (3);
}

void	set_base(t_param *truc, char **av)
{
	truc->id = mlx_init();
	truc->win = mlx_new_window(truc->id, 1000, 800, "FDF");
	truc->img = mlx_new_image(truc->id, 1000, 800);
	truc->data_addr = mlx_get_data_addr(truc->img, &truc->bpx,
			&truc->size, &truc->idgaf);
	truc->zoom = 1;
	truc->xrotate = 0;
	truc->yrotate = 0;
	truc->zrotate = 0;
	truc->xpadding = 0;
	truc->ypadding = 0;
	truc->color = 0x0000FFFF;
	truc->space = calc_space(truc);
	truc = int_reader(truc, av);
	pixel_puter(truc);
}

int		main(int ac, char **av)
{
	t_param	*truc;
	int		fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	get_next_line(fd, av);
	if (error_one(*av) != 1)
		return (0);
	if ((truc = (t_param*)malloc(sizeof(t_param))) == NULL)
		return (0);
	truc->nbx = nb_of_nbs(*av);
	truc->nby = 1;
	while (get_next_line(fd, av))
	{
		if (error_one(*av) != 1 || nb_of_nbs(*av) != truc->nbx)
			return (0);
		truc->nby = truc->nby + 1;
	}
	close(fd);
	set_base(truc, av);
	mlx_key_hook(truc->win, keyboard_input, truc);
	mlx_loop(truc->id);
	return (0);
}
