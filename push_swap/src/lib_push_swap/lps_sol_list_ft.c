/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_sol_list_ft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:07:14 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/13 20:18:46 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

t_sol	*lps_sol_new_elem(int move)
{
	t_sol	*new;

	if ((new = (t_sol *)malloc(sizeof(t_sol))) == NULL)
		return (NULL);
	new->move = move;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_sol	*lps_sol_list_insert(int move, t_sol *last)
{
	t_sol	*new;

	if ((new = lps_sol_new_elem(move)) == NULL)
		return (NULL);
	if (last != NULL)
		last->next = new;
	new->prev = last;
	return (new);
}

void	lps_sol_list_print(t_sol *begin)
{
	int		i;

	i = 0;
	while (begin != NULL)
	{
		i++;
		ft_putstr(lps_convert_move_to_string(begin->move));
		ft_putstr("\n");
		begin = begin->next;
	}
	//ft_putstr("\nNombre d'operations: ");
	//ft_putnbr(i);
	//ft_putstr("\n");
	return ;
}

void	lps_sol_list_free(t_sol *begin)
{
	t_sol	*tmp;

	while (begin != NULL)
	{
		tmp = begin->next;
		free(begin);
		begin = tmp;
	}
}
