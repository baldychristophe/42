/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_list_compl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <dbaldy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 10:18:27 by dbaldy            #+#    #+#             */
/*   Updated: 2016/05/06 12:16:30 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char				*path_to_tab(char *var, int marge)
{
	int			i;
	int			count;
	char		*buf;

	count = 0;
	i = g_local->curs - marge - 2;
	while (var[count] && count < i)
	{
		if (var[count] != ' ')
			break ;
		count++;
	}
	if (count == i && var[count] == ' ')
		return (NULL);
	i = not_escaped(var, i, -1);
	count = not_escaped(var, i, 1);
	if (i < 0 || count - i < 0)
		return (NULL);
	buf = (count - i == 0) ? ft_strdup("./") : ft_strsub(var, i, count - i);
	return (buf);
}

char			**get_cmd_list(void)
{
	char	**res;

	if ((res = (char**)malloc(sizeof(char*) * 7)) == NULL)
		return (NULL);
	res[0] = ft_strdup("status");
	res[1] = ft_strdup("start");
	res[2] = ft_strdup("stop");
	res[3] = ft_strdup("restart");
	res[4] = ft_strdup("reloadconf");
	res[5] = ft_strdup("exit");
	res[6] = NULL;
	return (res);
}
