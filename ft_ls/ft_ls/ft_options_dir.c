/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:10:01 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 18:50:14 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	ft_time_dir(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		*buf;

	if ((buf = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (0);
	if ((dirp = opendir(path)) == NULL)
	{
		if (errno == 20)
			return ((*ft_non_open_file(path))->time_st);
		else
			return (0);
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") != 0)
		{
			if ((lstat(ft_strjoin(ft_strjoin(path, "/"), dp->d_name), buf))
					== -1)
				perror("stat");
			return ((long)buf->st_mtimespec.tv_sec);
		}
	}
	return (0);
}

char	**ft_time_sort_dir(char **dir)
{
	int		i[2];
	char	*buf;

	i[0] = 1;
	while (i[0])
	{
		i[0] = 0;
		i[1] = 1;
		while (dir[i[1]] != NULL)
		{
			if (ft_time_dir(dir[i[1] - 1]) < ft_time_dir(dir[i[1]]))
			{
				i[0] = 1;
				buf = ft_strdup(dir[i[1] - 1]);
				dir[i[1] - 1] = ft_strdup(dir[i[1]]);
				dir[i[1]] = ft_strdup(buf);
				free(buf);
			}
			i[1]++;
		}
	}
	return (dir);
}

char	**ft_sort_type_dir(char **dir)
{
	int		i[2];
	char	*buf;

	i[0] = 1;
	while (i[0])
	{
		i[0] = 0;
		i[1] = 1;
		while (dir[i[1]] != NULL)
		{
			if (ft_type_dir(dir[i[1] - 1]) > ft_type_dir(dir[i[1]]))
			{
				i[0] = 1;
				buf = ft_strdup(dir[i[1]]);
				dir[i[1]] = ft_strjoin("", dir[i[1] - 1]);
				dir[i[1] - 1] = ft_strjoin("", buf);
			}
			i[1]++;
		}
	}
	return (dir);
}

char	**ft_sort_dir(char **dir)
{
	int		i[2];
	char	*buf;

	i[0] = 1;
	while (i[0])
	{
		i[0] = 0;
		i[1] = 1;
		while (dir[i[1]] != NULL)
		{
			if (ft_strcmp(dir[i[1] - 1], dir[i[1]]) > 0)
			{
				i[0] = 1;
				buf = ft_strdup(dir[i[1]]);
				dir[i[1]] = ft_strjoin("", dir[i[1] - 1]);
				dir[i[1] - 1] = ft_strjoin("", buf);
			}
			i[1]++;
		}
	}
	return (dir);
}

char	**ft_reverse_dir(char **dir)
{
	int		i[2];
	char	*buf;

	i[0] = 0;
	while (dir[i[0]] != NULL)
		i[0]++;
	i[1] = 0;
	while (i[1] < i[0] / 2)
	{
		buf = ft_strdup(dir[i[1]]);
		dir[i[1]] = ft_strjoin("", dir[i[0] - i[1] - 1]);
		dir[i[0] - i[1] - 1] = ft_strjoin("", buf);
		i[1]++;
	}
	return (dir);
}
