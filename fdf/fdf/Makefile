# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/14 14:42:25 by cbaldy            #+#    #+#              #
#    Updated: 2016/02/09 11:18:17 by cbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c get_next_line.c fdf_get_map.c fdf_mlx_control.c fdf_draw_iso.c \
	  fdf_1_aux.c fdf_rotation_img.c fdf_draw_axo.c fdf_draw_obl.c fdf_fill.c

INCLUDE = -I includes/

MLX = -lmlx -framework OpenGL -framework AppKit

FLAG = -Wall -Werror -Wextra

CFILES = $(addprefix src/, $(SRC))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(INCLUDE) $(CFILES)
	@gcc -o $(NAME) -L libft/ -lft $(MLX) $(OBJ)
	@echo "\x1b[32;02mfdf ready\x1b[0;m"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\x1b[0;01mclean"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\x1b[0;01mfclean"

re: fclean all
