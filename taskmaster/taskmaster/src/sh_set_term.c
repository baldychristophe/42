/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_set_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:45:00 by cbaldy            #+#    #+#             */
/*   Updated: 2016/05/06 10:39:25 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			sh_get_term_fildes(char **env)
{
	char	*term;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "TERM=", 5) == 0)
			break ;
		i++;
	}
	if (env[i] == NULL)
		return (-1);
	term = &(ft_strchr(env[i], '=')[1]);
	if (tgetent(NULL, term) != 1)
	{
		g_local->le_mode = 1;
		return (-1);
	}
	return (0);
}

int			sh_set_term(void)
{
	struct termios	tmp;

	if (tcgetattr(STDIN_FILENO, &tmp) < 0)
	{
		g_local->le_mode = 1;
		return (-1);
	}
	tmp.c_cc[VMIN] = 1;
	tmp.c_cc[VTIME] = 0;
	tmp.c_lflag &= ~(ICANON | ECHO | ISIG);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &tmp)) < 0)
	{
		g_local->le_mode = 1;
		return (-1);
	}
	return (0);
}

int			sh_reset_term(void)
{
	struct termios	tmp;

	if (tcgetattr(STDIN_FILENO, &tmp) < 0)
		return (-1);
	tmp.c_lflag |= (ICANON | ECHO | ISIG);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &tmp)) < 0)
		return (-1);
	ft_tputs("ve", 1, 0);
	return (0);
}
