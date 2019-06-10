/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:35:42 by cbaldy            #+#    #+#             */
/*   Updated: 2016/11/27 19:39:12 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ps_loop_a(t_main *main)
{
	t_jeton	*start;
	t_jeton	*last;

	start = *(main->a_begin);
	last = *(main->a_end);
	if (start->next != NULL && last->prev != NULL)
	{
		if (start->pos > start->next->pos && (start->next->pos != 0 ||
					start->pos != (main->nb / 2) - 1))
				return (SA);
		if (start->next->next != NULL && start->next->pos >
				start->next->next->pos)
			return (RA);
		if (start->pos < last->pos && (start->pos != 0 ||
					last->pos != (main->nb / 2) -1))
			return (RRA);
		if (lps_jeton_list_is_sorted(*(main->a_begin), 0) == 1)
			return (RA);
	}
	return (SORTED);
}

static int		ps_loop_b(t_main *main)
{
	t_jeton	*start;
	t_jeton	*last;

	start = *(main->b_begin);
	last = *(main->b_end);
	if (start->next != NULL && last->prev != NULL)
	{
		if (start->pos < start->next->pos && (start->pos != (main->nb / 2)
					|| start->next->pos != main->nb - 1))
				return (SB);
		if (start->next->next != NULL && start->next->pos <
				start->next->next->pos)
			return (RB);
		if (start->pos > last->pos && (last->pos != (main->nb / 2) ||
					start->pos != main->nb - 1))
			return (RRB);
		if (lps_jeton_list_is_sorted(*(main->b_begin), 1) == 1)
			return (RB);
	}
	return (SORTED);
}

t_sol			*ps_bubble_sort(t_main *main, t_sol *sol)
{
	int		i[3];

	i[0] = SA;
	i[1] = SB;
	if (*(main->b_begin) == NULL)
		i[1] = SORTED;
	while (i[0] != SORTED || i[1] != SORTED)
	{
		if (i[0] != SORTED)
			i[0] = ps_loop_a(main);
		if (i[1] != SORTED)
			i[1] = ps_loop_b(main);
		i[2] = 0;
		while (i[2] < 2)
		{
			if (i[i[2]] != SORTED)
			{
				if ((sol = lps_move(i[i[2]], main, sol)) == NULL)
					return (NULL);
			}
			i[2]++;
		}
	}
	return (sol);
}
