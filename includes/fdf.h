/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:51:18 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/24 14:34:21 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"
# include "get_next_line.h"
# include <math.h>

	typedef struct	s_param
{
	int		nbx;
	int		nby;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		x1cp;
	int		y1cp;
	int		x2cp;
	int		y2cp;
	float	zoom;
	int		xpadding;
	int		ypadding;
	void	*win;
	void	*id;
	int		bpx;
	int		size;
	char	*data_addr;
	void	*img;
	int		idgaf;
	int		**tab;
	float	rotx;
	float	roty;
	float	rotz;
	float	tmpx;
	float	tmpy;
	float	tmpz;
	int		space;
	float	*pointx;
	float	*pointy;
	int		color;
	int		xrotate;
	int		yrotate;
	int		zrotate;
	int		fat;
}				t_param;

void	pixel_puter(t_param *truc);
void	segment_tracer(t_param *truc);
int		keyboard_input(int keycode, void *truc);
t_param	*int_reader(t_param *truc, char **av);
int		w_changes(char *str);

#endif
