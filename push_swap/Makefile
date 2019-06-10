# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/01 20:14:13 by cbaldy            #+#    #+#              #
#    Updated: 2016/11/05 09:55:43 by cbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = project

INCLUDE = -I includes/

FLAG = -Wall -Werror -Wextra

LIBPS = src/lib_push_swap/
LIBFT = -L libft/ -lft -L $(LIBPS) -lpushswap
CH = src/checker/
PS = src/push_swap/

all: $(NAME)

$(NAME):
	@make -C $(LIBPS) re && make -C $(LIBPS) clean
	@#@make -C libft/ re && make -C libft/ clean
	@make -C $(CH) fclean && make -C $(CH) && mv $(CH)checker .
	@make -C $(PS) fclean && make -C $(PS) && mv $(PS)push_swap .
	@echo "\x1b[32;02m$(NAME) ready\x1b[0;m"

clean:
	@make -C $(CH) clean
	@make -C $(PS) clean
	@echo "\x1b[0;01mclean\x1b[0;m"

fclean: clean
	@make -C $(LIBPS) fclean
	@#@make -C libft/ fclean
	@make -C $(CH) fclean && /bin/rm -f checker
	@make -C $(PS) fclean && /bin/rm -f push_swap
	@echo "\x1b[0;01mfclean\x1b[0;m"

re: fclean all

libps:
	make -C $(LIBPS) re

ch:
	make -C checker/ re
