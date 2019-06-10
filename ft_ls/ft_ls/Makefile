# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/14 14:42:25 by cbaldy            #+#    #+#              #
#    Updated: 2016/01/06 17:17:01 by cbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ft_construct_list.c ft_print.c ft_read_argv.c ft_options_dir.c \
	  ft_recursive.c aux.c ft_sort_list.c ft_sort_errno.c ft_device.c \
	  ft_col_print.c ft_other_option.c ft_direct_path.c

SRC1 = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Werror -Wextra $(SRC)
	@make -C libft/ fclean
	@make -C libft/
	@make -C libft/ clean
	@gcc -o $(NAME) -L libft/ -lft $(SRC1)
	@echo "ft_ls ready"

clean:
	@/bin/rm -f $(SRC1)
	@echo "clean"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "fclean"

re: fclean all
