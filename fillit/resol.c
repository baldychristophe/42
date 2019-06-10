/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resol.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 12:10:15 by cbaldy            #+#    #+#             */
/*   Updated: 2015/12/03 15:06:21 by dbaldy           ###   ########.fr       */
/*   Updated: 2015/12/03 13:51:50 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int		*coordonnees(int **piece)
{
	int		*i;
	int		x;
	int		y;
	int		j;
	
	if ((i = malloc(sizeof(int) * 8)) == NULL)
		return (NULL);
	x = 0;
	j = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (piece[x][y] > 0)
			{
				i[j] = x;
				i[j + 1] = y;
				j += 2;
			}
			y++;
		}
		x++;
	}
	return (i);
}

static void			placement(int **tab, int **resol, int line, int col)
{
	int		*x;
	int		j;

	j = 0;
	x = coordonnees(tab);
	while (j < 8)
	{
		resol[line + (x[j] - x[0])][col + (x[j + 1] - x[1])] = tab[x[j]][x[j + 1]];
		j += 2;
	}
}

static void			desempiler(int **resol, int piece_nb)
{
	int		i[2];

	i[0] = 0;
	while (resol[i[0]][0] != -1)
	{
		i[1] = 0;
		while (resol[0][i[1]] != -1)
		{
			if (resol[i[0]][i[1]] == piece_nb + 1)
				resol[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
	}
}

static int		check_placement(int **tab, int **resol, int line, int col)
{
	int		*x;
	int		j;

	x = coordonnees(tab);
	j = 0;
	while (j < 8)
	{
		if (resol[line + (x[j] - x[0])][col + (x[j + 1] - x[1])] != 0 ||
				col + (x[j + 1] - x[1]) < 0)
			return (0);
		j += 2;
	}
	return (1);
}

static int		recursive_placement(int ***tab, int **resol, int piece_nb)
{
	int		i[2];

	if (tab[piece_nb] == NULL)
		return (1);
	i[0] = 0;
	while (resol[i[0]][0] != -1)
	{
		i[1] = 0;
		while (resol[0][i[1]] != -1)
		{
			if (resol[i[0]][i[1]] == 0)
				if (check_placement(tab[piece_nb], resol, i[0], i[1]) == 1) //1 = ok
					{
						placement(tab[piece_nb], resol, i[0], i[1]);
						if (recursive_placement(tab, resol, piece_nb + 1) == 1)
							return (1);
						desempiler(resol, piece_nb);
					}
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}

int		**resol(int ***tab, int nb_tetri)
{
	int		**resol;
	int		size_resol;
	int		sol;

	size_resol = sqrt_fillit(nb_tetri * 4);
	sol = 0;
	while (sol == 0)
	{
		if ((resol = create_empty_sol(size_resol)) == NULL)
			return (NULL);
		sol = recursive_placement(tab, resol, 0);
		size_resol++;
	}
	return (resol);
}
