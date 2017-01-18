/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_tracer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:25:30 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/16 15:13:17 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_param		*revert_xy(t_param *truc)
{
	int		tmp;

	tmp = truc->x1;
	truc->x1 = truc->y1;
	truc->y1 = tmp;
	tmp = truc->x2;
	truc->x2 = truc->y2;
	truc->y2 = tmp;
	return (truc);
}

void	up_down(t_param *truc, int dx, int dy, int e)
{
	truc = revert_xy(truc);
	e = truc->x2 - truc->x1;
	if (truc->x2 < truc->x1)
		e = truc->x1 - truc->x2;
	dx = e * 2;
	dy = (truc->y2 - truc->y1) * 2;
	if (dy < 0)
		dy = (truc->y1 - truc->y2) * 2;
	while (truc->x1 != truc->x2)
	{
		*(unsigned *)(truc->data_addr + ((truc->x1 + truc->padding) *
					truc->size) + ((truc->y1 + truc->padding) *
					truc->bpx / 8)) = 0x0000FFFF;
		if (truc->x2 < truc->x1)
			truc->x1 = truc->x1 - 2;
		truc->x1 = truc->x1 + 1;
		if ((e = e - dy) <= 0)
		{
			if (truc->y1 > truc->y2)
				truc->y1 = truc->y1 - 2;
			truc->y1 = truc->y1 + 1;
			e = e + dx;
		}
	}
}

void	left_right(t_param *truc, int dx, int dy, int e)
{
	e = truc->x2 - truc->x1;
	if (truc->x2 < truc->x1)
		e = truc->x1 - truc->x2;
	dx = e * 2;
	dy = (truc->y2 - truc->y1) * 2;
	if (dy < 0)
		dy = (truc->y1 - truc->y2) * 2;
	while (truc->x1 != truc->x2)
	{
		*(unsigned *)(truc->data_addr + ((truc->y1 + truc->padding) *
					truc->size) + ((truc->x1 + truc->padding) *
					truc->bpx / 8)) = 0x0000FFFF;
		if (truc->x2 < truc->x1)
			truc->x1 = truc->x1 - 2;
		truc->x1 = truc->x1 + 1;
		if ((e = e - dy) <= 0)
		{
			if (truc->y1 > truc->y2)
				truc->y1 = truc->y1 - 2;
			truc->y1 = truc->y1 + 1;
			e = e + dx;
		}
	}
}

void	loltest(t_param *truc, int dx, int dy, int e)
{
	e = truc->x2cp - truc->x1cp;
	if (truc->x2cp < truc->x1cp)
		e = truc->x1cp - truc->x2cp;
	dx = e * 2;
	dy = (truc->y2cp - truc->y1cp) * 2;
	if (dy < 0)
		dy = (truc->y1cp - truc->y2cp) * 2;
	while (truc->x1cp != truc->x2cp)
	{
		if (truc->x2cp < truc->x1cp)
			truc->x1cp = truc->x1cp - 2;
		truc->x1cp = truc->x1cp + 1;
		if ((e = e - dy) <= 0)
		{
			if (truc->y1cp > truc->y2cp)
				truc->y1cp = truc->y1cp - 2;
			truc->y1cp = truc->y1cp + 1;
			e = e + dx;
		}
	}
	if (truc->y1cp == truc->y2cp)
		left_right(truc, dx, dy, e);
	else
		up_down(truc, dx, dy, e);
}

void	segment_tracer(t_param *truc)
{
	int		dx;
	int		dy;
	int		e;

	truc->x1 = truc->x1 * truc->zoom;
	truc->y1 = truc->y1 * truc->zoom;
	truc->x2 = truc->x2 * truc->zoom;
	truc->y2 = truc->y2 * truc->zoom;
	truc->x1cp = truc->x1;
	truc->x2cp = truc->x2;
	truc->y1cp = truc->y1;
	truc->y2cp = truc->y2;
	e = 0;
	dx = 0;
	dy = 0;
	loltest(truc, dx, dy, e);
}
