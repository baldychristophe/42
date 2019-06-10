# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/14 14:42:25 by cbaldy            #+#    #+#              #
#    Updated: 2016/12/14 12:00:31 by cbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c ps_solve.c ps_bubble_sort.c ps_quick_split.c old_solve.c \
	  ps_brutforce.c ps_is_coherent_move.c \
	  ps_res_v3.c ps_next_move.c ps_next_move_aux.c \
	  ps_v4.c ps_recompile.c

INCLUDE = -I ../includes/
FLAG = -Wall -Werror -Wextra
LIBFT = -L ../../libft/ -lft
PS_LIB = -L ../lib_push_swap -lpushswap
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(INCLUDE) $(SRC)
	@gcc -o $(NAME) $(LIBFT) $(PS_LIB) $(OBJ)
	@mkdir obj && mv $(OBJ) obj
	@echo "\x1b[32;02m$(NAME) ready\x1b[0;m"

clean:
	@/bin/rm -rf obj
	@/bin/rm -rf $(OBJ)
	@#@echo "\x1b[0;01mclean\x1b[0;m"

fclean: clean
	@/bin/rm -f $(NAME)
	@#@echo "\x1b[0;01mfclean\x1b[0;m"

re: fclean all
