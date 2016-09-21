# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 20:02:38 by ffrimpon          #+#    #+#              #
#    Updated: 2015/12/05 17:47:38 by ffrimpon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = `ls | grep "\.c"`
OBJ = `ls | grep "\.o"`

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -o $(NAME) libft.a $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
