/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:36:46 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/26 14:06:16 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void		signal_handler(int signum)
{
	ft_free_tab(g_env);
	sh_reset_term();
	ft_dprintf(STDOUT_FILENO, "\t21sh: exit\n");
	exit(signum);
}

int			main(int ac, char **av, char **env)
{
	if (ac != 1)
	{
		ft_dprintf(STDERR_FILENO, "minishell: argument invalid: %s\n", av[1]);
		return (0);
	}
	sh_set_env(env);
	if (sh_set_term() < 0)
		return (0);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, signal_handler);
	while (42)
	{
		if (sh_prompt() < 0)
		{
			ft_free_tab(g_env);
			sh_reset_term();
			return(0);
		}
	}
	return (0);
}
