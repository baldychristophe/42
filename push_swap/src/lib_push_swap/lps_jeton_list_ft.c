/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_jeton_list_ft.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:34:12 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/08 17:14:46 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_jeton	*lps_jeton_new_elem(const char *str, const int pos)
{
	t_jeton	*new;

	if ((new = (t_jeton *)malloc(sizeof(t_jeton))) == NULL)
		return (NULL);
	new->id = ft_atoi(str);
	new->pos = pos;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int		lps_jeton_list_free(t_jeton *begin)
{
	t_jeton	*buf;

	while (begin != NULL)
	{
		buf = begin->next;
		free(begin);
		begin = buf;
	}
	return (0);
}

int		lps_jeton_list_print(t_jeton *begin)
{
	if (begin == NULL)
		ft_putstr("Empty\n");
	while (begin != NULL)
	{
		ft_putnbr(begin->id);
		ft_putstr(" -> ");
		ft_putnbr(begin->pos);
		ft_putstr("\n");
		begin = begin->next;
	}
	return (0);
}

int		lps_jeton_list_is_sorted(t_jeton *begin, int pile)
{
	if (pile == 0)
	{
		while (begin != NULL && begin->next != NULL)
		{
			if (begin->pos > begin->next->pos)
				return (1);
			begin = begin->next;
		}
		return (0);
	}
	while (begin != NULL && begin->next != NULL)
	{
		if (begin->pos < begin->next->pos)
			return (1);
		begin = begin->next;
	}
	return (0);
}
