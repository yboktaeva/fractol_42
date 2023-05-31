/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:01:49 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 17:15:25 by yuboktae         ###   ########.fr       */
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

void	switch_julia(t_mlx *data, t_set c, t_set z)
{
	if (data->fractal == 1)
	{
		c = (t_set){0.285, 0.01};
		first_julia(data, c, z);
	}
	else if (data->fractal == 2)
	{
		c = (t_set){0.285, 0.01};
		first_julia(data, c, z);
	}
	else if (data->fractal == 5)
	{
		julia_set(data, c);
		first_julia(data, c, z);
	}	
}

int	first_julia(t_mlx *j, t_set c, t_set z)
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
			z.r = zoom_re(j, x) + j->offset_x;
			z.i = zoom_im(j, y) + j->offset_y;
			color = get_iter(j, z, c);
			my_pix_put(j, x, y, color);
		}
	}
	mlx_put_image_to_window(j->mlx, j->win, j->img, 0, 0);
	return (0);
}
