# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/19 16:22:50 by ffrimpon          #+#    #+#              #
#    Updated: 2016/06/01 18:55:17 by ffrimpon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC_NAME =	main.c parsing.c solve.c path.c print.c count.c check.c bonus.c error.c check_cmd.c

OBJ= $(SRC:.c=.o)
	FLAGS= -Wall -Werror -Wextra
	INC_PATH= ./includes/
	SRC_PATH= ./srcs/
	LIB_PATH= ./libft/
	LIB_NAME= libft
	PRINTF_PATH= ./libftprintf/
	LIB_NAME= libftprintf

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

NORME := $(shell norminette $(SRC) $(INC_PATH)lem_in.h | grep -B 1 Error)

all: $(NAME)

$(NAME):
		@make -C $(LIB_PATH)
		@make -C $(PRINTF_PATH)
			@gcc $(FLAGS) -o $(NAME) -Ilibft $(LIB_PATH)libft.a -Ilibftprintf $(PRINTF_PATH)libftprintf.a $(SRC)
				@echo "Compilation $(NAME) [\033[1;32mOK\033[0m]"
		@touch correct_file.txt
		@chmod 777 correct_file.txt

clean:
		@rm -f $(OBJ)
			@make clean -C $(LIB_PATH)
		@touch correct_file.txt
		@rm correct_file.txt

fclean: clean
		@rm -f $(NAME)
			@make fclean -C $(LIB_PATH)

re: fclean all


norme:
	@norminette $(SRC) $(INC_PATH)lem_in.h | grep -B 1 Error

dev: fclean all norme
