/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:19:54 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/08 16:39:46 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

char	*lps_convert_move_to_string(int move)
{
	if (move == SA)
		return ("sa");
	else if (move == SB)
		return ("sb");
	else if (move == SS)
		return ("ss");
	else if (move == RA)
		return ("ra");
	else if (move == RB)
		return ("rb");
	else if (move == RR)
		return ("rr");
	else if (move == PA)
		return ("pa");
	else if (move == PB)
		return ("pb");
	else if (move == RRA)
		return ("rra");
	else if (move == RRB)
		return ("rrb");
	else
		return ("rrr");
}

int		lps_opposite_move(int move)
{
	if (move == SA)
		return (SA);
	if (move == SB)
		return (SB);
	if (move == RA)
		return (RRA);
	if (move == RB)
		return (RRB);
	if (move == RRA)
		return (RA);
	if (move == RRB)
		return (RB);
	if (move == SS)
		return (SS);
	if (move == RR)
		return (RRR);
	if (move == RRR)
		return (RR);
	if (move == PA)
		return (PB);
	if (move == PB)
		return (PA);
	return (-1);
}

int		lps_convert_string_to_int(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (SA);
	if (ft_strcmp(str, "sb") == 0)
		return (SB);
	if (ft_strcmp(str, "ra") == 0)
		return (RA);
	if (ft_strcmp(str, "rb") == 0)
		return (RB);
	if (ft_strcmp(str, "pa") == 0)
		return (PA);
	if (ft_strcmp(str, "pb") == 0)
		return (PB);
	if (ft_strcmp(str, "rra") == 0)
		return (RRA);
	if (ft_strcmp(str, "rrb") == 0)
		return (RRB);
	if (ft_strcmp(str, "ss") == 0)
		return (SS);
	if (ft_strcmp(str, "rr") == 0)
		return (RR);
	if (ft_strcmp(str, "rrr") == 0)
		return (RRR);
	return (-1);
}
