/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:06:10 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/23 17:17:02 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_change_op(t_arg_list *tmp, int direction, int place)
{
	t_arg_list	*tmp2;
	int			i;

	tmp2 = tmp;
	i = 0;
	while (i < place)
	{
		tmp2 = (direction > 0 ? tmp2->next : tmp2->previous);
		i++;
	}
	tmp2->op += 1;
	return (0);
}

static int	ft_right_move(t_arg_list *tmp, int *win)
{
	if (tmp->nb + win[4] >= win[1])
		return (ft_change_op(tmp, -1, win[4] * (tmp->nb / win[4])));
	else
		return (ft_change_op(tmp, 1, win[4]));
}

static int	ft_left_move(t_arg_list *tmp, int *win)
{
	int		k;

	if (tmp->nb - win[4] < 0)
	{
		k = (tmp->nb + (win[4] * (win[3] - 1)) >= win[1] ? 2 : 1);
		return (ft_change_op(tmp, 1, win[4] * (win[3] - k)));
	}
	else
		return (ft_change_op(tmp, -1, win[4]));
}

int			ft_deplace_cursor(t_arg_list *tmp, int *win, int move)
{
	tmp->op -= 1;
	if (move == 3)
		return (ft_right_move(tmp, win));
	else if (move == 4)
		return (ft_left_move(tmp, win));
	else if (move == 2)
		return (ft_change_op(tmp, 1, 1));
	else if (move == 1)
		return (ft_change_op(tmp, -1, 1));
	return (-1);
}
