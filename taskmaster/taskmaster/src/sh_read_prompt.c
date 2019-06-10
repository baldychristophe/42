/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:36:22 by cbaldy            #+#    #+#             */
/*   Updated: 2016/05/12 17:50:01 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_set_local_env(void)
{
	if ((g_local = (t_local *)malloc(sizeof(t_local))) == NULL)
		return (-1);
	g_local->curs = 0;
	g_local->le_mode = 0;
	g_local->exit_value = 0;
	g_paste = NULL;
	return (0);
}

static int	sh_print_prompt(void)
{
	int				i;
	struct winsize	w;

	i = 0;
	i = ft_dprintf(STDIN_FILENO, "taskmaster> ");
	sh_set_local_env();
	g_local->curs = i + 1;
	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &w) < 0)
		return (0);
	g_local->nb_col = (w.ws_col == 0 ? 1 : w.ws_col);
	sh_set_term();
	ft_tputs("cd", 1, 0);
	return (i);
}

static int	sh_read_prompt(t_line_list **first, t_hist_list **hist)
{
	int			len;
	char		buf[10];
	int			i;

	i = 0;
	len = read(STDIN_FILENO, buf, 10);
	ft_bzero(&buf[len], 10 - len);
	if (ft_strcmp(buf, "\x09") != 0)
		clear_curr_compl();
	if ((len != 1 || buf[0] < 31 || buf[0] > 127) &&
			(len != 1 || buf[0] != 10))
		i = term_edit_line(buf, len, first, hist);
	else if (len == 1)
		i = term_write_line(first, buf[0]);
	return (i);
}

int			sh_prompt(void)
{
	t_line_list			*first;
	char				*str;
	int					i;
	t_hist_list			*modif_hist;

	if ((first = line_list_new(sh_print_prompt())) == NULL)
		return (0);
	modif_hist = retrieve_history(0, NULL);
	i = 0;
	while (i != 10 && i != 4 && i != -1 && i != 3)
		i = sh_read_prompt(&first, &modif_hist);
	if ((str = sh_retrieve_cmd_line(first, i)) != NULL &&
			get_bangged(&str, &first) >= 0)
		server_send_python(str);
	if (str != NULL)
		retrieve_history(1, first);
	line_list_free(first);
	clear_hist(&modif_hist);
	free(str);
	return (0);
}
