/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_device.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 14:07:27 by cbaldy            #+#    #+#             */
/*   Updated: 2015/12/21 11:46:39 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*ft_dev_space(t_fi_list **begin, int *tab)
{
	t_fi_list	*tmp;

	tmp = *begin;
	tab[0] = 0;
	tab[1] = 0;
	while (tmp != NULL)
	{
		if (tmp->device != 0)
		{
			if (ft_nb_chiffre(major(tmp->device)) > tab[0])
				tab[0] = ft_nb_chiffre(major(tmp->device));
			if (ft_nb_chiffre(minor(tmp->device)) > tab[1])
				tab[1] = ft_nb_chiffre(minor(tmp->device));
		}
		tmp = tmp->next;
	}
	return (tab);
}
