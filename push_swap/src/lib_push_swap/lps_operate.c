/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_operate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:27:17 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/08 17:20:14 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static int	lps_swap(t_jeton **begin, t_jeton **end)
{
	t_jeton	*buf[3];

	if ((buf[0] = *begin) == NULL || buf[0]->next == NULL)
		return (0);
	buf[1] = buf[0]->next;
	buf[2] = buf[1]->next;
	if (buf[2] != NULL)
		buf[2]->prev = buf[0];
	buf[0]->next = buf[2];
	buf[0]->prev = buf[1];
	buf[1]->prev = NULL;
	buf[1]->next = buf[0];
	*begin = buf[1];
	if (*end == buf[1])
		*end = buf[0];
	return (0);
}

static int	lps_push(t_jeton **start, t_jeton **start_end, t_jeton **arrival,
		t_jeton **arrival_end)
{
	t_jeton	*buf[3];

	if ((buf[0] = *start) == NULL)
		return (0);
	buf[2] = *arrival;
	buf[1] = buf[0]->next;
	if (buf[1] != NULL)
		buf[1]->prev = NULL;
	else
		*start_end = NULL;
	*start = buf[1];
	buf[0]->next = buf[2];
	if (buf[2] != NULL)
		buf[2]->prev = buf[0];
	else
		*arrival_end = buf[0];
	*arrival = buf[0];
	return (0);
}

static int	lps_rotate(t_jeton **begin, t_jeton **end)
{
	t_jeton	*buf[3];

	if ((buf[0] = *begin) == NULL)
		return (0);
	buf[1] = buf[0]->next;
	buf[2] = *end;
	if (buf[1] != NULL)
	{
		*begin = buf[1];
		buf[1]->prev = NULL;
	}
	if (buf[2] != buf[0])
	{
		buf[2]->next = buf[0];
		buf[0]->prev = buf[2];
	}
	buf[0]->next = NULL;
	*end = buf[0];
	return (0);
}

static int	lps_reverse_rotate(t_jeton **begin, t_jeton **end)
{
	t_jeton	*buf[3];

	if ((buf[0] = *end) == NULL)
		return (0);
	buf[1] = buf[0]->prev;
	buf[2] = *begin;
	if (buf[1] != NULL)
	{
		*end = buf[1];
		buf[1]->next = NULL;
	}
	if (buf[2] != buf[0])
	{
		buf[2]->prev = buf[0];
		buf[0]->next = buf[2];
	}
	buf[0]->prev = NULL;
	*begin = buf[0];
	return (0);
}

int			lps_operate(int move, t_main *ma)
{
	if (move == SA)
		return (lps_swap(ma->a_begin, ma->a_end));
	if (move == SB)
		return (lps_swap(ma->b_begin, ma->b_end));
	if (move == PA)
		return (lps_push(ma->b_begin, ma->b_end, ma->a_begin, ma->a_end));
	if (move == PB)
		return (lps_push(ma->a_begin, ma->a_end, ma->b_begin, ma->b_end));
	if (move == RA)
		return (lps_rotate(ma->a_begin, ma->a_end));
	if (move == RB)
		return (lps_rotate(ma->b_begin, ma->b_end));
	if (move == RRA)
		return (lps_reverse_rotate(ma->a_begin, ma->a_end));
	if (move == RRB)
		return (lps_reverse_rotate(ma->b_begin, ma->b_end));
	return (lps_operate_special_move(move, ma));
}
