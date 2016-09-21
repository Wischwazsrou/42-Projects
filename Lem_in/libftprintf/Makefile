# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 13:57:18 by ffrimpon          #+#    #+#              #
#    Updated: 2016/06/04 19:01:11 by ffrimpon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
INC_PATH = ./includes/

SRC_NAME =	ft_printf.c print_s.c type.c print_c_low.c\
			print_x_uintmax.c check_flags.c print_o_uintmax.c\
			print_u_uintmax.c print_d_intmax.c ft_strrev.c\
			check_convert.c ft_putwchar.c ft_putwstr.c\
			ft_o_count.c print_pourcent.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
NORME := $(shell norminette $(SRC) $(INC_PATH)*.h | grep -B 1 Error)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation $(NAME) [\033[1;32mOK\033[0m]"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norme:
ifeq ($(NORME), )
	@echo "Norme srcs, includes [\033[1;32mOK\033[0m]"
else
	@norminette $(SRC) $(INC_PATH)*.h | grep -B 1 Error
endif
