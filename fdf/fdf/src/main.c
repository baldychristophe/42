/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 18:51:52 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/27 18:28:48 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char ** av)
{
	int		**map;

	if (ac != 2)
	{
		ft_putendl("error arguments");
		return (0);
	}
	if ((map = fdf_get_map(av[1])) == NULL)
	{
		ft_putendl("Invalid map");
		return (0);
	}
	map = fdf_height_convert(map);
	fdf_mlx_control(map);
	return (0);
}
