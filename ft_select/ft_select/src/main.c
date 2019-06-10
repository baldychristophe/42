/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 12:08:22 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/24 19:28:26 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	t_arg_list	*begin;
	int			fd;
	int			i;

	if (ac < 2)
		return (0);
	if ((fd = ft_set_term(-1)) < 0)
		return (0);
	if ((begin = ft_create_list(ac, av)) == NULL)
		return (0);
	ft_handle_sig(begin, fd);
	while (42)
	{
		g_begin = begin;
		g_fd = fd;
		if ((i = ft_read_term(&begin, fd)) != 0)
		{
			if (i != -2)
				ft_free_list(begin);
			ft_reset_term(fd);
			return (close(fd));
		}
	}
	return (0);
}
