/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_quick_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:09:53 by cbaldy            #+#    #+#             */
/*   Updated: 2016/11/27 17:36:03 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ps_quick_split_move(t_main *main, int pivot)
{
	t_jeton	*tmp;

	tmp = *(main->a_begin);
	if (tmp->pos >= pivot)
		return (PB);
	else
		return (RA);
}

t_sol			*ps_quick_split(t_main *main, t_sol *sol)
{
	int		index;
	int		move;
	int		pivot;

	index = 0;
	pivot = main->nb / 2;
	while (index < main->nb)
	{
		move = ps_quick_split_move(main, pivot);
		if ((sol = lps_move(move, main, sol)) == NULL)
			return (NULL);
		index++;
	}
	return (sol);
}
