/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_next_move_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:53:36 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/13 18:51:55 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sol	*ps_pa_or_pb(t_main *main, t_sol *sol)
{
	t_jeton	*tmp;

	tmp = *(main->a_begin);
	if (tmp != NULL && tmp->next != NULL && tmp->pos != tmp->next->pos -1 &&
			tmp->pos != main->nb -1)
		return (lps_move(PB, main, sol));
	return (lps_move(PA, main, sol));
}

t_sol	*ps_execute_next_move(t_main *main, t_sol *sol, int move, int nb)
{
	int		i;

	i = 0;
	if (move == PB)
		return (lps_move(PB, main, sol));
	while (i < nb)
	{
		sol = lps_move(move, main, sol);
		i++;
	}
	return (ps_pa_or_pb(main, sol));
}
