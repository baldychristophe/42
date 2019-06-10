/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:36:22 by cbaldy            #+#    #+#             */
/*   Updated: 2016/03/02 16:59:50 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_print_prompt(void)
{
	int		i;
	struct winsize	w;

	i = 0;
	if ((i = sh_is_new_var("USER")) != -1)
		i = ft_dprintf(STDIN_FILENO, &(ft_strchr(g_env[i], '=')[1]));
	if (i < 0)
		i = 0;
	i += ft_dprintf(STDIN_FILENO, "$>");
	g_local->prompt = i;
	g_local->curs = i + 1;
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) < 0)
		return (0);
	g_local->nb_col = w.ws_col;
	return (0);
}

static int	sh_read_prompt(t_com_list **begin, t_hist_list **hist)
{
	int			len;
	char		*buf;

	buf = ft_strnew(10);
	len = read(STDIN_FILENO, buf, 9);
	if ((len != 1 || buf[0] < 31 || buf[0] > 127) &&
			(len != 1 || buf[0] != 10))
		term_edit_line(buf, len, begin, hist);
	if (len == 1)
		term_write_line(begin, buf[0]);
	free(buf);
	return (buf[0]);
}

int			sh_prompt(void)
{
	t_com_list			*begin;
	static t_hist_list	*hist;
	char				*str;
	int 				i;

	sh_print_prompt();
	i = 0;
	begin = NULL;
	hist_list_new(&hist);
	while (i != 10 && i != -1 && i != 4)
		i = sh_read_prompt(&begin, &hist);
	str = com_list_retrieve(begin);
	ft_printf("%s\n", str);
	hist_add_elem(begin, &hist);
	if (str != NULL && ft_strlen(str) != 0)
		sh_split_com(str);
	if (str != NULL)
		free(str);
	return (0);
}
