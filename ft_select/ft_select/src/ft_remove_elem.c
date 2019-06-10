/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 18:20:05 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/23 16:51:45 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_remove_elem(t_arg_list *tmp, t_arg_list **begin)
{
	t_arg_list	*prec;
	t_arg_list	*suiv;
	int			i;

	prec = tmp->previous;
	suiv = tmp->next;
	prec->next = suiv;
	suiv->previous = prec;
	suiv->op += 1;
	i = 0;
	if (suiv->nb == tmp->nb)
		i = -2;
	if (tmp->nb == 0)
		*begin = suiv;
	free(tmp->name);
	free(tmp);
	while (suiv->nb != 0)
	{
		suiv->nb -= 1;
		suiv = suiv->next;
	}
	return (i);
}
