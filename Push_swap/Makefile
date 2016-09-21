# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/31 16:03:43 by ffrimpon          #+#    #+#              #
#    Updated: 2016/03/31 16:03:45 by ffrimpon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_NAME =	main.c f_swap.c f_push.c f_rotate.c f_rev_rotate.c parsing.c\
			messages.c solve.c f_for_solve.c
OBJ= $(SRC:.c=.o)
FLAGS= -Wall -Werror -Wextra
INC_PATH= ./includes/
SRC_PATH= ./srcs/
LIB_PATH= ./libft/
LIB_NAME= libft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

NORME := $(shell norminette $(SRC) $(INC_PATH)push_swap.h | grep -B 1 Error)

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH)
	@gcc $(FLAGS) -o $(NAME) -Ilibft $(LIB_PATH)libft.a $(SRC)
	@echo "Compilation $(NAME) [\033[1;32mOK\033[0m]"

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all


norme:
ifeq ($(NORME), )
	@echo "Norme srcs et includes [\033[1;32mOK\033[0m]"
else
	@norminette $(SRC) $(INC_PATH)push_swap.h | grep -B 1 Error
endif

dev: fclean all norme 
