/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:07:25 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 18:38:26 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt_list	g_opt_tab[] = {
	{'a', OPT_A},
	{'l', OPT_L},
	{'r', OPT_MINR},
	{'t', OPT_T},
	{'R', OPT_R},
	{'1', OPT_UN},
	{'U', OPT_U},
	{'S', OPT_S},
};

static int	ft_opt_index(char c)
{
	int		i;

	i = 0;
	if (c == g_opt_tab[5].opt_char && (g_option & OPT_L) != 0)
		return (OPT_UN - OPT_L);
	while (i < 8)
	{
		if (c == g_opt_tab[i].opt_char && (g_option & g_opt_tab[i].opt_nu) == 0)
			return (g_opt_tab[i].opt_nu);
		i++;
	}
	ft_putstr_fd("/bin/ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] \
[file ...]\n", 2);
	return ((g_option * (-1)) - 1);
}

int			ft_read_opt(int argc, char **argv)
{
	int		i[3];

	g_option = 0;
	i[0] = 1;
	while (i[0] < argc && argv[i[0]][0] == '-' && argv[i[0]][1] != '-')
	{
		i[1] = 1;
		while (i[1] < (int)ft_strlen(argv[i[0]]))
		{
			g_option = g_option + ft_opt_index(argv[i[0]][i[1]]);
			if (g_option < 0)
				return (-1);
			i[1]++;
		}
		i[0]++;
	}
	if (i[0] < argc && argv[i[0]][0] == '-' && argv[i[0]][1] == '-' &&
			ft_strlen(argv[i[0]]) > 2)
		g_option = g_option + ft_opt_index(argv[i[0]][1]);
	if (i[0] < argc && g_option >= 0)
		g_option = g_option + OPT_PATH;
	return (g_option);
}

static char	**ft_apply_opt_to_path(char **dir)
{
	if ((g_option & OPT_U) == 0)
		dir = ft_sort_dir(dir);
	if ((g_option & OPT_T) != 0 && (g_option & OPT_S) == 0)
		ft_time_sort_dir(dir);
	if ((g_option & OPT_MINR) != 0)
		ft_reverse_dir(dir);
	dir = ft_sort_type_dir(dir);
	dir = ft_sort_errno(dir);
	return (dir);
}

char		**ft_read_path(int argc, char **argv)
{
	char	**dir;
	int		i[2];

	i[0] = 1;
	i[1] = 0;
	while (i[0] < argc && i[1] == 0 && argv[i[0]][0] == '-')
	{
		if (argv[i[0]][0] == '-' && (argv[i[0]][1] == '-' ||
					argv[i[0]][1] == '\0'))
			i[1] = 1;
		i[0]++;
	}
	if (argv[i[0] - 1][1] == '\0')
		i[0]--;
	if (i[0] == argc)
	{
		dir = ft_memalloc(sizeof(char *) * 2);
		dir[0] = ".";
		return (dir);
	}
	return (ft_apply_opt_to_path(&(argv[i[0]])));
}
