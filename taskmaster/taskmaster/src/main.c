/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:36:46 by cbaldy            #+#    #+#             */
/*   Updated: 2016/05/12 18:19:37 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	main_error(int error)
{
	if (error == 0)
		ft_putstr_fd("taskmaster: the shell could not start properly\n",
				STDERR_FILENO);
	else if (error == 1)
		ft_putstr_fd("taskmaster: the socket could not be created\n",
				STDERR_FILENO);
	return (1);
}

int			main(int ac, char **av, char **env)
{
	if (ac != 1)
		return (main_error(0));
	else if (sh_get_term_fildes(env) < 0)
		return (main_error(0));
	else if (sh_set_term() < 0)
		return (main_error(0));
	else if (server_init_socket() < 0)
		return (main_error(1));
	while (42)
	{
		if (sh_prompt() < 0)
		{
			sh_reset_term();
			return (0);
		}
	}
	return (0);
	*av = NULL;
}
