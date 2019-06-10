/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_v4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:09:08 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/14 13:05:31 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ps_get_pivot(t_main *main, int len)
{
	int		sum;
	int		i;
	t_jeton	*tmp;

	sum = 0;
	i = 0;
	tmp = *(main->a_begin);
	while (tmp != NULL && i < len)
	{
		sum += tmp->pos;
		tmp = tmp->next;
		i++;
	}
	return (sum / len);
}

static t_sol	*ps_advance(t_main *main, t_sol *sol, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		sol = lps_move(RRA, main, sol);
		i++;
	}
	return (sol);
}

static t_sol	*ps_split_pivot(t_main *main, t_sol *sol, int pivot, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if ((*(main->a_begin))->pos > pivot)
			sol = lps_move(PB, main, sol);
		else
			sol = lps_move(RA, main, sol);
		i++;
	}
	while (*(main->b_begin) != NULL)
		sol = lps_move(PA, main, sol);
	return (sol);
}

static t_sol	*ps_rec_qcksrt(t_main *main, t_sol *sol, int len)
{
	int		pivot;

	if (len < 2)
		return (sol);
	pivot = ps_get_pivot(main, len);
	sol = ps_split_pivot(main, sol, pivot, len);
	sol = ps_rec_qcksrt(main, sol, len / 2);
	sol = ps_advance(main, sol, len / 2 + len % 2);
	sol = ps_rec_qcksrt(main, sol, len / 2 + len % 2);
	return (sol);	
}

t_sol	*ps_v4(t_main *main)
{
	t_sol	*sol;

	sol = NULL;
	sol = ps_rec_qcksrt(main, sol, main->nb);
	while (sol != NULL && sol->prev != NULL)
		sol = sol->prev;
	return (ps_recompile(sol));
}
