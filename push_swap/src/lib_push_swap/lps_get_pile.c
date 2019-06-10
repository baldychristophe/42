/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_get_pile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 16:08:29 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/08 17:20:39 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static t_jeton	*lps_get_pile_final_return(t_jeton *ret, char **av, int flag,
		int *sorted)
{
	if (flag == 1)
		ft_freetab(av);
	if (sorted != NULL)
		free(sorted);
	return (ret);
}

static int		lps_get_position(const char *str, const int *sorted)
{
	int		i;
	int		nb;

	nb = ft_atoi(str);
	i = 0;
	while (sorted[i] != nb)
		i++;
	return (i);
}

static t_jeton	*lps_build_pile(int ac, char **av, int flag)
{
	int		i;
	int		pos;
	int		*sorted;
	t_jeton	*j_arr[ac];

	if ((sorted = lps_check_validity(ac, av)) == NULL)
		return (lps_get_pile_final_return(NULL, av, flag, sorted));
	i = 0;
	while (i < ac)
	{
		pos = lps_get_position(av[i], sorted);
		if ((j_arr[i] = lps_jeton_new_elem(av[i], pos)) == NULL)
			return (lps_get_pile_final_return(NULL, av, flag, sorted));
		if (i > 0)
		{
			j_arr[i - 1]->next = j_arr[i];
			j_arr[i]->prev = j_arr[i - 1];
		}
		i++;
	}
	return (lps_get_pile_final_return(j_arr[0], av, flag, sorted));
}

static t_jeton	*lps_split_args(char *str)
{
	int		i;
	char	**arr;

	if ((arr = ft_strsplit(str, ' ')) == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
		i++;
	return (lps_build_pile(i, arr, 1));
}

t_jeton			*lps_get_pile(int argc, char **argv)
{
	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		return (lps_split_args(argv[1]));
	else
		return (lps_build_pile(argc - 1, &(argv[1]), 0));
}
