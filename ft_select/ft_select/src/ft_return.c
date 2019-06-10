/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:40:37 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/23 10:10:47 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_return(t_arg_list *begin)
{
	t_arg_list *tmp;

	if ((begin->op & 2) != 0)
		ft_printf("%s ", begin->name);
	tmp = begin->next;
	while (tmp->nb > 0)
	{
		if ((tmp->op & 2) != 0)
			ft_printf("%s ", tmp->name);
		tmp = tmp->next;
	}
	return (0);
}
