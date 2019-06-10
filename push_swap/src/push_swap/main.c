/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:14:20 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/14 11:57:42 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_main	*main;
	t_sol	*sol;

	if ((main = lps_get_main(argc, argv)) == NULL)
	{
		if (argc > 1)
			ft_putstr("Error\n");
		return (1);
	}
	if ((sol = ps_solve(main)) == NULL)
		return (1);
	lps_sol_list_print(sol);
	lps_sol_list_free(sol);
	//lps_main_print_state(main);
	lps_main_free(main);
	return (0);
}
