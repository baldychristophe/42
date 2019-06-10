/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:12:49 by cbaldy            #+#    #+#             */
/*   Updated: 2016/05/13 11:41:28 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "struct_shell.h"
# include "ft_select.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>
# include <sys/socket.h>
# include <sys/un.h>

# define HIST_SIZE 32

int				server_send_python(char *str);
int				server_init_socket(void);

char			**get_cmd_list(void);
t_line_list		*str_to_line(char *str, t_line_list *first);
t_line_list		*line_list_dup(t_line_list *var);
int				line_list_free(t_line_list *first);
int				hist_print_line(char *s);
int				exit_completion(t_line_list *begin);
char			*cd_var_env(char *name);
int				clear_hist(t_hist_list **hist);
t_hist_list		*copy_hist(t_hist_list *hist);
int				sh_prompt(void);
int				ft_free_tab(char **arr);
char			*mod_strjoin(char *s1, char *s2, int fr);
char			*mod_strsub(char *s, unsigned int start, size_t len, int fr);
char			*mod_strtrim(char *s);
int				sh_getenv(char **com);
int				sh_set_env(char **env);
int				env_custom(char **com);
int				sh_set_term(void);
int				sh_reset_term(void);
int				ft_tputs(char *s, int nb_l, int flag);
int				term_edit_line(char *buf, int len, t_line_list **first,
		t_hist_list **hist);
t_com_list		*com_list_new(char value);
int				com_list_count(t_com_list *begin);
int				term_write_line(t_line_list **first, char buf);
char			*com_list_retrieve(t_com_list *begin);
int				*hist_list_new(t_hist_list **hist);
int				com_list_free(t_com_list *begin);
t_com_list		*com_list_dup(t_com_list *begin);
int				hist_change(int move, t_hist_list **hist, t_line_list **first);
int				print_command(t_com_list *new, char buf, t_line_list *first);
int				term_mv_horizontal(int move, t_line_list **first, int change);
t_com_list		*com_list_reconstruct(char *s);
int				com_list_remove(t_com_list *del, t_com_list **begin);
int				term_finish_line(t_line_list *first);
int				com_list_add(t_com_list **begin, t_com_list *new, int marge);
char			*com_list_join(t_com_list *begin);
int				term_mv_cursor(char buf, t_line_list **first);
int				sh_exec_control(char *str);
int				tab_mode(t_line_list **first);
char			*sh_retrieve_cmd_line(t_line_list *first, int end);
t_line_list		*line_list_new(int marge);
char			*line_list_retrieve(t_line_list *first);
t_line_list		*line_list_dup(t_line_list *var);
int				line_list_free(t_line_list *first);
int				line_list_get_marge(t_line_list *first);
int				hist_control_size(t_hist_list **hist);
int				sh_get_term_fildes(char **env);
t_hist_list		*retrieve_history(int flag, t_line_list *first);
int				get_bangged(char **str, t_line_list **first);
int				yank_line(char c, t_line_list **first);
int				ed_ctrld_line(t_line_list **first);
int				copy_paste(t_line_list **first);
int				not_escaped(char *var, int i, int flag);
int				copy_end_mode(t_line_list **first);
int				retrieve_row_to_skip(t_line_list *first);
int				tm_start_stop(char **apps);
int				tm_status(char **apps);

#endif
