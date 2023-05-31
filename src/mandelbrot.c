/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:02:53 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 17:15:50 by yuboktae         ###   ########.fr       */
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

int	mandelbrot(t_mlx *m, t_set c, t_set z)
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
			c.r = zoom_re(m, x) + m->offset_x;
			c.i = zoom_im(m, y) + m->offset_y;
			color = get_iter(m, z, c);
			my_pix_put(m, x, y, color);
		}
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	return (0);
}
