/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:44:23 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/14 12:00:19 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "struct.h"
# include "libft.h"
# include "lib_push_swap.h"

# include <stdlib.h>
# include <unistd.h>

t_sol	*ps_solve(t_main *main);
t_sol	*ps_brutforce(t_main *main);
int		ps_is_coherent_move(t_main *main, t_sol *sol, int move);

t_sol	*ps_res_v3(t_main *main);
t_sol	*ps_next_move(t_main *main, t_sol *sol);
t_sol	*ps_execute_next_move(t_main *main, t_sol *sol, int move, int nb);

t_sol	*ps_v4(t_main *main);
t_sol	*ps_recompile(t_sol *sol);

t_sol	*ps_bubble_sort(t_main *main, t_sol *sol);
t_sol	*ps_quick_split(t_main *main, t_sol *sol);
t_sol	*ps_old_solve(t_main *main);

#endif
