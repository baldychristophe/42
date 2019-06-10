/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 11:17:37 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 16:49:53 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_pushback_list(t_fi_list **begin, t_fi_list *new)
{
	t_fi_list	*tmp;

	if (*begin == NULL)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp != NULL && tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->previous = tmp;
	}
}

void	ft_put_old_date(long st)
{
	int		i;
	char	*buf;

	i = 0;
	ft_putstr(ft_strsub(ctime(&st), 3, 8));
	buf = ft_strdup(ft_strrchr(ctime(&st), ' '));
	while (buf[i] != 0 && buf[i] != '\n')
		i++;
	ft_putstr(ft_strsub(buf, 0, i));
}

int		ft_type_dir(char *path)
{
	DIR		*dirp;

	if (ft_is_link(path) == 10 && (g_option & OPT_L) != 0)
		return (0);
	if ((dirp = opendir(path)) == NULL)
		return (0);
	closedir(dirp);
	return (1);
}

int		ft_nb_chiffre(int nb)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	if (nb == 0)
		return (2);
	while (nb / i > 0)
	{
		i *= 10;
		j++;
	}
	return (j);
}

char	*ft_bit_analysis(char *str, unsigned int mode)
{
	if ((S_ISVTX & mode) != 0 && (mode & S_IRWXO) != 0)
		str[9] = 't';
	else if ((S_ISVTX & mode) != 0)
		str[9] = 'T';
	if ((S_ISGID & mode) != 0 && (mode & S_IRWXG) != 0)
		str[6] = 's';
	else if ((S_ISGID & mode) != 0)
		str[6] = 'S';
	if ((S_ISUID & mode) != 0 && (mode & S_IRWXU) != 0)
		str[3] = 's';
	else if ((S_ISUID & mode) != 0)
		str[3] = 'S';
	return (str);
}
