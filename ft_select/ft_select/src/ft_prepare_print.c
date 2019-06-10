/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:35:40 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/24 19:36:03 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		*ft_prepare_print(t_arg_list *begin, int fd)
{
	t_arg_list		*tmp;
	int				*win;
	struct winsize	w;

	if ((win = (int *)malloc(sizeof(int) * 6)) == NULL)
		return (NULL);
	win[0] = 1;
	win[1] = 0;
	ioctl(fd, TIOCGWINSZ, &w);
	win[2] = w.ws_col;
	win[5] = w.ws_row;
	tmp = begin;
	while (tmp->nb >= win[1])
	{
		win[1]++;
		if ((int)ft_strlen(tmp->name) > win[0])
			win[0] = ft_strlen(tmp->name);
		tmp = tmp->next;
	}
	win[0] = ((8 - (win[0] % 8)) != 1 ? win[0] : win[0] + 1);
	win[3] = win[2] / (win[0] + (8 - (win[0] % 8))) == 0;
	win[3] = (win[3] == 0 ? 1 : win[3]);
	win[4] = win[1] / win[3];
	win[4] = (win[1] % win[3] == 0 ? win[4] : win[4] + 1);
	return (win);
}
