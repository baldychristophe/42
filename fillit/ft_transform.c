/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:24:32 by dbaldy            #+#    #+#             */
/*   Updated: 2015/12/02 12:22:21 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

unsigned int taille(char *str)
{
	int				i;
	unsigned int	k;

	i = 0;
	k = 1;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			k++;
		i++;
	}
	return (k);
}

static void			ft_fill(int	*line, char *str, int no)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (str[i] == '#')
			line[i] = no + 1;
		else
			line[i] = 0;
		i++;
	}
	line[i] = -1;
}

static int			**fill_piece(char *str, int no)
{
	int		**piece;
	int		i;
	int		j;

	i = 0;
	j = 0;
	piece = (int **)malloc(sizeof(int*) * 4);
	if (piece == NULL)
		return (NULL);
	while (j < 4)
	{
		piece[j] = (int *)malloc(sizeof(int) * 5);
		if (piece[j] == NULL)
			return (NULL);
		ft_fill(piece[j], &str[i], no);
		i += 5;
		j++;
	}
	return (piece);
}

int		***lecture(char *str)
{
	int		***echiquier;
	int		k;
	int		i;

	i = 0;
	k = taille(str);
	echiquier = (int ***)malloc(sizeof(int**) * (k + 1));
	if (echiquier == NULL)
		return (NULL);
	while (i < k)
	{
		echiquier[i] = fill_piece(str + 21 * i, i);
		i++;
	}	
	echiquier[i] = NULL;
	return (echiquier);
}
