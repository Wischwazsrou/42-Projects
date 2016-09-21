# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/03 18:16:14 by ffrimpon          #+#    #+#              #
#    Updated: 2016/02/10 11:42:29 by ffrimpon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c srcs/parsing.c srcs/iso.c srcs/draw.c srcs/color.c srcs/key.c
OBJ = srcs/main.o srcs/parsing.o srcs/iso.o srcs/draw.o srcs/color.o srcs/key.o

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -Wall -Wextra -Werror -o $(NAME) -Ilibft libft/libft.a $(SRC) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
