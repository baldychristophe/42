/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 09:51:55 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/27 11:13:01 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	fdf_redirect_draw(t_param *param)
{	
	mlx_destroy_image(param->mlx, param->img);
	param->img = mlx_new_image(param->mlx, WINL, WINH);
	if (param->projection == 1)
		fdf_draw_iso(param);
	else if (param->projection == 2)
		fdf_draw_axo(param);
	else
		fdf_fill(param);
	return (0);
}

int			fdf_change_img(t_param *param, int keycode)
{
	if (keycode == 18 && param->projection != 1)
		param->projection = 1;
	else if (keycode == 19 && param->projection != 2)
		param->projection = 2;
	else if (keycode == 20 && param->projection != 3)
		param->projection = 3;
	else
		return (0);
	if (param->projection == 1 || param->projection == 3)
	{
		param->alpha = 5.5154;
		param->beta = 6.2852;
	}
	else
	{
		param->alpha = 3.6154;
		param->beta = 12.8852;
	}
	fdf_redirect_draw(param);
	return (0);
}

int			fdf_rotation_img(t_param *param, int keycode)
{
	if (keycode == 123)
		param->beta += 0.1;
	else if (keycode == 124)
		param->beta -= 0.1;
	else if (keycode == 125)
		param->alpha += 0.1;
	else if (keycode == 126)
		param->alpha -= 0.1;
	fdf_redirect_draw(param);
	return (0);
}

int			fdf_zoom_img(t_param *param, int keycode)
{
	if (keycode == 69 && param->scale < 30)
		param->scale += 1;
	else if (keycode == 78 && param->scale > 0)
		param->scale -= 1;
	fdf_redirect_draw(param);
	return (0);
}
