/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_shell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 12:18:39 by cbaldy            #+#    #+#             */
/*   Updated: 2016/03/02 11:57:12 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SHELL_H
# define STRUCT_SHELL_H

# include "shell.h"

typedef struct			s_local
{
	int					prompt;
	int					curs;
	int					exit_value;
	int					nb_col;
}						t_local;

typedef struct			s_builtin
{
	char				*name;
	int					(*f)(char **com);
}						t_builtin;

typedef struct			s_com_list
{
	char				c;
	struct s_com_list	*next;
	struct s_com_list	*previous;
}						t_com_list;

typedef struct			s_hist_list
{
	struct s_com_list	*old;
	struct s_hist_list	*next;
	struct s_hist_list	*previous;
}						t_hist_list;

char					**g_env;
struct s_local			*g_local;

#endif
