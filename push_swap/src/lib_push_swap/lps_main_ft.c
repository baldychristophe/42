/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_main_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 13:22:46 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/08 17:15:10 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

void	lps_main_print_state(t_main *main)
{
	ft_putstr("Pile A:\n");
	lps_jeton_list_print(*(main->a_begin));
	ft_putstr("//\n");
	ft_putstr("Pile B:\n");
	lps_jeton_list_print(*(main->b_begin));
	ft_putstr("/*** END ***/\n");
	return ;
}

int		lps_main_free(t_main *main)
{
	lps_jeton_list_free(*(main->a_begin));
	lps_jeton_list_free(*(main->b_begin));
	free(main->a_begin);
	free(main->b_begin);
	free(main->a_end);
	free(main->b_end);
	free(main);
	return (0);
}

int		lps_main_is_sorted(t_main *main)
{
	if (*(main->b_begin) != NULL)
		return (1);
	return (lps_jeton_list_is_sorted(*(main->a_begin), 0));
}
