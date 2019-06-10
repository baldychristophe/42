/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_axo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:07:23 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/27 18:29:08 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_put_vline(t_param *p, int l, int c, char *img_s)
{
	int		i[2];
	int		h[3];
	float	k;

	k = 0;
	h[0] = c - p->map[0][1] / 2;
	h[1] = l - p->map[0][0] / 2;
	while (k <= 1)
	{
		i[0] = WINL / 2 + p->scale * (h[0] * cos(p->beta) - (((1 - k) *
					   (h[1] - 1) + k * h[1]) * sin(p->beta)));
		i[1] = WINH / 2 + p->scale * (-h[0] * sin(p->alpha) * sin(p->beta) -
				((1 - k) * (h[1] - 1) + k * h[1]) * cos(p->beta) * sin(p->alpha) +
				((1 - k) * p->map[l - 1][c] + k * 
				p->map[l][c]) * cos(p->alpha));
		h[2] = (i[1] * p->j[1]) + i[0] * (p->j[0] / 8);
		if (i[1] >= 0 && i[1] <= (WINH + 1) * p->j[1] && i[0] >= 0 &&
				i[0] * p->j[0] / 8 <= p->j[1])
			fdf_color(&(img_s[h[2]]), ((1 - k) * p->map[l - 1][c] +
					k * p->map[l][c]));
		k = k + 0.01;
		//k = k + ((1 / (float)p->scale) < 0.05 ? 1 / (float)p->scale : 0.05);
	}
	return (0);
}

static int	fdf_put_hline(t_param *p, int l, int c, char *img_s)
{
	int		i[2];
	int		h[3];
	float	k;

	k = 0;
	h[0] = c - p->map[0][1] / 2;
	h[1] = l - p->map[0][0] / 2;
	while (k <= 1)
	{
		i[0] = WINL / 2 + p->scale * (((1 - k) * (h[0] - 1) + k * h[0]) * cos(p->beta)
				- h[1] * sin(p->beta));
		i[1] = WINH / 2 + p->scale * (-((1 - k) * (h[0] - 1) + k * h[0]) * sin(p->alpha)
				* sin(p->beta) - h[1] * cos(p->beta) * sin(p->alpha) + ((1 - k) *
				p->map[l][c - 1] + k * p->map[l][c]) * cos(p->alpha));
		h[2] = (i[1] * p->j[1]) + i[0] * (p->j[0] / 8);
		if (i[1] >= 0 && i[1] <= (WINH + 1) * p->j[1] && i[0] >= 0 &&
				i[0] * (p->j[0] / 8) <= p->j[1])
			fdf_color(&(img_s[h[2]]), ((1 - k) * p->map[l][c - 1] +
					k * p->map[l][c]));
		k = k + 0.01;
		//k = k + ((1 / (float)p->scale) < 0.05 ? 1 / (float)p->scale : 0.05);
	}
	return (0);
}

static int	fdf_put_point(t_param *param, int line, int col, char * img_s)
{
	if (col > 0)
		fdf_put_hline(param, line, col, img_s);
	if (line > 1)
		fdf_put_vline(param, line, col, img_s);
	return (0);
}

int			fdf_draw_axo(t_param *param)
{
	char	*img_s;
	int		i[2];

	img_s = mlx_get_data_addr(param->img, &(param->j[0]), &(param->j[1]),
			&(param->j[2]));
	i[0] = 1;
	while (i[0] < param->map[0][0] + 1)
	{
		i[1] = 0;
		while (i[1] < param->map[0][1])
		{
			fdf_put_point(param, i[0], i[1], img_s);
			i[1]++;
		}
		i[0]++;
	}
	printf("%f %f\n", param->alpha, param->beta);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}
