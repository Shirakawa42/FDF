/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:51:18 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/06 12:26:30 by lvasseur         ###   ########.fr       */
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
}				t_param;

t_param		*segment_tracer(t_param *truc);

#endif
