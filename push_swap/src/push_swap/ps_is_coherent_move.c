/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_is_coherent_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:01:48 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/07 17:12:24 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_get_previous_move(t_sol *sol, int move)
{
	while (sol->prev != NULL && sol->move % 2 != move % 2)
		sol = sol->prev;
	return (sol->move);
}

int		ps_is_coherent_move(t_main *main, t_sol *sol, int move)
{
	int		pm;

	if ((move == PB && *(main->a_begin) == NULL)||(move == PA && *(main->b_begin) == NULL))
		return (1);
	else if ((move == SB || move == RB || move == RRB) &&
			*(main->b_begin) == *(main->b_end))
		return (1);
	else if ((move == SA || move == RA || move == RRA) &&
			*(main->a_begin) == *(main->a_end))
		return (1);
	else if (sol == NULL)
		return (0);
	else if ((move == PA && sol->move == PB) || (move == PB && sol->move == PA))
		return (1);
	pm = ps_get_previous_move(sol, move);
	if ((move == RA && pm == RRA) || (move == RRA && pm == RA) ||
			(move == SA && pm == SA) || (move == SB && pm == SB) ||
			(move == RB && pm == RRB) || (move == RRB && pm == RB))
		return (1);
	return (0);
}
