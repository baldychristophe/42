/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_brutforce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:28:30 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/07 18:46:26 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_sol	**ps_bf_create_sol(int	len)
{
	t_sol	**sol;
	t_sol	*tmp;
	int		i;

	if ((sol = (t_sol **)malloc(sizeof(t_sol *))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if ((tmp = lps_sol_new_elem(-1)) == NULL)
			return (NULL);
		if (i == 0)
			*sol = tmp;
		else
		{
			(*sol)->next = tmp;
			tmp->prev = *sol;
			*sol = tmp;
		}
		i++;
	}
	while ((*sol)->prev != NULL)
		*sol = (*sol)->prev;
	return (sol);
}

static void		ps_bf_move(int move, t_main *main, t_sol **sol)
{
	lps_operate(move, main);
	(*sol)->next->move = move;
	*sol = (*sol)->next;
	return;
}

static void 	ps_bf_revert(t_main *main, t_sol **sol)
{
	lps_operate(lps_opposite_move((*sol)->move), main);
	(*sol)->move = -1;
	*sol = (*sol)->prev;
	return;
}

static int		ps_explore_depth(t_main *main, t_sol **sol, int depth, int depth_max)
{
	int		move;

	move = 0;
	while (move < 8)
	{
		if (ps_is_coherent_move(main, *sol, move) == 0)
		{
			ps_bf_move(move, main, sol);
			if (lps_main_is_sorted(main) == 0)
				return (0);
			if (depth < depth_max && ps_explore_depth(main, sol, depth + 1, depth_max) == 0)
					return (0);
			ps_bf_revert(main, sol);
		}
		move++;
	}
	return (1);
}

t_sol			*ps_brutforce(t_main *main)
{
	int		depth_max;
	t_sol	**sol;
	t_sol	*res;

	depth_max = 1;
	if ((sol = ps_bf_create_sol(MAX_BF + 2)) == NULL)
		return (NULL);
	while (depth_max < MAX_BF)
	{
		if (ps_explore_depth(main, sol, 1, depth_max) == 0)
			break;
		depth_max++;
	}
	res = *sol;
	free(sol);
	return (res);
}
