/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:16:33 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/13 19:52:53 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sol	*ps_clean_ret_bf(t_sol *sol)
{
	t_sol	*tmp[3];

	while (sol->prev != NULL)
		sol = sol->prev;
	while (sol != NULL && sol->move == -1)
	{
		tmp[1] = sol->next;
		if (tmp[1] != NULL)
			tmp[1]->prev = NULL;
		free(sol);
		sol = tmp[1];
	}
	tmp[0] = sol;
	while (tmp[0] != NULL && tmp[0]->next != NULL && tmp[0]->next->move != -1)
		tmp[0] = tmp[0]->next;
	while (tmp[0] != NULL && tmp[0]->next != NULL)
	{
		tmp[1] = tmp[0]->next;
		tmp[2] = tmp[1]->next;
		free(tmp[1]);
		tmp[0]->next = tmp[2];
	}
	return (sol);
}

t_sol			*ps_solve(t_main *main)
{
	t_sol	*sol;

	if (lps_main_is_sorted(main) == 0)
		return (NULL);
	if ((sol = ps_clean_ret_bf(ps_brutforce(main))) != NULL)
		return (sol);
	return (ps_v4(main));
	return (ps_res_v3(main));
	return (ps_old_solve(main));
}
