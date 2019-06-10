/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 18:20:11 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/16 18:47:17 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		sh_builtin_exit(char **com)
{
	return (-1);
	int		i;

	i = 0;
	if (com[1] != NULL)
		i = ft_atoi(com[1]);
	ft_free_tab(g_env);
	ft_free_tab(com);
	exit(i);
	return (0);
}
