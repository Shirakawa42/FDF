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
		truc->x1 = 50 + (25 * x);
		truc->y1 = 50;
		y = 0;
		while (y < truc->nby)
		{
			truc->x2 = 50 + (25 * x);
			truc->y2 = 50 + (25 * y);
			segment_tracer(truc);
			truc->x1 = 50 + (25 * x);
			truc->y1 = 50 + (25 * y);
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
		truc->x1 = 50;
		truc->y1 = 50 + (25 * y);
		x = 0;
		while (x < truc->nbx)
		{
			truc->x2 = 50 + (25 * x);
			truc->y2 = 50 + (25 * y);
			segment_tracer(truc);
			truc->x1 = 50 + (25 * x);
			truc->y1 = 50 + (25 * y);
			x++;
		}
		y++;
	}
	pixel_puter_vertical(truc);
}
