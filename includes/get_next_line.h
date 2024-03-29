/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvasseur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:29:05 by lvasseur          #+#    #+#             */
/*   Updated: 2017/01/24 15:27:19 by lvasseur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 64

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../srcs/libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
