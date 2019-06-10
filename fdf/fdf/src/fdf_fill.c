/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:53:51 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/26 12:38:04 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_put_vline(t_param *p, int l, int c, char *img_s)
{
	int		i[2];
	int		h[3];
	float	k;
	float	g;

	k = 0;
	h[0] = c - p->map[0][1] / 2;
	h[1] = l - p->map[0][0] / 2;
	while (k <= 1)
	{
		g = 0;
		while (g <= 1 && (1 - g - k) >= 0)
		{
			i[0] = WINL / 2 + p->scale * ((k * (h[0] + 1) + g * h[0] + (1 - g - k) * h[0])
					* cos(p->beta) - ((k * p->map[l][c + 1] + g * p->map[l + 1][c]
							+ (1 - k - g)  * p->map[l][c]) * sin(p->beta)));
			i[1] = WINH / 2 + p->scale * ((k * (h[0] + 1) + g * h[0] + (1 - g - k) * h[0])
					* sin(p->alpha) * sin(p->beta) + (g * (h[1] + 1) + k * h[1]
					+ (1 - g - k) * h[1]) * cos(p->alpha) + (k * p->map[l][c + 1]
					+ g * p->map[l + 1][c] + (1 - k - g) * p->map[l][c])
					* sin(p->alpha) * cos(p->beta));
			h[2] = (i[1] * p->j[1]) + i[0] * (p->j[0] / 8);
			if (h[2] >= 0 && h[2] <= WINH * p->j[1])//&& img_s[h[2]] == 0)
				fdf_color(&(img_s[h[2]]), (k * p->map[l][c + 1] + g * p->map[l + 1][c] +
						(1 - g - k) * p->map[l][c]));
			g = g + 0.01;
		}
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
	float	g;

	k = 0;
	h[0] = c - p->map[0][1] / 2;
	h[1] = l - p->map[0][0] / 2;
	while (k <= 1)
	{
		g = 0;
		while (g <= 1 && (1 - g - k) >= 0)
		{
			i[0] = WINL / 2 + p->scale * ((k * (h[0] - 1) + g * h[0] + (1 - g - k) * h[0])
					* cos(p->beta) - ((k * p->map[l][c - 1] + g * p->map[l - 1][c]
							+ (1 - k - g)  * p->map[l][c]) * sin(p->beta)));
			i[1] = WINH / 2 + p->scale * ((k * (h[0] - 1) + g * h[0] + (1 - g - k) * h[0])
					* sin(p->alpha) * sin(p->beta) + (g * (h[1] - 1) + k * h[1]
					+ (1 - g - k) * h[1]) * cos(p->alpha) + (k * p->map[l][c - 1]
					+ g * p->map[l - 1][c] + (1 - k - g) * p->map[l][c])
					* sin(p->alpha) * cos(p->beta));
			h[2] = (i[1] * p->j[1]) + i[0] * (p->j[0] / 8);
			if (h[2] >= 0 && h[2] <= WINH * p->j[1])//&& img_s[h[2]] == 0)
				fdf_color(&(img_s[h[2]]), (k * p->map[l][c - 1] + g * p->map[l - 1][c] +
						(1 - g - k) * p->map[l][c]));
			g = g + 0.01;
		}
		k = k + 0.01;
		//k = k + ((1 / (float)p->scale) < 0.05 ? 1 / (float)p->scale : 0.05);
	}
	return (0);
}

static int	fdf_put_point(t_param *param, int line, int col, char * img_s)
{
	if (col > 0 && line > 1)
		fdf_put_hline(param, line, col, img_s);
	if (line < param->map[0][0] && col < param->map[0][1] - 1)
		fdf_put_vline(param, line, col, img_s);
	return (0);
}

int			fdf_fill(t_param *param)
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
	//printf("%f  %f\n", param->alpha, param->beta);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}
