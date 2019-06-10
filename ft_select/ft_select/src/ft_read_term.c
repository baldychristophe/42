/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 11:26:06 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/23 16:43:04 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_get_move(t_arg_list **begin, int move, int fd)
{
	t_arg_list	*tmp;
	int			*win;

	if ((win = ft_prepare_print(*begin, fd)) == NULL)
		return (-1);
	tmp = *begin;
	while (tmp->nb != win[1] && tmp->op != 1 && tmp->op != 3)
		tmp = tmp->next;
	if (move < 5)
		ft_deplace_cursor(tmp, win, move);
	if (move == 5)
	{
		tmp->op = tmp->op ^ 2;
		ft_deplace_cursor(tmp, win, 2);
	}
	if (move == 6)
		return (ft_remove_elem(tmp, begin));
	free(win);
	return (0);
}

static int	ft_interpret(char *s, int len, t_arg_list **begin, int fd)
{
	if (len == 3 && s[0] == 27 && s[1] == 91 && s[2] > 64 && s[2] < 69)
		return (ft_get_move(begin, s[2] - 64, fd));
	else if ((len == 4 && s[0] == 27 && s[1] == 91 && s[2] == 51 &&
				s[3] == 126) || (len == 1 && s[0] == 127))
		return (ft_get_move(begin, 6, fd));
	else if (len == 1 && s[0] == ' ')
		return (ft_get_move(begin, 5, fd));
	else if (len == 1 && s[0] == 27)
		return (-1);
	else if (len == 1 && s[0] == 10)
		return (1);
	return (0);
}

int			ft_read_term(t_arg_list **begin, int fd)
{
	int		ret;
	char	*buf;
	int		i;

	buf = ft_strnew(10);
	ft_print_list(*begin, fd);
	ret = read(fd, buf, 9);
	i = ft_interpret(buf, ret, begin, fd);
	free(buf);
	if (i == 1)
		ft_return(*begin);
	return (i);
}
