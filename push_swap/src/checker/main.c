/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 20:23:57 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/14 11:57:39 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ch_apply_sol(t_main *main, t_sol *sol)
{
	while (sol != NULL)
	{
		lps_operate(sol->move, main);
		sol = sol->next;
	}
	return (lps_main_is_sorted(main));
}

static void	ch_check_sol(t_main *main, t_sol *sol)
{
	if (ch_apply_sol(main, sol) == 0)
	{
		ft_putstr("OK\n");
		return ;
	}
	else
	{
		ft_putstr("KO\n");
		return ;
	}
}

int			main(int argc, char **argv)
{
	t_main	*main;
	t_sol	*sol;
	int		err;

	sol = NULL;
	if ((main = lps_get_main(argc, argv)) == NULL)
	{
		if (argc > 1)
			ft_putstr("Error\n");
		return (1);
	}
	if ((err = ch_read_sol(&sol)) == 1)
		ft_putstr("Error\n");
	else
		ch_check_sol(main, sol);
	lps_sol_list_free(sol);
	lps_main_free(main);
	return (err);
}
