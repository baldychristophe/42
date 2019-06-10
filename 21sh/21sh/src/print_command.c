/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 17:00:28 by cbaldy            #+#    #+#             */
/*   Updated: 2016/03/03 11:40:56 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*static int	print_handle_wrapping(t_com_list **begin, int nb)
{
	int		line;
	t_com_list	*tmp;

	ft_tputs("sc", 1, 0);
	line = g_local->curs / (g_local->nb_col + 1);
	
	int		j = 0;
	tmp = *begin;
	char	*buf[10];
	while (tmp != NULL)
	{
		if (j != 0 && j % (g_local->nb_col + 1 - g_local->prompt) == 0)
		{
			//ft_tputs("sf", 1, 1);
			ft_tputs("DO", 1, 1);
			ft_tputs("cr", 1, 0);
			ft_putchar_fd(tmp->c, STDIN_FILENO);
		}
		tmp = tmp->next;
		j++;
	}
	read(STDIN_FILENO, buf, 10);
	ft_tputs("UP", 1, ((nb + g_local->prompt) / (g_local->nb_col + 1)) - line);
	ft_tputs("rc", 1, 0);
	return (nb);
}*/

int		print_command(t_com_list **begin, char buf)
{
	ft_tputs("vi", 1, 0);
	ft_tputs("sc", 1, 0);
	ft_tputs("cr", 1, 0);
	ft_tputs("RI", 1, g_local->prompt);
	char	*str = com_list_retrieve(*begin);
	ft_putstr_fd(str, STDIN_FILENO);
	g_local->curs += 1;
	ft_tputs("rc", 1, 0);
	ft_tputs("nd", 1, 0);
	ft_tputs("ve", 1, 0);


	/*int		nb;

	nb = com_list_count(*begin);
	ft_putchar_fd(buf, STDIN_FILENO);
	g_local->curs += 1;
	if (g_local->curs / (g_local->nb_col + 1) < (nb + g_local->prompt) /
			(g_local->nb_col + 1))
		print_handle_wrapping(begin, nb);*/
	return (0);
	buf = 0;
	*begin = NULL;
}
