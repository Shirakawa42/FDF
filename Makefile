# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 20:45:05 by zadrien           #+#    #+#              #
#    Updated: 2017/01/24 14:32:59 by lvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = FDF

LIB = -L srcs/libft/ -lft

LIBFT = srcs/libft/libft.a

C_DIR = srcs/

SRCS = main.c pixel_puter.c keyboard_input.c segment_tracer.c \
       get_next_line.c

SRC = $(addprefix $(C_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

INC = -I includes -I srcs/libft/

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc -Wall -Wextra -Werror $^ -o $@ $(LIB) -lmlx -framework OpenGL -framework AppKit

$(LIBFT):
	make -C srcs/libft/

$(OBJ) : $(SRC)
	gcc -c -Wall -Wextra -Werror $^ $(INC)

clean :
	make clean -C srcs/libft/
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIBFT)
	rm -f libft.a
	rm -f $(NAME)

re : fclean all
