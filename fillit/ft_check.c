/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:07:21 by dbaldy            #+#    #+#             */
/*   Updated: 2015/12/03 14:43:16 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '.') && (str[i] != '#') && (str[i] != '\n'))
			return (1);
		i++;
	}
	return (0);
}

static int		ft_check_line(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != '\n')
		{
			j++;
			i++;
		}
		if (j != 4)
			return (1);
		if (str[i] == '\n' && str[i + 1] == '\n')
			i += 2;
		else
			i++;
	}
	return (0);
}

static int		ft_size_sqr(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i + 1])
	{
		if (str[i] == '\n')
			j++;
		if (str[i] == '\n' && str[i + 1] == '\n' && j == 4)
		{
			j = 0;
			i++;
		}
		if ((str[i] == '\n' && str[i + 1] == '\n' && j != 4) || (j > 4))
			return (1);
		i++;
	}
	if (str[i] != '\n')
		return (1);
	return (0);
}			

int				ft_check(char *str)
{
	if ((ft_check_line(str) == 1) || (ft_check_char(str) == 1) || (ft_size_sqr(str) == 1))
		return (1);
	return (0);
}
