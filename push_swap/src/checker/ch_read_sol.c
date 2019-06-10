/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_read_sol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:10:30 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/14 11:57:36 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ch_read_sol(t_sol **sol)
{
	char	*line;
	int		ret;
	int		move;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if ((move = lps_convert_string_to_int(line)) == -1)
			return (1);
		if ((*sol = lps_sol_list_insert(move, *sol)) == NULL)
			return (1);
	}
	while (*sol != NULL && (*sol)->prev != NULL)
		*sol = (*sol)->prev;
	return (0);
}
