/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:01:34 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/24 17:32:18 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	update(t_param *truc)
{
	mlx_destroy_image(((t_param*)truc)->id, ((t_param*)truc)->img);
	((t_param*)truc)->img = mlx_new_image(((t_param*)truc)->id, 1000, 800);
	((t_param*)truc)->data_addr = mlx_get_data_addr(((t_param*)truc)->img,
		&((t_param*)truc)->bpx,
		&((t_param*)truc)->size, &((t_param*)truc)->idgaf);
	pixel_puter((t_param*)truc);
}

void	keyboard_input_other(int keycode, void *truc)
{
	if (keycode == 126)
		((t_param*)truc)->xrotate += 5;
	if (keycode == 125)
		((t_param*)truc)->xrotate -= 5;
	if (keycode == 124)
		((t_param*)truc)->yrotate += 5;
	if (keycode == 123)
		((t_param*)truc)->yrotate -= 5;
	if (keycode == 89)
		((t_param*)truc)->zrotate += 5;
	if (keycode == 91)
		((t_param*)truc)->zrotate -= 5;
	if (keycode == 13)
		((t_param*)truc)->ypadding -= 10;
	if (keycode == 0)
		((t_param*)truc)->xpadding -= 10;
	if (keycode == 1)
		((t_param*)truc)->ypadding += 10;
	if (keycode == 2)
		((t_param*)truc)->xpadding += 10;
}

void	keyboard_input_exit(int keycode, t_param *truc)
{
	int		y;

	if (keycode == 53)
	{
		y = -1;
		while (++y < truc->nby)
			free(truc->tab[y]);
		free(truc->tab);
		free(truc);
		exit(1);
	}
}

int		keyboard_input(int keycode, void *truc)
{
	if (keycode == 69 || keycode == 78)
		(keycode == 69) ? (((t_param*)truc)->zoom += 0.05) :
			(((t_param*)truc)->zoom -= 0.05);
	if (keycode == 83)
		((t_param*)truc)->color = 0x00FF0000;
	if (keycode == 84)
		((t_param*)truc)->color = 0x00FFFF00;
	if (keycode == 85)
		((t_param*)truc)->color = 0x0000FFFF;
	if (keycode == 86)
		((t_param*)truc)->color = 0x00FFFFFF;
	if (keycode == 87)
		((t_param*)truc)->color = 0x00F00FF0;
	if (keycode == 88)
		((t_param*)truc)->color = 0x0000FF00;
	keyboard_input_exit(keycode, (t_param*)truc);
	keyboard_input_other(keycode, truc);
	keyboard_input_rezet(keycode, (t_param*)truc);
	update(truc);
	return (0);
}
