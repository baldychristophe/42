/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:58:14 by dbaldy            #+#    #+#             */
/*   Updated: 2015/12/03 10:26:58 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_sol(int **solution)
{
	int	line;
	int col;

	line = 0;
	while (solution[line][0] != -1)
	{
		col = 0;
		while (solution[line][col] != -1)
		{
			if (solution[line][col] == 0)
				ft_putchar('.');
			else
				ft_putchar(solution[line][col] + 'A' - 1);
			col++;
		}
		ft_putchar('\n');
		line++;
	}
}
