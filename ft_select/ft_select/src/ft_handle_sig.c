/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:52:14 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/24 19:26:41 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	ft_handle_quit(void)
{
	ft_reset_term(g_fd);
	close(g_fd);
	ft_free_list(g_begin);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGCONT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	exit(1);
}

static void	ft_handle_sigstsp(void)
{
	struct termios	w;
	char			cp[2];

	tcgetattr(0, &w);
	cp[0] = w.c_cc[VSUSP];
	cp[1] = 0;
	ft_reset_term(g_fd);
	signal(SIGINT, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

static void	sighandler(int signum)
{
	if (signum == SIGWINCH)
		ft_print_list(g_begin, g_fd);
	else if (signum == SIGTSTP)
		ft_handle_sigstsp();
	else if (signum == SIGCONT)
	{
		ft_set_term(g_fd);
		signal(SIGTSTP, sighandler);
		ft_print_list(g_begin, g_fd);
	}
	else if (signum == SIGINT || signum == SIGTERM)
		ft_handle_quit();
}

void		ft_handle_sig(t_arg_list *begin, int fd)
{
	g_fd = fd;
	g_begin = begin;
	signal(SIGWINCH, sighandler);
	signal(SIGTSTP, sighandler);
	signal(SIGCONT, sighandler);
	signal(SIGINT, sighandler);
	signal(SIGQUIT, sighandler);
}
