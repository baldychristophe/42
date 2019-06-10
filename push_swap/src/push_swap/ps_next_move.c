/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_next_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:09:57 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/13 19:00:09 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_next_ra_pa(t_main *main)
{
	t_jeton	*tmp;
	int		i;
	int		pos_b;

	if (*(main->b_begin) == NULL)
		return (-1);
	pos_b = (*(main->b_begin))->pos;
	tmp = *(main->a_begin);
	i = 0;
	while (tmp != NULL && tmp->pos != pos_b + 1)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp != NULL)
		return (i);
	return (-1);
}

static int	ps_next_rb_pa(t_main *main)
{
	t_jeton	*tmp;
	int		i;
	int		pos_a;

	if (*(main->a_begin) == NULL)
		return (-1);
	pos_a = (*(main->a_begin))->pos;
	tmp = *(main->b_begin);
	i = 0;
	while (tmp != NULL && tmp->pos != pos_a - 1)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp != NULL)
		return (i);
	return (-1);
}

static int	ps_next_rrb_pa(t_main *main)
{
	t_jeton	*tmp;
	int		i;
	int		pos_a;

	if (*(main->a_begin) == NULL)
		return (-1);
	pos_a = (*(main->a_begin))->pos;
	tmp = *(main->b_end);
	i = 1;
	while (tmp != NULL && tmp->pos != pos_a - 1)
	{
		i++;
		tmp = tmp->prev;
	}
	if (tmp != NULL)
		return (i);
	return (-1);
}

static int	ps_next_pb(t_main *main)
{
	t_jeton	*tmp;

	tmp = *(main->a_begin);
	if (tmp->pos == main->nb -1)
		return (-1);
	return (0);
}

t_sol		*ps_next_move(t_main *main, t_sol *sol)
{
	int		next[4];

	next[0] = ps_next_ra_pa(main);
	next[1] = ps_next_rb_pa(main);
	next[2] = ps_next_pb(main);
	next[3] = ps_next_rrb_pa(main);

	t_jeton	*tmp;
	tmp = *(main->a_begin);
	if (tmp != NULL && tmp->next != NULL && (tmp->pos == tmp->next->pos - 1 ||
				tmp->pos == main->nb - 1))
	{
		if (next[1] == -1 && next[3] == -1)
			return (lps_move(RA, main, sol));
		if (next[1] <= next[3])
			return (ps_execute_next_move(main, sol, RB, next[1]));
		else if (next[1] > next[3])
			return (ps_execute_next_move(main, sol, RRB, next[1]));
	}

	if (next[2] != -1 && next[1] == -1 && next[2] < next[0])
		return (ps_execute_next_move(main, sol, PB, -1));
	if (next[0] == -1 && next[1] != -1)
		return (ps_execute_next_move(main, sol, RB, next[1]));
	else if (next[0] != -1 && next[1] == -1)
		return (ps_execute_next_move(main, sol, RA, next[0]));
	else if (next[0] == -1 && next[1] == -1 && next[2] != -1)
		return (ps_execute_next_move(main, sol, PB, -1));
	else if (next[0] == -1 && next[1] == -1 && next[2] == -1)
		return (ps_execute_next_move(main, sol, RA, 0));
	else if (next[0] <= next[1])
		return (ps_execute_next_move(main, sol, RA, next[0]));
	else if (next[1] < next[0])
		return (ps_execute_next_move(main, sol, RB, next[1]));
	return (ps_execute_next_move(main, sol, RA, 0));
}
