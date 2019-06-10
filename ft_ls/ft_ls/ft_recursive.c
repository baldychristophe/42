/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 14:51:26 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 12:20:12 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_free_list(t_fi_list **begin)
{
	t_fi_list	*tmp;
	t_fi_list	*eph;

	if (begin != NULL)
		tmp = *begin;
	else
		tmp = NULL;
	while (tmp != NULL)
	{
		eph = tmp->next;
		free(tmp);
		tmp = eph;
	}
	if (begin != NULL)
		free(begin);
}

int				ft_is_link(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	char			*buf[2];
	int				sol;

	sol = -1;
	buf[1] = (ft_strrchr(path, '/') == NULL ? "." : ft_strdup(path));
	if ((buf[0] = ft_strrchr(path, '/')) == NULL)
		buf[0] = ft_strdup(path);
	else
	{
		buf[0] = &(buf[0][1]);
		ft_strrchr(buf[1], '/')[1] = '\0';
	}
	if ((dirp = opendir(buf[1])) == NULL)
		return (-1);
	while ((dp = readdir(dirp)) != NULL)
		if (ft_strcmp(buf[0], dp->d_name) == 0)
			sol = dp->d_type;
	closedir(dirp);
	return (sol);
}

static void		ft_aux_recursive(char *path_name, t_fi_list *tmp)
{
	char	*str;

	str = ft_strjoin(path_name, "/");
	ft_putchar('\n');
	ft_putendl(ft_strjoin(str, ft_strjoin(tmp->name, ":")));
	ft_recursive(ft_strjoin(str, tmp->name));
}

int				ft_recursive(char *path)
{
	t_fi_list	**begin;
	t_fi_list	*tmp;

	g_flag = 0;
	begin = (g_link == 1 && (g_option & OPT_L) != 0 ? ft_non_open_file(path)
			: ft_construct_list(path));
	if (path[0] == 0)
		path = ft_strdup("fts_open");
	if (errno != 0 && ft_errno(path) != 0 && g_flag == 0)
		perror(ft_strjoin("ls: ", path));
	((g_option & OPT_L) == 0 && (g_option & OPT_UN) == 0 ?
			ft_col_print(begin) : ft_lprint(begin, path));
	if ((g_option & OPT_R) != 0 && begin != NULL)
	{
		tmp = *begin;
		while (tmp != NULL)
		{
			if (tmp->mode[0] == 'd' && ft_strcmp(tmp->name, ".") != 0 &&
					ft_strcmp(tmp->name, "..") != 0)
				ft_aux_recursive(path, tmp);
			tmp = tmp->next;
		}
	}
	ft_free_list(begin);
	return (0);
}
