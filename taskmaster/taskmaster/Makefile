# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/14 14:42:25 by cbaldy            #+#    #+#              #
#    Updated: 2016/05/13 11:42:11 by dbaldy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = taskmaster

SRC = main.c sh_set_term.c sh_read_prompt.c ft_1_aux.c ft_tputs.c\
	  term_edit_line.c com_list_ft.c hist_list_ft.c term_write_line.c\
	  print_command.c com_list_ft2.c term_mv_cursor.c hist_change.c \
	  sh_retrieve_cmd_line.c line_list_ft.c term_mv_horizontal.c hist_static.c \
	  line_list_ft2.c ed_ctrld_line.c yank_line.c copy_end_mode.c \
	  server_taskmaster.c builtin_tm.c

TAB = tab_mode.c tab_select.c tab_nb_col.c tab_nb_row.c tab_cursor_mvt.c \
	  tab_line_management.c tab_complete_line.c tab_prepare_select.c\
      tab_list_compl.c tab_string_match.c tab_supp.c suppr_elem.c\
	  glob_replace_bang.c glob_bang_digit.c glob_bang_str.c escape_quotes.c

INCLUDE = -I includes/

FLAG = -Wall -Werror -Wextra -g

LIBRARIES = -L libft/ -L ft_printf -lft -lftprintf -ltermcap

CFILES = $(addprefix src/, $(SRC))
CTAB = $(addprefix src/completion/, $(TAB))

OBJ = $(SRC:.c=.o)
OBJ2 = $(TAB:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(FLAG) $(INCLUDE) $(CFILES) $(CTAB)
	@#@make -C libft/ fclean && make -C libft && make -C libft/ clean
	@#@make -C ft_printf/ fclean && make -C ft_printf && make -C ft_printf/ clean
	@gcc -o $(NAME) $(LIBRARIES) $(OBJ) $(OBJ2)
	@mkdir obj && mv $(OBJ) $(OBJ2) obj
	@echo "\x1b[32;02m$(NAME) ready\x1b[0;m"

clean:
	@/bin/rm -rf obj
	@/bin/rm -rf $(OBJ) $(OBJ2)
	@echo "\x1b[0;01mclean\x1b[0;m"

fclean: clean
	@/bin/rm -f $(NAME)
	@rm -f **/*.pyc
	@rm -rf server
	@#@make -C libft fclean
	@#@make -C ft_printf fclean
	@echo "\x1b[0;01mfclean\x1b[0;m"

re: fclean all
