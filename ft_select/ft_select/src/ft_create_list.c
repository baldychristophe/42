/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:27:13 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/23 17:15:29 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static t_arg_list	*list_new_elem(char *str, int i)
{
	t_arg_list	*new;

	if ((new = (t_arg_list *)malloc(sizeof(t_arg_list))) == NULL)
		return (NULL);
	new->name = ft_strdup(str);
	new->next = NULL;
	new->previous = NULL;
	new->op = 0;
	new->nb = i;
	return (new);
}

t_arg_list			*ft_create_list(int ac, char **av)
{
	t_arg_list	*first;
	t_arg_list	*second;
	int			i;

	first = list_new_elem(av[1], 0);
	i = 2;
	while (i < ac)
	{
		second = list_new_elem(av[i], i - 1);
		second->previous = first;
		first->next = second;
		first = first->next;
		i++;
	}
	while (first->previous != NULL)
		first = first->previous;
	first->op = 1;
	second->next = first;
	first->previous = second;
	return (first);
}
