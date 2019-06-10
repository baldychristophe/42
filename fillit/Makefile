# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 10:30:59 by cbaldy            #+#    #+#              #
#    Updated: 2015/12/03 11:20:24 by dbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = aux.c ft_check.c main.c stock.c ft_print_sol.c ft_transform.c \
	  ft_valid.c resol.c

SRC1 = aux.o ft_check.o main.o stock.o ft_print_sol.o ft_transform.o\
	   ft_valid.o resol.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC1)

clean:
	/bin/rm -f $(SRC1)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
