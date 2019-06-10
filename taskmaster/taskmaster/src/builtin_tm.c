/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_tm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <dbaldy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 11:28:06 by dbaldy            #+#    #+#             */
/*   Updated: 2016/05/13 11:45:42 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		tm_start_stop(char **apps)
{
	char	**tmp;
	char	*to_print;

	tmp = apps + 2;
	to_print = (ft_strcmp(apps[1], "started") == 0) ? "started" : "stopped";
	while (*tmp)
	{
		ft_printf("%s: %s\n", to_print, *tmp);
		tmp++;
	}
	return (0);
}

int		tm_status(char **apps)
{
	char	**tmp;
	char	**status;

	tmp = apps;
	while (*tmp)
	{
		status = ft_strsplit(*tmp, '.');
		ft_printf("pid: %5s, uptime: %7s, %-10s %s\n", status[2],
				status[3], status[1], status[0]);
		ft_freetab(status);
		tmp++;
	}
	return (0);
}
