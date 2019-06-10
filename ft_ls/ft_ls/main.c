/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:52:49 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 18:46:33 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int			i;
	char		**dir;

	if (ft_read_opt(argc, argv) == -1)
		return (0);
	dir = ft_read_path(argc, argv);
	i = ((g_option & OPT_PATH) != 0 ? ft_direct_path(dir) : 0);
	while (dir[i] != NULL && i >= 0)
	{
		g_link = (ft_is_link(dir[i]) == 10 && dir[i][ft_strlen(dir[i]) - 1]
				!= '/' && (g_option & OPT_L) != 0 ? 1 : 0);
		if (dir[1] != NULL && ft_type_dir(dir[i]) == 1 && g_link != 1)
			ft_putendl(ft_strjoin(dir[i], ":"));
		ft_recursive(dir[i]);
		if (dir[i][0] == 0)
			return (0);
		if (dir[i + 1] != NULL && ft_type_dir(dir[i + 1])
				== 1 && ft_errno(dir[i]) == 0)
			ft_putchar('\n');
		i++;
	}
	return (0);
}
