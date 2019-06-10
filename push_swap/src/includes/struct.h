/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:39:21 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/07 18:46:38 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define MAX_BF 11
# define SORTED 11
# define SA 0
# define SB 1
# define PA 2
# define PB 3
# define RA 4
# define RB 5
# define RRA 6
# define RRB 7
# define RR 8
# define RRR 9
# define SS 10

typedef struct		s_jeton
{
	int				id;
	int				pos;
	struct s_jeton	*next;
	struct s_jeton	*prev;
}					t_jeton;

typedef struct		s_sol
{
	int				move;
	struct s_sol	*next;
	struct s_sol	*prev;
}					t_sol;

typedef struct		s_main
{
	int				nb;
	struct s_jeton	**a_begin;
	struct s_jeton	**a_end;
	struct s_jeton	**b_begin;
	struct s_jeton	**b_end;
}					t_main;

#endif
