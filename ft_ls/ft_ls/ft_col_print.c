/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 11:15:49 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 15:58:17 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	*ft_creat_tab(t_fi_list **begin)
{
	t_fi_list		*tmp;
	int				*tab;
	struct winsize	w;

	if ((tab = (int *)malloc(sizeof(int) * 5)) == NULL)
		return (NULL);
	tab[0] = 1;
	tab[1] = 0;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	tab[2] = w.ws_col;
	tmp = *begin;
	while (tmp != NULL)
	{
		if ((int)ft_strlen(tmp->name) > tab[0])
			tab[0] = ft_strlen(tmp->name);
		tab[1]++;
		tmp = tmp->next;
	}
	tab[3] = tab[2] / (tab[0] + ((tab[0] % 4) > 2 ? 5 : 4 - tab[0] % 4));
	tab[4] = tab[1] / tab[3];
	tab[4] = (tab[1] % tab[3] == 0 ? tab[4] : tab[4] + 1);
	return (tab);
}

static void	ft_put_line(t_fi_list **begin, int *tab, int i)
{
	int			j[3];
	t_fi_list	*tmp;

	j[0] = 1;
	j[1] = 1;
	tmp = *begin;
	while (j[0] <= tab[1] && tmp != NULL)
	{
		while (j[0] % tab[4] != i % tab[4])
			j[0]++;
		while (j[1] < j[0] && tmp != NULL)
		{
			tmp = tmp->next;
			j[1]++;
		}
		if (j[1] <= tab[1])
		{
			j[2] = ft_strlen(tmp->name) - 1;
			ft_putstr(tmp->name);
			while (j[2]++ < tab[0] - 1)
				ft_putchar(' ');
			ft_putchar('\t');
		}
		j[0]++;
	}
}

void		ft_col_print(t_fi_list **begin)
{
	int			*tab;
	int			i;

	if (begin != NULL)
	{
		i = 1;
		tab = ft_creat_tab(begin);
		while (i <= tab[4])
		{
			ft_put_line(begin, tab, i);
			ft_putchar('\n');
			i++;
		}
	}
}
