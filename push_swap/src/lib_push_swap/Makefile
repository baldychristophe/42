# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 18:31:38 by cbaldy            #+#    #+#              #
#    Updated: 2016/11/25 19:14:36 by cbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libpushswap.a
ROOT_DIR = ../..

SRC = lps_check_validity.c lps_get_pile.c lps_jeton_list_ft.c lps_get_main.c \
	  lps_operate.c lps_main_ft.c lps_sol_list_ft.c lps_utils.c \
	  lps_operate_aux.c

OBJ = $(SRC:.c=.o)

INCLUDE = -I ../includes/
LIB= -L ../../libft/ -lft
FLAG = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(INCLUDE) $(SRC)
	@ar rc $(NAME) $(OBJ) $(ROOT_DIR)/libft/libft.a
	@ranlib $(NAME)
	@echo "\x1b[0;01m$(NAME) ready\x1b[0;m"

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
