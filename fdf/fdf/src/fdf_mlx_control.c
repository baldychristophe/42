/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 09:17:20 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/27 11:05:09 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_key_hook(int keycode, t_param *param)
{
	if (keycode == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(53);
	}
	if (keycode >= 123 && keycode <= 126)
		fdf_rotation_img(param, keycode);
	if (keycode == 69 || keycode == 78)
		fdf_zoom_img(param, keycode);
	if (keycode == 18 || keycode == 19 || keycode == 20)
		fdf_change_img(param, keycode);
	return (0);
}

int		fdf_mlx_control(int **map)
{
	t_param	*param;

	if ((param = (t_param *)malloc(sizeof(t_param))) == NULL)
		return (0);
	if ((param->mlx = mlx_init()) == NULL)
		return (0);
	if ((param->win = mlx_new_window(param->mlx, WINL, WINH, "Fdf")) == NULL)
		return (0);
	if ((param->img = mlx_new_image(param->mlx, WINL, WINH)) == NULL)
		return (0);
	param->map = map;
	param->alpha = 5.5154;
	param->beta = 6.2852;
	param->scale = fdf_scale(map[0]);
	param->projection = 1;
	fdf_draw_iso(param);
	mlx_key_hook(param->win, fdf_key_hook, param);
	mlx_loop(param->mlx);
	return (0);
}
