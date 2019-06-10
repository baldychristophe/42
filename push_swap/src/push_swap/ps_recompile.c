/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_recompile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:59:32 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/14 13:05:33 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_pop_type_1(t_sol *first, t_sol *sec)
{
	t_sol	*tmp[2];

	tmp[0] = first->prev;
	tmp[1] = sec->next;
	free(first);
	free(sec);
	if (tmp[0] != NULL)
		tmp[0]->next = tmp[1];
	if (tmp[1] != NULL)
		tmp[1]->prev = tmp[0];
	return ;
}

static void	ps_pop_type_2(t_sol *one, t_sol *two, t_sol *three, t_sol *four)
{
	t_sol	*tmp;

	tmp = one->prev;
	free(one);
	free(two);
	free(three);
	four->prev = tmp;
	tmp->next = four;
	four->move = SA;
	return ;
}

static void	ps_sol_pop(t_sol *first, int type)
{
	t_sol	*tmp[4];

	tmp[0] = first->next;
	tmp[1] = tmp[0]->next;
	if (type == 1)
	{
		ps_pop_type_1(tmp[0], tmp[1]);
		return ;
	}
	tmp[2] = tmp[1]->next;
	tmp[3] = tmp[2]->next;
	ps_pop_type_2(tmp[0], tmp[1], tmp[2], tmp[3]);
	return ;
	
}

static int	ps_is_recompilable(t_sol *first)
{
	t_sol	*tmp[4];

	if (first->next == NULL || first->next->next == NULL)
		return (0);
	tmp[0] = first->next;
	tmp[1] = tmp[0]->next;
	if ((tmp[0]->move == PB && tmp[1]->move == PA) ||
			(tmp[0]->move == PA && tmp[1]->move == PB) ||
			(tmp[0]->move == RA && tmp[1]->move == RRA) ||
			(tmp[0]->move == RRA && tmp[1]->move == RA))
		return (1);
	if (tmp[1]->next == NULL || tmp[1]->next->next == NULL)
		return (0);
	tmp[2] = tmp[1]->next;
	tmp[3] = tmp[2]->next;
	if (tmp[0]->move == PB && tmp[1]->move == RA && tmp[2]->move == PA &&
			tmp[3]->move == RRA)
		return (2);
	return (0);
}

t_sol		*ps_recompile(t_sol *sol)
{
	t_sol	*tmp;
	int		type;

	if (sol == NULL || sol->next == NULL)
		return (sol);
	tmp = sol;
	while (tmp != NULL && tmp->next != NULL)
	{
		if ((type = ps_is_recompilable(tmp)) != 0)
		{
			ps_sol_pop(tmp, type);
			if (tmp->prev != NULL)
				tmp = tmp->prev;
		}
		else
			tmp = tmp->next;
	}
	return (sol);
}
