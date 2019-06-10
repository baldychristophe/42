/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:09:00 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/24 19:28:11 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef struct			s_arg_list
{
	char				*name;
	int					op;
	int					nb;
	struct s_arg_list	*next;
	struct s_arg_list	*previous;
}						t_arg_list;

t_arg_list				*g_begin;
int						g_fd;

int						ft_set_term(int flag);
int						ft_read_term(t_arg_list **begin, int fd);
t_arg_list				*ft_create_list(int ac, char **av);
int						ft_print_list(t_arg_list *begin, int fd);
int						ft_tputs(char *s, int nb_l, int flag, int fd);
int						*ft_prepare_print(t_arg_list *begin, int fd);
int						ft_deplace_cursor(t_arg_list *tmp, int *win, int move);
int						ft_return(t_arg_list *begin);
int						ft_remove_elem(t_arg_list *tmp, t_arg_list **begin);
int						ft_reset_term(int fd);
int						ft_free_list(t_arg_list *begin);
void					ft_handle_sig(t_arg_list *begin, int fd);

#endif
