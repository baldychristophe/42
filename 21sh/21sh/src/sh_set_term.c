/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_set_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:45:00 by cbaldy            #+#    #+#             */
/*   Updated: 2016/03/03 11:34:28 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_get_term_fildes(void)
{
	char	*term;
	int		i;

	if ((i = sh_is_new_var("TERM")) < 0)
		return (-1);
	term = &(ft_strchr(g_env[i], '=')[1]);
	if (tgetent(NULL, term) != 1)
		return (-1);
	return (0);
}

int			sh_set_term(void)
{
	struct termios	tmp;

	sh_get_term_fildes();
	if (tcgetattr(STDIN_FILENO, &tmp) < 0)
		return (-1);
	tmp.c_cc[VMIN] = 1;
	tmp.c_cc[VTIME] = 0;
	tmp.c_lflag &= ~(ICANON | ECHO);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &tmp)) < 0)
		return (-1);
	//ft_tputs("im", 1, 0);
	return (0);
}

int			sh_reset_term(void)
{
	struct termios	tmp;

	//ft_tputs("ei", 1, 0);
	if (tcgetattr(STDIN_FILENO, &tmp) < 0)
		return (-1);
	tmp.c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &tmp)) < 0)
		return (-1);
	return (0);
}
