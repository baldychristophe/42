/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 10:25:14 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/22 18:17:00 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	f_putchar(int c)
{
	static int	fd;

	if (c < 0)
	{
		fd = -c;
		return (0);
	}
	ft_putchar_fd(c, fd);
	return (0);
}

int			ft_tputs(char *s, int nb_l, int flag, int fd)
{
	char	*str[2];
	char	*term;

	f_putchar(-fd);
	str[0] = ft_memalloc(50);
	str[1] = str[0];
	term = tgetstr(s, &(str[0]));
	if (flag != 0)
		term = tgoto(term, flag, flag);
	tputs(term, nb_l, f_putchar);
	free(str[1]);
	return (0);
}
