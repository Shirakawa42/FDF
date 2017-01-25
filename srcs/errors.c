/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:39:32 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/25 13:55:00 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	keyboard_input_rezet(int keycode, t_param *truc)
{
	if (keycode == 15)
	{
		truc->xrotate = 0;
		truc->yrotate = 0;
		truc->zrotate = 0;
		truc->xpadding = 0;
		truc->ypadding = 0;
		truc->color = 0x0000FFFF;
		truc->zoom = 1;
	}
}

int		errors(char **av)
{
	int		fd;
	int		max;

	fd = open(av[1], O_RDONLY);
	get_next_line(fd, av);
	max = nb_of_nbs(*av);
	while (get_next_line(fd, av))
		if (nb_of_nbs(*av) != max)
			return (-1);
	close(fd);
	return (0);
}
