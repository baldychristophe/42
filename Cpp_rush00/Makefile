# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cobrunet <cobrunet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/20 14:36:23 by cobrunet          #+#    #+#              #
#    Updated: 2017/01/15 19:30:45 by cbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = ft_retro

CC = clang++

SRC_PATH = ./src/
INC_PATH = ./inc/

SRC_NAME = main.cpp Game.cpp Enemy.cpp Input.cpp Obstacle.cpp Player.cpp \
		   Scene.cpp AGameElement.cpp ANonPlayable.cpp Missile.cpp

CFLAGS = -Wall -Wextra -Werror
OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.cpp=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

all: $(NAME)
$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "\033[36mFT_RETRO:\033[0m [\033[35mCompilation:\033[0m\033[32m $@\033[0m]"
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC_PATH)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -lncurses -o $@ $^
	@echo "\033[36m****\033[0m"
	@echo "\033[36m     FT_RETRO - OK\033[0m"
	@echo "\033[36m****\033[0m"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "[\033[31mSuppression des .o\033[0m]"

fclean: clean
	@rm -f $(NAME)
	@echo "[\033[31mSuppression de \033[36m$(NAME)\033[0m\033[0m]"

re: fclean all
