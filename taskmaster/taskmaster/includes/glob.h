/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glob.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldy <dbaldy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:39:58 by dbaldy            #+#    #+#             */
/*   Updated: 2016/05/06 10:10:34 by dbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOB_H
# define GLOB_H

# include "shell.h"

int						escape_quotes(char *str, int *i, int c);
int						ft_free_tab(char **table);
int						strstr_cmd(char **str, int *i, t_hist_list **hist);
int						strcmp_cmd(char **str, int *i, t_hist_list **hist);
int						direct_digit(char **str, int *i, t_hist_list **hist);
int						backward_digit(char **str, int *i, t_hist_list **hist);

#endif
