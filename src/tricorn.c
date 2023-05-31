/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:28:41 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 17:16:10 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static double	zoom_re(t_mlx *data, int x)
{
	return (((x - WIDTH / 2.0) * 4.0 / WIDTH) * data->zoom);
}

static double	zoom_im(t_mlx *data, int y)
{
	return (((y - HEIGHT / 2.0) * 4.0 / WIDTH) * data->zoom);
}

int	tricorn(t_mlx *t, t_set c, t_set z)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			c.r = zoom_re(t, x) + t->offset_x;
			c.i = zoom_im(t, y) + t->offset_y;
			z = (t_set){c.r, c.i};
			color = get_iter(t, z, c);
			my_pix_put(t, x, y, color);
		}
	}
	mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
	return (0);
}
