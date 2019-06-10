/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 16:10:32 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 16:01:28 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_swap_list(t_fi_list **begin, t_fi_list *tmp,
		t_fi_list *tmp_bis)
{
	t_fi_list	*buf;
	t_fi_list	*qua;

	buf = tmp_bis->next;
	qua = tmp->previous;
	if (qua != NULL)
		qua->next = tmp_bis;
	if (tmp == *begin)
		*begin = tmp_bis;
	tmp_bis->next = tmp;
	tmp_bis->previous = tmp->previous;
	tmp->next = buf;
	tmp->previous = tmp_bis;
	if (buf != NULL)
		buf->previous = tmp;
}

static t_fi_list	**ft_tidy_list(t_fi_list **begin)
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
			if (ft_strcmp(tmp->name, tmp->next->name) > 0)
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

static t_fi_list	**ft_sort_list_time(t_fi_list **begin)
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
			if (tmp->time_st < tmp->next->time_st)
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

static t_fi_list	**ft_reverse_list_order(t_fi_list **begin)
{
	t_fi_list	*tmp;
	t_fi_list	*buf;

	tmp = *begin;
	while (tmp->next != NULL)
	{
		buf = tmp->next;
		tmp->next = tmp->previous;
		tmp->previous = buf;
		tmp = tmp->previous;
	}
	tmp->next = tmp->previous;
	tmp->previous = NULL;
	*begin = tmp;
	return (begin);
}

t_fi_list			**ft_sort_list(t_fi_list **begin)
{
	if (*begin == NULL)
		return (NULL);
	if ((g_option & OPT_U) == 0)
		begin = ft_tidy_list(begin);
	if ((g_option & OPT_T) != 0)
		begin = ft_sort_list_time(begin);
	if ((g_option & OPT_S) != 0)
		begin = ft_sort_list_size(begin);
	if ((g_option & OPT_MINR) != 0)
		begin = ft_reverse_list_order(begin);
	return (begin);
}
