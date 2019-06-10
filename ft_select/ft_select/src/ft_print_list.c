/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:34:39 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/23 18:53:03 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_put_elem(t_arg_list *tmp, int fd)
{
	if (tmp->op == 1 || tmp->op == 3)
		ft_tputs("us", 1, 0, fd);
	if (tmp->op == 2 || tmp->op == 3)
		ft_tputs("mr", 1, 0, fd);
	ft_dprintf(fd, "%s", tmp->name);
	if (tmp->op == 2 || tmp->op == 3)
		ft_tputs("me", 1, 0, fd);
	if (tmp->op == 1 || tmp->op == 3)
		ft_tputs("ue", 1, 0, fd);
	return (0);
}

static int	ft_position_cursor(int *win, int i, int fd)
{
	ft_tputs("cr", 1, 0, fd);
	if (i % win[4] != 0)
		ft_tputs("DO", 1, i % win[4], fd);
	if (i / win[4] != 0)
		ft_tputs("RI", 1, (i / win[4]) * (win[0] + (8 - (win[0] % 8))), fd);
	return (0);
}

static int	ft_reset_cursor(int *win, int i, int fd)
{
	ft_tputs("cr", 1, 0, fd);
	if (i % win[4] != 0)
		ft_tputs("UP", 1, i % win[4], fd);
	return (0);
}

static int	ft_initialize_print(int *win, int fd)
{
	int			j;
	static int	k;

	ft_tputs("cd", 1, 0, fd);
	if (win[2] < win[0] || win[5] < win[4])
	{
		ft_tputs("cl", 1, 0, fd);
		k = 1;
		return (-1);
	}
	j = 0;
	while (j < win[4] - 1)
	{
		ft_tputs("sf", 1, 0, fd);
		j++;
	}
	if (k == 1)
		ft_tputs("cl", 1, 0, fd);
	ft_reset_cursor(win, win[4] - 1, fd);
	return (0);
}

int			ft_print_list(t_arg_list *begin, int fd)
{
	t_arg_list	*tmp;
	int			*win;

	if ((win = ft_prepare_print(begin, fd)) == NULL)
		return (-1);
	if (ft_initialize_print(win, fd) < 0)
		return (0);
	tmp = begin;
	while (tmp->nb < tmp->next->nb)
	{
		ft_position_cursor(win, tmp->nb, fd);
		ft_put_elem(tmp, fd);
		ft_reset_cursor(win, tmp->nb, fd);
		tmp = tmp->next;
	}
	ft_position_cursor(win, tmp->nb, fd);
	ft_put_elem(tmp, fd);
	ft_reset_cursor(win, tmp->nb, fd);
	free(win);
	return (0);
}
