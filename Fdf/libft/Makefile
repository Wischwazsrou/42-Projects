# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_bis                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffrimpon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 19:51:54 by ffrimpon          #+#    #+#              #
#    Updated: 2016/01/12 19:26:19 by ffrimpon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = `ls | grep "\.c"`
OBJ = `ls | grep "\.o"`

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
