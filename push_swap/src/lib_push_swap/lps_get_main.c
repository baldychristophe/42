/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_get_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:44:49 by cbaldy            #+#    #+#             */
/*   Updated: 2016/12/07 18:08:52 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static t_main	*lps_malloc_main(void)
{
	t_main	*main;

	if ((main = (t_main *)malloc(sizeof(t_main))) == NULL)
		return (NULL);
	if ((main->a_begin = (t_jeton **)malloc(sizeof(t_jeton *))) == NULL)
		return (NULL);
	if ((main->a_end = (t_jeton **)malloc(sizeof(t_jeton *))) == NULL)
		return (NULL);
	if ((main->b_begin = (t_jeton **)malloc(sizeof(t_jeton *))) == NULL)
		return (NULL);
	if ((main->b_end = (t_jeton **)malloc(sizeof(t_jeton *))) == NULL)
		return (NULL);
	return (main);
}

static t_main	*lps_construct_main(t_jeton *j_list, int argc)
{
	t_main	*main;
	t_jeton *buf;

	if ((main = lps_malloc_main()) == NULL)
		return (NULL);
	*(main->a_begin) = j_list;
	buf = j_list;
	while (buf->next != NULL)
		buf = buf->next;
	*(main->a_end) = buf;
	*(main->b_begin) = NULL;
	*(main->b_end) = NULL;
	main->nb = argc - 1;
	return (main);
}

t_main			*lps_get_main(int argc, char **argv)
{
	t_jeton	*j_list;

	if ((j_list = lps_get_pile(argc, argv)) == NULL)
		return (NULL);
	return (lps_construct_main(j_list, argc));
}
