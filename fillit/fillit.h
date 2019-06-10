/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:20:11 by cbaldy            #+#    #+#             */
/*   Updated: 2015/12/03 10:27:49 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void	ft_putstr(char *src);
int		ft_strlen(char *src);
char	*stock(char **input);
char	*add_stock(char *stock, char *buf);
int		ft_check(char *str);
int		check(char *str);
void	ft_putchar(char c);
int		***lecture(char *str);
void	ft_print_sol(int **echiquier);
unsigned int taille(char *str);
int		ft_valid(int ***tab);
int		**resol(int ***tab, int nb_tetri);
int		sqrt_fillit(int nb);
int		**create_empty_sol(int size);

# endif
