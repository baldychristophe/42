/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:59:09 by dbaldy            #+#    #+#             */
/*   Updated: 2015/12/03 14:50:21 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	connection(int **piece, int line, int col)
{
	int		count;

	count = 0;
	if (line > 0)
		if (piece[line - 1][col] > 0)
			count++;
	if (line < 3)
		if (piece[line + 1][col] > 0)
			count++;
	if (col > 0)
		if (piece[line][col - 1] > 0)
			count++;
	if (col < 3)
		if (piece[line][col + 1] > 0)
			count++;
	return (count);
}
static int	tetri(int **piece)
{
	int		i[2];
	int		connect;

	connect = 0;
	i[0] = 0;
	while (i[0] < 4)
	{
		i[1] = 0;
		while (i[1] < 4)
		{
			if (piece[i[0]][i[1]] > 0)
			{
				if (connection(piece, i[0], i[1]) >= 2)
					connect++;
				else if (connection(piece, i[0], i[1]) == 0)
					return (0);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (connect);
}

static int	nb_char(int	**piece)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] > 0)
				k++;
			j++;
		}
		i++;
	}
	if (k != 4)
		return (0);
	return (1);
}

int			ft_valid(int ***tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (tetri(tab[i]) == 0) //ici 0 = tetriminos non valid
			return (1);			// dans le main 1 = non valid
		if (nb_char(tab[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}	
