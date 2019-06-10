/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:29:02 by cbaldy            #+#    #+#             */
/*   Updated: 2016/03/02 19:28:51 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "ft_printf.h"
# include "struct_shell.h"

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

int				sh_prompt(void);
int				sh_command(char **com);
int				sh_builtin_cd(char **com);
int				sh_builtin_env(char **com);
int				sh_builtin_setenv(char **com);
int				sh_builtin_unsetenv(char **com);
int				sh_builtin_exit(char **com);
int				ft_free_tab(char **arr);
char			*mod_strjoin(char *s1, char *s2, int fr);
char			*mod_strsub(char *s, unsigned int start, size_t len, int fr);
char			*mod_strtrim(char *s);
int				cd_exist_error(char *path, char *com, int flag);
char			*sh_get_env_var(char *var_name);
int				sh_add_var_env(char *name, char *value);
int				sh_rm_var_env(char *name);
int				sh_is_new_var(char *com);
int				sh_change_var_env(char *name, char *value);
char			*cd_get_path(char **com, int opt);
char			*cd_get_old_path(void);
char			*cd_print_path(char **com, char *n_path, int opt);
int				sh_getenv(char **com);
int				sh_set_env(char **env);
int				env_custom(char **com);
int				cd_substitution(char **com);
int				cd_update_env(char *old_path, char *new_path, int opt);

int				sh_set_term(void);
int				sh_reset_term(void);
int				sh_split_com(char *str);
int				ft_tputs(char *s, int nb_l, int flag);
int				term_edit_line(char *buf, int len, t_com_list **begin, t_hist_list **hist);
t_com_list		*com_list_new(char value);
int				com_list_count(t_com_list *begin);
int				term_write_line(t_com_list **begin, char buf);
char			*com_list_retrieve(t_com_list *begin);
int				*hist_list_new(t_hist_list **hist);
int				com_list_free(t_com_list *begin);
t_com_list		*com_list_dup(t_com_list *begin);
int				hist_change(int move, t_hist_list **hist, t_com_list **begin);
int				hist_add_elem(t_com_list *begin, t_hist_list **hist);
int				print_command(t_com_list **begin, char buf);

#endif
