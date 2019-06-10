/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:52:16 by cbaldy            #+#    #+#             */
/*   Updated: 2015/12/02 11:43:41 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1 , &c, 1);
}

void	ft_putstr(char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		write(2, &(src[i]), 1);
		i++;
	}
}

int		ft_strlen(char *src)
{
	int		i;

	i = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
		i++;
	return (0);
}
