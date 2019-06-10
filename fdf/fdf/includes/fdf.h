/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:54:21 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/27 18:28:27 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>

# define WINL 1200
# define WINH 1000
# define ABS(x) (x < 0 ? -x : x)

typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct		s_param
{
	void			*mlx;
	void			*win;
	void			*img;
	int				**map;
	int				j[3];
	float			alpha;
	float			beta;
	int				scale;
	int				projection;
}					t_param;

int					**fdf_get_map(char *av);
int					fdf_mlx_control(int **map);
int					fdf_draw_iso(t_param *param);
int					fdf_rotation_img(t_param *param, int keycode);
int					fdf_scale(int *nb);
int					fdf_color(char *byte, float height);
int					fdf_zoom_img(t_param *param, int keycode);
int					fdf_draw_axo(t_param *param);
int					fdf_change_img(t_param *param, int keycode);
int					fdf_draw_obl(t_param *param);
int					fdf_fill(t_param *param);
int					**fdf_height_convert(int **map);

#endif
