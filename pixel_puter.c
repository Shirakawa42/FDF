/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_puter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:35:37 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/18 14:22:24 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_puter_vertical(t_param *truc)
{
	int		x;
	int		y;

	x = 0;
	while (x < truc->nbx)
	{
		truc->x1 = (500 - (truc->space * truc->nbx / 2)) + (truc->space * x);
		truc->y1 = 400 - (truc->space * truc->nby / 2);
		y = 0;
		while (y < truc->nby)
		{
			truc->x2 = (500 - (truc->space * truc->nbx / 2)) + (truc->space * x);
			truc->y2 = (400 - (truc->space * truc->nby / 2)) + (truc->space * y) - truc->tab[y][x];
			segment_tracer(truc);
			truc->x1 = (500 - (truc->space * truc->nbx / 2)) + (truc->space * x);
			truc->y1 = (400 - (truc->space * truc->nby / 2)) + (truc->space * y) - truc->tab[y][x];
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(truc->id, truc->win, truc->img, 0, 0);
}

void	pixel_puter(t_param *truc)
{
	int		x;
	int		y;

	y = 0;
	truc->padding = 0;
	while (y < truc->nby)
	{
		truc->x1 = 500 - (truc->space * truc->nbx / 2);
		truc->y1 = (400 - (truc->space * truc->nby / 2)) + (truc->space * y);
		x = 0;
		while (x < truc->nbx)
		{
			truc->x2 = (500 - (truc->space * truc->nbx / 2)) + (truc->space * x);
			truc->y2 = (400 - (truc->space * truc->nby / 2)) + (truc->space * y) - truc->tab[y][x];
			segment_tracer(truc);
			truc->x1 = (500 - (truc->space * truc->nbx / 2)) + (truc->space * x);
			truc->y1 = (400 - (truc->space * truc->nby / 2)) + (truc->space * y) - truc->tab[y][x];
			x++;
		}
		y++;
	}
	pixel_puter_vertical(truc);
}
