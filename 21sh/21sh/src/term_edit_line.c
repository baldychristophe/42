/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_edit_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:51:22 by cbaldy            #+#    #+#             */
/*   Updated: 2016/03/02 19:28:44 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	term_move_cursor(int move, t_com_list *begin)
{
	if (move == 3 && com_list_count(begin) > g_local->curs -
			g_local->prompt - 1)
	{
		ft_tputs("nd", 1, 0);
		g_local->curs += 1;
	}
	else if (move == 4 && g_local->curs > g_local->prompt + 1)
	{
		ft_tputs("le", 1, 0);
		g_local->curs -= 1;
	}
	return (0);
}

static int	term_move_home_end(int move, t_com_list *begin)
{
	int			i;
	int			line;

	line = g_local->curs / (g_local->nb_col + 2);
	if (move == 2)
	{
		ft_tputs("UP", 1, line);
		ft_tputs("cr", 1, 0);
		ft_tputs("RI", 1, g_local->prompt);
		g_local->curs = g_local->prompt + 1;
	}
	else if (move == 0)
	{
		i = com_list_count(begin) + g_local->prompt;
		ft_tputs("DO", 1, (i / (g_local->nb_col + 1)) - line);
		ft_tputs("cr", 1, 0);
		ft_tputs("RI", 1, i % g_local->nb_col);
		g_local->curs = i + 1;
	}
	return (0);
}

int		term_edit_line(char *buf, int len, t_com_list **begin, t_hist_list **hist)
{
	if (len == 3 && buf[0] == 27 && buf[1] == 91)
	{
		if(buf[2] == 65 || buf[2] == 66)
			return (hist_change(buf[2] - 64, hist, begin));
		if(buf[2] == 67 || buf[2] == 68)
			return (term_move_cursor(buf[2] - 64, *begin));
		if (buf[2] == 70 || buf[2] == 72)
			return (term_move_home_end(buf[2] - 70, *begin));
	}
	return (buf[0]);
}
