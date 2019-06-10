/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 17:59:12 by cbaldy            #+#    #+#             */
/*   Updated: 2016/11/27 18:03:28 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ps_sol_recompile_aux(int move, t_sol *last)
{
	t_sol	*tmp[2];

	tmp[0] = last->prev;
	tmp[1] = tmp[0]->prev;
	free(tmp[0]);
	last->move = move;
	last->prev = tmp[1];
	if (tmp[1] != NULL)
		tmp[1]->next = last;
}

static t_sol	*ps_sol_recompile(t_sol *last)
{
	int		m[2];
	int		i;

	i = 0;
	while (last->prev != NULL)
	{
		m[0] = last->prev->move;
		m[1] = last->move;
		
		if ((m[0] == SA && m[1] == SB) || (m[0] == SB && m[1] == SA))
			ps_sol_recompile_aux(SS, last);
		else if ((m[0] == RA && m[1] == RB) || (m[0] == RB && m[1] == RA))
			ps_sol_recompile_aux(RR, last);
		else if ((m[0] == RRA && m[1] == RRB) || (m[0] == RRB && m[1] == RRA))
			ps_sol_recompile_aux(RRR, last);
		else
			last = last->prev;
		i++;
	}
	return (last);
}

static t_sol	*ps_complete_sort(t_main *main, t_sol *sol)
{
	int		i;

	i = 0;
	while (*(main->b_begin) != NULL)
	{
		i++;
		lps_operate(PA, main);
		if ((sol = lps_sol_list_insert(PA, sol)) == NULL)
			return (NULL);
	}
	while (i > 0)
	{
		i--;
		lps_operate(RA, main);
		if ((sol = lps_sol_list_insert(RRA, sol)) == NULL)
			return (NULL);
	}
	return (sol);
}

t_sol			*ps_old_solve(t_main *main)
{
	t_sol	*sol;

	sol = NULL;
	if (main->nb > 0)
	{
		if ((sol = ps_quick_split(main, sol)) == NULL)
			return (NULL);
	}
	if ((sol = ps_bubble_sort(main, sol)) == NULL)
		return (NULL);
	sol = ps_complete_sort(main, sol);
	if ((sol = ps_sol_recompile(sol)) == NULL)
		return (NULL);
	return (sol);
}
