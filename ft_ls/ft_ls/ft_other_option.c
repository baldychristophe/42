/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:44:40 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 12:34:50 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fi_list	**ft_sort_list_size(t_fi_list **begin)
{
	t_fi_list	*tmp;
	int			i;

	i = 1;
	while (i != 0)
	{
		i = 0;
		tmp = *begin;
		while (tmp->next != NULL && tmp != NULL)
		{
			if (tmp->taille < tmp->next->taille)
			{
				i = 1;
				ft_swap_list(begin, tmp, tmp->next);
			}
			else
				tmp = tmp->next;
		}
	}
	return (begin);
}
