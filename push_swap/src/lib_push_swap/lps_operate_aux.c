/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_operate_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:12:24 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/12 19:16:54 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

int		lps_operate_special_move(int move, t_main *main)
{
	if (move == RR)
	{
		lps_operate(RA, main);
		lps_operate(RB, main);
	}
	else if (move == RRR)
	{
		lps_operate(RRA, main);
		lps_operate(RRB, main);
	}
	else if (move == SS)
	{
		lps_operate(SA, main);
		lps_operate(SB, main);
	}
	return (0);
}

t_sol	*lps_move(int move, t_main *main, t_sol *sol)
{
	lps_operate(move, main);
	if ((sol = lps_sol_list_insert(move, sol)) == NULL)
		return (NULL);
	return (sol);
}
