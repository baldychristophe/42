/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:46:54 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/23 19:14:10 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_get_term_fildes(void)
{
	char	*term;

	if ((term = getenv("TERM")) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "ft_select: terminal unknown\n");
		return (-1);
	}
	if (tgetent(NULL, term) != 1)
	{
		ft_dprintf(STDERR_FILENO, "ft_select: terminal unknown\n");
		return (-1);
	}
	return (0);
}

int			ft_set_term(int flag)
{
	struct termios	tmp;
	int				fd;

	if (ft_get_term_fildes() < 0)
		return (-1);
	if (flag == -1)
	{
		if ((fd = open(ttyname(STDIN_FILENO), O_RDWR)) < 0)
			return (-1);
	}
	else
		fd = flag;
	if (tcgetattr(fd, &tmp) < 0)
		return (-1);
	tmp.c_cc[VMIN] = 1;
	tmp.c_cc[VTIME] = 0;
	tmp.c_lflag &= ~(ICANON | ECHO);
	if ((tcsetattr(fd, TCSANOW, &tmp)) < 0)
		return (-1);
	ft_tputs("vi", 1, 0, fd);
	return (fd);
}

int			ft_reset_term(int fd)
{
	struct termios	tmp;

	ft_tputs("cd", 1, 0, fd);
	ft_tputs("ve", 1, 0, fd);
	if (tcgetattr(fd, &tmp) < 0)
		return (-1);
	tmp.c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(fd, TCSANOW, &tmp)) < 0)
		return (-1);
	return (0);
}

int			ft_free_list(t_arg_list *begin)
{
	t_arg_list		*end;

	end = begin->previous;
	end->next = NULL;
	while (begin != NULL)
	{
		end = begin;
		begin = begin->next;
		free(end->name);
		free(end);
		end = NULL;
	}
	return (0);
}
