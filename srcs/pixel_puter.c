/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_puter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:35:37 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/24 14:19:31 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	radiantator(int degre)
{
	return (degre * 0.0174533);
}

void	matrice_ator(t_param *truc, float x, float y, float z)
{
	truc->tmpx = x;
	truc->tmpy = y * cos(truc->rotx) + z * -sin(truc->rotx);
	truc->tmpz = y * sin(truc->rotx) + z * cos(truc->rotx);
	x = truc->tmpx * cos(truc->roty) + truc->tmpz * sin(truc->roty);
	y = truc->tmpy;
	z = truc->tmpx * -sin(truc->roty) + truc->tmpz * cos(truc->roty);
	truc->tmpx = x * cos(truc->rotz) + y * -sin(truc->rotz);
	truc->tmpy = x * sin(truc->rotz) + y * cos(truc->rotz);
	truc->tmpz = z;
	truc->pointx[truc->fat] = truc->tmpx * truc->space * truc->zoom;
	truc->pointy[truc->fat] = truc->tmpy * truc->space * truc->zoom;
}

void	xyz(t_param *truc)
{
	int		x;
	int		y;

	truc->rotx = radiantator(truc->xrotate);
	truc->roty = radiantator(truc->yrotate);
	truc->rotz = radiantator(truc->zrotate);
	y = 0;
	truc->fat = 0;
	if (!(truc->pointx = (float*)malloc(sizeof(float) * truc->nbx * truc->nby)))
		return ;
	if (!(truc->pointy = (float*)malloc(sizeof(float) * truc->nbx * truc->nby)))
		return ;
	while (y < truc->nby)
	{
		x = 0;
		while (x < truc->nbx)
		{
			matrice_ator(truc, x, y, truc->tab[y][x]);
			x++;
			truc->fat++;
		}
		y++;
	}
}

void	pixel_puter_vertical(t_param *truc)
{
	int		i;

	i = 0;
	while (i + truc->nbx < (truc->nby * truc->nbx))
	{
		truc->x1 = truc->pointx[i] + 500 - (truc->nbx / 2 * truc->space
				* truc->zoom) + truc->xpadding;
		truc->y1 = truc->pointy[i] + 400 - (truc->nby / 2 * truc->space
				* truc->zoom) + truc->ypadding;
		truc->x2 = truc->pointx[i + truc->nbx] + 500 - (truc->nbx / 2
				* truc->space * truc->zoom) + truc->xpadding;
		truc->y2 = truc->pointy[i + truc->nbx] + 400 - (truc->nby / 2
				* truc->space * truc->zoom) + truc->ypadding;
		segment_tracer(truc);
		i++;
	}
	mlx_put_image_to_window(truc->id, truc->win, truc->img, 0, 0);
	free(truc->pointx);
	free(truc->pointy);
}

void	pixel_puter(t_param *truc)
{
	int		i;
	int		tmp;

	xyz(truc);
	i = -1;
	tmp = 0;
	while (++i < (truc->nby * truc->nbx) - 1)
	{
		truc->x1 = truc->pointx[i] + 500 - (truc->nbx / 2 *
				truc->space * truc->zoom) + truc->xpadding;
		truc->y1 = truc->pointy[i] + 400 - (truc->nby / 2 *
				truc->space * truc->zoom) + truc->ypadding;
		truc->x2 = truc->pointx[i + 1] + 500 - (truc->nbx /
				2 * truc->space * truc->zoom) + truc->xpadding;
		truc->y2 = truc->pointy[i + 1] + 400 - (truc->nby /
				2 * truc->space * truc->zoom) + truc->ypadding;
		segment_tracer(truc);
		tmp++;
		if (tmp == truc->nbx - 1)
		{
			i++;
			tmp = 0;
		}
	}
	pixel_puter_vertical(truc);
}
