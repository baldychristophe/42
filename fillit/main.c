/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:22:15 by cbaldy            #+#    #+#             */
/*   Updated: 2015/12/03 12:36:23 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		preliminaire(char **input)
{
	char	*stock_m;
	
	stock_m = stock(input);
	if (ft_check(stock_m) == 1)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		***echiquier;
	int		size;
	int		**solution;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (preliminaire(argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	size = taille(stock(argv));
	echiquier = lecture(stock(argv));
	if (ft_valid(echiquier) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if ((solution = resol(echiquier, size)) == NULL)
			ft_putstr("no solution\n");
	ft_print_sol(solution);
	return (0);
}
