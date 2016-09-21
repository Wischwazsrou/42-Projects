# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vklepper <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 19:16:04 by vklepper          #+#    #+#              #
#    Updated: 2016/02/22 13:33:41 by ffrimpon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

SRC = src/main.c src/draw.c src/data.c src/key.c src/mandelbrot.c src/color.c src/julia.c src/expose.c src/burningship.c src/tree.c src/galaxy.c
OBJ = src/main.o src/draw.o src/data.o src/key.o src/mandelbrot.o src/color.o src/julia.o src/expose.o src/burningship.o src/tree.o src/galaxy.o

all: $(NAME)

$(NAME):
	@make -C libft/
	@gcc -Wall -Wextra -Werror -o $(NAME) -Ilibft libft/libft.a $(SRC) -lmlx -framework OpenGL -framework AppKit

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
