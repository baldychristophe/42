/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist_list_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:41:27 by cbaldy            #+#    #+#             */
/*   Updated: 2016/03/02 16:33:11 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		*hist_list_new(t_hist_list **hist)
{
	t_hist_list	*new;

	if ((new = (t_hist_list *)malloc(sizeof(t_hist_list))) == NULL)
		return (NULL);
	new->old = NULL;
	new->next = NULL;
	new->previous = NULL;
	if ((*hist) != NULL)
	{
		new->next = *hist;
		(*hist)->previous = new;
	}
	*hist = new;
	return (0);
}

int		hist_change(int move, t_hist_list **hist, t_com_list **begin)
{
	char	*str;

	if (move == 1 && (*hist)->next != NULL)
		*hist = (*hist)->next;
	else if (move == 2 && (*hist)->previous != NULL)
		*hist = (*hist)->previous;
	else
		return (0);
	ft_tputs("cr", 1, 0);
	ft_tputs("RI", 1, g_local->prompt);
	ft_tputs("cd", 1, 0);
	com_list_free(*begin);
	*begin = com_list_dup((*hist)->old);
	str = com_list_retrieve(*begin);
	ft_printf("%s", str);
	free(str);
	g_local->curs = g_local->prompt + 1 + (int)ft_strlen(str);
	return (0);
}

int		hist_control_size(t_hist_list **hist)
{
	int			i;
	t_hist_list *tmp[2];

	i = 0;
	tmp[0] = *hist;
	while (tmp[0] != NULL)
	{
		i++;
		tmp[1] = tmp[0];
		tmp[0] = tmp[0]->next;
	}
	if (i > 20)
	{
		tmp[0] = tmp[1]->previous;
		tmp[0]->next = NULL;
		com_list_free(tmp[1]->old);
		free(tmp[1]);
	}
	return (0);
}

int		hist_add_elem(t_com_list *begin, t_hist_list **hist)
{
	while ((*hist)->previous != NULL)
		*hist = (*hist)->previous;
	if (begin != NULL)
	{
		if (begin->c != 0)
			(*hist)->old = begin;
		else
			free(begin);
	}
	else if ((*hist)->next != 0)
	{
		*hist = (*hist)->next;
		free((*hist)->previous);
	}
	else
	{
		free(*hist);
		*hist = NULL;
	}
	hist_control_size(hist);
	return (0);
}
