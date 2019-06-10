/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_1_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 16:10:49 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/27 18:51:38 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			fdf_scale(int *nb)
{
	int		h;

	h = (ABS(nb[2]) > nb[3] ? ABS(nb[2]) : nb[3]);
	h = (h > nb[0] / 2 ? h : nb[0] / 2);
	h = (h > nb[1] / 2 ? h : nb[1] / 2);
	return (300 / h);
}

static int	fdf_put_color(char *byte, int b, int g, int r)
{
	byte[0] = b;
	byte[1] = g;
	byte[2] = r;
	return (0);
}

int			fdf_color(char *byte, float height)
{
	if (height < -5)
		fdf_put_color(byte, 246, 2, 62);
	else if (height > 12)
		fdf_put_color(byte, 255, 255, 255);
	else if (height < 0)
		fdf_put_color(byte, 247, 2 + ((height + 5) / 5) * 202, 62 -
				((height + 5) / 5) * 55);
	else if (height == 0)
		fdf_put_color(byte, 77, 209, 46);
	else if (height <= 4)
		fdf_put_color(byte, 77 - (height / 4) * 56, 209 -
				(height / 4) * 21, 46 + (height / 4) * 187);
	else if (height <= 8)
		fdf_put_color(byte, 21 + ((height - 4) / 4) * 41, 188 -
				((height - 4) / 4) * 70, 233 - ((height - 4) / 4) * 41);
	else if (height <= 12)
		fdf_put_color(byte, 62 + ((height - 8) / 8) * 193, 118 +
			((height - 8) / 8) * 137, 192 + ((height - 8) / 8) * 63);
	return (0);
}

int			**fdf_height_convert(int **map)
{
	int		i[2];

	if (map[0][2] > -11 && map[0][3] < 11)
		return (map);
	i[0] = 1;
	while (i[0] < map[0][0] + 1)
	{
		i[1] = 0;
		while (i[1] < map[0][1])
		{
			if (map[i[0]][i[1]] < 0)
				map[i[0]][i[1]] = -log(abs(map[i[0]][i[1]]) + M_E);
			if (map[i[0]][i[1]] > 0)
				map[i[0]][i[1]] = log(map[i[0]][i[1]] + M_E);
			i[1]++;
		}
		i[0]++;
	}
	return (map);
}
