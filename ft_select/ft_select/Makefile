# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/14 14:42:25 by cbaldy            #+#    #+#              #
#    Updated: 2016/02/24 11:47:56 by cbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

SRC = main.c ft_read_term.c ft_set_term.c ft_create_list.c ft_print_list.c \
	  ft_tputs.c ft_prepare_print.c ft_move_cursor.c ft_return.c \
	  ft_remove_elem.c ft_handle_sig.c

INCLUDE = -I includes/

FLAG = -Wall -Werror -Wextra

CFILES = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(INCLUDE) $(CFILES)
	@make -C libft/ fclean && make -C libft && make -C libft/ clean
	@make -C ft_printf/ fclean && make -C ft_printf && make -C ft_printf/ clean
	@gcc -o $(NAME) -L libft/ -L ft_printf/ -lft -lftprintf -ltermcap $(OBJ)
	@echo "\x1b[32;02m$(NAME) ready\x1b[0;m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\x1b[0;01mclean"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\x1b[0;01mfclean"

re: fclean all
