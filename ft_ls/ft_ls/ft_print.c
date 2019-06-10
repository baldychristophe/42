/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 10:43:28 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/06 16:01:24 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	*ft_max_col(t_fi_list **begin)
{
	t_fi_list	*tmp;
	int			*max;

	if ((max = (int *)malloc(sizeof(int) * 7)) == NULL)
		return (NULL);
	max[6] = -1;
	while (max[6]++ < 5)
		max[max[6]] = 0;
	tmp = *begin;
	while (tmp != NULL)
	{
		if (ft_nb_chiffre(tmp->nb_links) > max[0])
			max[0] = ft_nb_chiffre(tmp->nb_links);
		if ((int)ft_strlen(tmp->proprio) > max[1])
			max[1] = ft_strlen(tmp->proprio);
		if ((int)ft_strlen(tmp->groupe) > max[2])
			max[2] = ft_strlen(tmp->groupe);
		if (ft_nb_chiffre(tmp->taille) > max[3])
			max[3] = ft_nb_chiffre(tmp->taille);
		max[4] = max[4] + tmp->block;
		if (max[5] == 0 && ft_strlen(tmp->mode) > 10)
			max[5] = 1;
		tmp = tmp->next;
	}
	return (max);
}

static void	ft_putspace(int col, int *max, t_fi_list *tmp)
{
	int		k;

	k = 0;
	if (col == 0)
	{
		if (ft_strlen(tmp->mode) < 11)
			ft_putchar(' ');
		while (k++ < (max[col] - ft_nb_chiffre(tmp->nb_links) + 1))
			ft_putchar(' ');
	}
	else if (col == 1)
		while (k++ < (max[col] - (int)ft_strlen(tmp->proprio) + 1))
			ft_putchar(' ');
	else if (col == 2)
		while (k++ < (max[col] - (int)ft_strlen(tmp->groupe) + 0))
			ft_putchar(' ');
	else if (col == 3)
		while (k++ < (max[col] - ft_nb_chiffre(tmp->taille) + 2))
			ft_putchar(' ');
}

static void	ft_affiche_dev(t_fi_list *tmp, t_fi_list **begin)
{
	int		k;
	int		*tab;

	k = 0;
	if ((tab = (int *)malloc(sizeof(int) * 2)) == NULL)
		exit(1);
	tab = ft_dev_space(begin, tab);
	if (tmp->device != 0 || tmp->mode[0] == 'c')
	{
		while (k++ < (tab[0] - ft_nb_chiffre(major(tmp->device)) + 1))
			ft_putchar(' ');
		ft_putnbr(major(tmp->device));
		ft_putchar(',');
		k = 0;
		while (k++ < (tab[1] - ft_nb_chiffre(minor(tmp->device)) + 1))
			ft_putchar(' ');
		ft_putnbr(minor(tmp->device));
	}
	else
	{
		if (tab[0] != 0)
			while (k++ < (tab[1] + tab[0]))
				ft_putchar(' ');
		ft_putnbr(tmp->taille);
	}
}

static void	ft_affiche_option(t_fi_list *tmp, int *max, t_fi_list **begin)
{
	time_t seconds;

	ft_putstr(tmp->mode);
	ft_putspace(0, max, tmp);
	ft_putnbr(tmp->nb_links);
	ft_putchar(' ');
	ft_putstr(tmp->proprio);
	ft_putspace(1, max, tmp);
	ft_putchar(' ');
	ft_putstr(tmp->groupe);
	ft_putspace(2, max, tmp);
	ft_putspace(3, max, tmp);
	ft_affiche_dev(tmp, begin);
	seconds = time(NULL);
	if (time(NULL) - tmp->time_st < 15552000 && time(NULL) - tmp->time_st
			>= -15552000)
		ft_putstr(ft_strsub(ctime(&tmp->time_st), 3, 13));
	else
		ft_put_old_date(tmp->time_st);
	ft_putchar(' ');
	if (tmp->mode[0] == 'l')
		tmp->name = ft_strjoin(ft_strjoin(tmp->name, " -> "), tmp->link);
}

void		ft_lprint(t_fi_list **begin, char *path)
{
	t_fi_list	*tmp;
	int			*max;

	if (begin != NULL)
	{
		if ((g_option & OPT_L) != 0)
			max = ft_max_col(begin);
		tmp = *begin;
		if ((g_option & OPT_L) != 0 && ft_type_dir(path) == 1 &&
				g_link != 1)
			ft_putendl(ft_strjoin("total ", ft_itoa(max[4])));
		while (tmp != NULL)
		{
			if ((g_option & OPT_R) != 0 && tmp->mode[0] == 'd' &&
					ft_type_dir(path) == 0)
				perror(ft_strjoin("ls: ", tmp->name));
			if ((g_option & OPT_L) != 0)
				ft_affiche_option(tmp, max, begin);
			ft_putendl(tmp->name);
			tmp = tmp->next;
		}
	}
}
