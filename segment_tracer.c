/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_tracer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 12:25:30 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/10 15:37:35 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_param		*revert_x(t_param *truc)
{
	int		tmp;

	tmp = truc->x1;
	truc->x1 = truc->x2;
	truc->x2 = tmp;
	return (truc);
}

t_param		*revert_y(t_param *truc)
{
	int		tmp;

	tmp = truc->y1;
	truc->y1 = truc->y2;
	truc->y2 = tmp;
	return (truc);
}

t_param		*left_right(t_param *truc, int dx, int dy, int e)
{
	if (truc->x1 < truc->x2)
	{
		revert_x(truc);
		revert_y(truc);
	}
	e = truc->x1 - truc->x2;
	dx = e * 2;
	dy = (truc->y2 - truc->y1) * 2;
	if (truc->y1 > truc->y2)
		dy = (truc->y1 - truc->y2) * 2;
	while (truc->x1 > truc->x2)
	{
		*(unsigned *)(truc->data_addr + ((truc->y1 + truc->padding) *
					truc->size) + ((truc->x1 + truc->padding) *
						truc->bpx / 8)) = 0x0000FFFF;
		truc->x1 = truc->x1 - 1;
		if ((e = e - dy) <= 0)
		{
			truc->y1 = truc->y1 + 1;
			if (truc->y1 > truc->y2)
				truc->y1 = truc->y1 - 2;
			e = e + dx;
		}
	}
	return (truc);
}

t_param		*up_down(t_param *truc, int dx, int dy, int e)
{
	if (truc->y1 > truc->y2)
	{
		revert_x(truc);
		revert_y(truc);
	}
	e = truc->x1 - truc->x2;
	dx = e * 2;
	dy = (truc->y2 - truc->y1) * 2;
	while (truc->y1 > truc->y2)
	{
		*(unsigned *)(truc->data_addr + ((truc->x1 + truc->padding) *
					truc->size) + ((truc->y1 + truc->padding) *
						truc->bpx / 8)) = 0x0000FFFF;
		truc->y1 = truc->y1 - 1;
		if ((e = e - dy) <= 0)
		{
			truc->y1 = truc->y1 + 1;
			e = e + dx;
		}
	}
	return (truc);
}

t_param		*segment_tracer(t_param *truc)
{
	int		dx;
	int		dy;
	int		e;

	truc->x1 = truc->x1 * truc->zoom;
	truc->y1 = truc->y1 * truc->zoom;
	truc->x2 = truc->x2 * truc->zoom;
	truc->y2 = truc->y2 * truc->zoom;
	e = 0;
	dx = 0;
	dy = 0;
	return (up_down(truc, dx, dy, e));
	return (left_right(truc, dx, dy, e));
}
