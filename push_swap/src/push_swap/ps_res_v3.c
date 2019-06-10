/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_res_v3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:15:53 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/13 19:09:01 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sol	*ps_loop(t_main *main, t_sol *sol)
{
	//lps_sol_list_print(sol);
	//ft_putstr("\n");
	//lps_main_print_state(main);

	return (ps_next_move(main, sol));
}

t_sol			*ps_res_v3(t_main *main)
{
	t_sol	*sol;
	
	sol = NULL;
	while (lps_main_is_sorted(main) != 0)
		sol = ps_loop(main, sol);
	while (sol != NULL && sol->prev != NULL)
		sol = sol->prev;
	return (sol);
}
