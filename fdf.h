/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:51:18 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/18 13:05:44 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

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
	int		zoom;
	int		padding;
	void	*win;
	void	*id;
	int		bpx;
	int		size;
	char	*data_addr;
	void	*img;
	int		idgaf;
	int		**tab;
	int		z;
	int		space;
}				t_param;

void	segment_tracer(t_param *truc);
void	pixel_puter(t_param *truc);
int		keyboard_input(int keycode, void *truc);

#endif
