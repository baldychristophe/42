/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_1_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 16:17:20 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/13 18:18:23 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_free_tab(char **tab)
{
	int		i;

	if (tab != NULL)
	{
		i = 0;
		while (tab[i] != NULL)
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
		return (1);
	}
	return (0);
}

char	*mod_strjoin(char *s1, char *s2, int fr)
{
	char	*tmp;

	if (s1 == NULL)
		tmp = ft_strdup(s2);
	else if (s2 == NULL)
		tmp = ft_strdup(s1);
	else
		tmp = ft_strjoin(s1, s2);
	if (fr == 1)
		free(s1);
	else if (fr == 2)
		free(s2);
	return (tmp);
}

char	*mod_strsub(char *s, unsigned int start, size_t len, int fr)
{
	char	*tmp;

	tmp = ft_strsub(s, start, len);
	if (fr == 1)
		free(s);
	return (tmp);
}
