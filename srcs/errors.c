/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:39:32 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/24 16:35:11 by lvasseur         ###   ########.fr       */
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

int		error_one(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == '-' || str[i] == ' ')
			i++;
		else
			return (-1);
	return (1);
}
