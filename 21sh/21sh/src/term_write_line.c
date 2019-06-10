/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_write_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 12:47:39 by cbaldy            #+#    #+#             */
/*   Updated: 2016/03/03 11:38:08 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ed_insert_char(t_com_list **begin, char buf, t_com_list *new)
{
	t_com_list	*tmp[2];
	int			i;

	i = 0;
	tmp[0] = *begin;
	while (tmp[0]->next != NULL && i < g_local->curs - g_local->prompt - 2)
	{
		tmp[0] = tmp[0]->next;
		i++;
	}
	tmp[1] = tmp[0]->next;
	tmp[0]->next = new;
	new->previous = tmp[0];
	if (tmp[1] != NULL)
	{
		tmp[1]->previous = new;
		new->next = tmp[1];
	}
	return (buf);
}

static int	ed_add_char(t_com_list **begin, char buf)
{
	t_com_list	*new;
	int		i;

	i = 0;
	if ((new = com_list_new(buf)) == NULL)
		return (-1);
	if (*begin == NULL)
		*begin = new;
	else if (g_local->curs - g_local->prompt == 1)
	{
		new->next = *begin;
		(*begin)->previous = new;
		*begin = new;
	}
	else
		ed_insert_char(begin, buf, new);
	print_command(begin, buf);
	return (buf);
}

static int	ft_remove_com_list(t_com_list *del, t_com_list **begin)
{
	t_com_list	*tmp[2];

	tmp[0] = del->previous;
	tmp[1] = del->next;
	free(del);
	del = NULL;
	if (tmp[0] != NULL)
		tmp[0]->next = tmp[1];
	else
		*begin = tmp[1];
	if (tmp[1] != NULL)
		tmp[1]->previous = tmp[0];
	return (0);
}

static int	ed_delete_char(t_com_list **begin)
{
	t_com_list *tmp;
	int		i;

	i = 0;
	tmp = *begin;
	if (g_local->curs == g_local->prompt + 1)
		return (0);
	while (tmp->next != NULL && i < g_local->curs - g_local->prompt - 2)
	{
		tmp = tmp->next;
		i++;
	}
	ft_remove_com_list(tmp, begin);
	ft_tputs("le", 1, 0);
	ft_tputs("dc", 1, 0);
	g_local->curs -= 1;
	tmp = *begin;
	return (0);
}

int		term_write_line(t_com_list **begin, char buf)
{

	if (buf == 127)
		ed_delete_char(begin);
	else if (buf == 10)
		ft_dprintf(STDOUT_FILENO, "%c", buf);
	else
		ed_add_char(begin, buf);
	return (buf);
}
