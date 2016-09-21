# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_bis                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 19:51:54 by ffrimpon          #+#    #+#              #
#    Updated: 2016/02/04 00:24:13 by ffrimpon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = `ls | grep "\.c"`
OBJ = `ls | grep "\.o"`

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -I ./includes -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
