/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direct_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:05:41 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 18:50:12 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_aux_direct_path(char *dir, t_fi_list **begin)
{
	g_link = (ft_is_link(dir) == 10 && dir[ft_strlen(dir) - 1]
			!= '/' && (g_option & OPT_L) != 0 ? 1 : 0);
	(g_link == 1 ? ft_non_open_file(dir) : ft_construct_list(dir));
	ft_pushback_list(begin, *(g_link == 1 ? ft_non_open_file(dir) :
				ft_construct_list(dir)));
}

static void	ft_print_direct_path(t_fi_list **begin, char **dir, int i)
{
	((g_option & OPT_L) == 0 && (g_option & OPT_UN) == 0 ?
		ft_col_print(begin) : ft_lprint(begin, dir[i - 1]));
	if (dir[i] != NULL && ft_type_dir(dir[i])
			== 1 && i > 0 && ft_errno(dir[i - 1]) == 0)
		ft_putchar('\n');
}

static int	ft_big_aux(char **dir, int i)
{
	t_fi_list	**begin;

	g_link = (ft_is_link(dir[i]) == 10 && dir[i][ft_strlen(dir[i]) - 1]
			!= '/' && (g_option & OPT_L) != 0 ? 1 : 0);
	if (ft_is_link(dir[i]) == 10 && g_link == 0)
		return (i);
	begin = (g_link == 1 ? ft_non_open_file(dir[i]) :
			ft_construct_list(dir[i]));
	i++;
	while (dir[i] != NULL && ft_type_dir(dir[i]) == 0)
	{
		ft_aux_direct_path(dir[i], begin);
		i++;
	}
	if ((g_option & OPT_S) != 0)
		begin = ft_sort_list_size(begin);
	ft_print_direct_path(begin, dir, i);
	return (i);
}

int			ft_direct_path(char **dir)
{
	int			i;

	i = 0;
	while (dir[i] != NULL && ft_errno(dir[i]) != 0)
	{
		ft_recursive(dir[i]);
		if (dir[i][0] == 0)
			return (-1);
		i++;
	}
	if (dir[i] != NULL && ft_type_dir(dir[i]) == 0)
		i = ft_big_aux(dir, i);
	return (i);
}
