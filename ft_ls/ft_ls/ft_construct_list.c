/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_construct_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:43:52 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 16:01:26 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_type_list			g_type_tab[] = {
	{0, "d"},
	{1, "p"},
	{2, "c"},
	{4, "d"},
	{6, "b"},
	{8, "-"},
	{10, "l"},
	{12, "s"},
	{14, "w"}
};

char				*g_mode_tab[] = {
	"---",
	"--x",
	"-w-",
	"-wx",
	"r--",
	"r-x",
	"rw-",
	"rwx"
};

static char			*ft_type_mode(unsigned char type, unsigned int mode)
{
	int		i[2];
	char	*str;

	str = ft_strnew(10);
	i[0] = 0;
	while (i[0] < 9)
	{
		if (type == g_type_tab[i[0]].type_nu)
			str = ft_strjoin("", g_type_tab[i[0]].type_abr);
		i[0]++;
	}
	str = ft_strjoin(str, g_mode_tab[(S_IRWXU & mode) / 64]);
	str = ft_strjoin(str, g_mode_tab[(S_IRWXG & mode) / 8]);
	str = ft_strjoin(str, g_mode_tab[(S_IRWXO & mode)]);
	return (ft_bit_analysis(str, mode));
}

static t_fi_list	*ft_aux_inspect(struct dirent *dp, t_fi_list *tmp,
		struct stat *buf, char *path)
{
	int		k;

	tmp->mode = ft_type_mode(dp->d_type, buf->st_mode);
	tmp->nb_links = buf->st_nlink;
	tmp->proprio = ft_strdup((getpwuid(buf->st_uid))->pw_name);
	tmp->groupe = ft_strdup((getgrgid(buf->st_gid))->gr_name);
	tmp->taille = buf->st_size;
	tmp->time_st = ((g_option & OPT_U) == 0 ? buf->st_mtimespec.tv_sec :
			buf->st_birthtimespec.tv_sec);
	tmp->block = buf->st_blocks;
	tmp->device = buf->st_rdev;
	if (tmp->mode[0] == 'l')
	{
		k = (buf->st_size > 0 ? buf->st_size : 1000);
		if ((tmp->link = (char *)malloc(k + 1)) == NULL)
			return (NULL);
		readlink(ft_strjoin(ft_strjoin(path, "/"), dp->d_name),
				tmp->link, k);
		tmp->link[k] = '\0';
	}
	return (tmp);
}

static t_fi_list	*ft_inspect_file(struct dirent *dp, char *path)
{
	t_fi_list		*tmp;
	struct stat		*buf;
	acl_t			eph;

	if ((buf = (struct stat *)malloc(sizeof(struct stat))) == NULL)
		return (NULL);
	lstat(ft_strjoin(ft_strjoin(path, "/"), dp->d_name), buf);
	if ((tmp = (t_fi_list *)malloc(sizeof(t_fi_list))) == NULL)
		return (NULL);
	tmp->next = NULL;
	tmp->previous = NULL;
	tmp->name = ft_strdup(dp->d_name);
	tmp = ft_aux_inspect(dp, tmp, buf, path);
	if (listxattr(ft_strjoin(ft_strjoin(path, "/"), dp->d_name), NULL,
			999, XATTR_NOFOLLOW) > 0)
		tmp->mode = ft_strjoin(tmp->mode, "@");
	else if ((eph = acl_get_file(ft_strjoin(ft_strjoin(path, "/"), dp->d_name),
				ACL_TYPE_EXTENDED)) != NULL)
	{
		tmp->mode = ft_strjoin(tmp->mode, "+");
		acl_free((void *)eph);
	}
	g_flag = 1;
	free(buf);
	return (tmp);
}

t_fi_list			**ft_non_open_file(char *path)
{
	char			*buf[2];
	DIR				*dirp;
	struct dirent	*dp;
	t_fi_list		**begin;

	if ((begin = (t_fi_list**)malloc(sizeof(t_fi_list*))) == NULL)
		return (NULL);
	*begin = NULL;
	buf[1] = (ft_strrchr(path, '/') == NULL ? "." : ft_strdup(path));
	if ((buf[0] = ft_strrchr(path, '/')) == NULL)
		buf[0] = ft_strdup(path);
	else
	{
		buf[0] = &(buf[0][1]);
		ft_strrchr(buf[1], '/')[1] = '\0';
	}
	if ((dirp = opendir(buf[1])) == NULL)
		return (NULL);
	while ((dp = readdir(dirp)) != NULL)
		if (ft_strcmp(buf[0], dp->d_name) == 0)
			*begin = ft_inspect_file(dp, buf[1]);
	if (ft_strcmp(buf[1], ".") != 0 && *begin != NULL)
		(*begin)->name = ft_strjoin(buf[1], buf[0]);
	closedir(dirp);
	return (begin);
}

t_fi_list			**ft_construct_list(char *path)
{
	DIR				*dirp;
	struct dirent	*dp;
	t_fi_list		**begin;

	if ((dirp = opendir(path)) == NULL)
	{
		if (errno != 20 && errno != 2)
			return (NULL);
		else
		{
			errno = -1;
			return (ft_non_open_file(path));
		}
	}
	if ((begin = (t_fi_list**)malloc(sizeof(t_fi_list*))) == NULL)
		return (NULL);
	*begin = NULL;
	while ((dp = readdir(dirp)) != NULL)
		if ((g_option & OPT_A) != 0 || dp->d_name[0] != '.')
			ft_pushback_list(begin, ft_inspect_file(dp, path));
	closedir(dirp);
	return (ft_sort_list(begin));
}
