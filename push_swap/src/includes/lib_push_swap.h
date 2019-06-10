/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:05:47 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/08 16:38:56 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PUSH_SWAP_H
# define LIB_PUSH_SWAP_H

# include "struct.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

t_jeton		*lps_get_pile(int argc, char **argv);
t_main		*lps_get_main(int argc, char **argv);
t_jeton		*lps_jeton_new_elem(const char *str, const int pos);
int			*lps_check_validity(int argc, char **argv);
int			lps_jeton_list_free(t_jeton *begin);
int			lps_jeton_list_print(t_jeton *begin);
int			lps_jeton_list_is_sorted(t_jeton *begin, int pile);
int			lps_operate(int move, t_main *main);
int			lps_operate_special_move(int move, t_main *main);
void		lps_main_print_state(t_main *main);
int			lps_main_free(t_main *main);
t_sol		*lps_sol_new_elem(int move);
t_sol		*lps_sol_list_insert(int move, t_sol *last);
void		lps_sol_list_print(t_sol *begin);
void		lps_sol_list_free(t_sol *begin);
char		*lps_convert_move_to_string(int move);
t_sol		*lps_move(int move, t_main *main, t_sol *sol);
int			lps_main_is_sorted(t_main *main);
int			lps_opposite_move(int move);
int			lps_convert_string_to_int(char *str);

#endif
