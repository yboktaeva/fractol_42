/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:38:19 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 17:16:00 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	zoom(int x, int y, t_mlx *data)
{
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	data->offset_x += (((x - WIDTH / 2.0) * 4.0 / WIDTH) * data->zoom) / 4;
	data->offset_y += (((y - HEIGHT / 2.0) * 4.0 / HEIGHT) * data->zoom) / 4;
}

void	short_cut(int keysym, t_mlx *data)
{
	t_set	rrr;

	if (data->fractal == 2)
	{
		rrr = change_julias(keysym, data->c, data);
		data->c = rrr;
		first_julia(data, data->c, data->z);
	}
	else if (data->fractal == 1)
	{
		data->c = (t_set){0.285, 0.01};
		first_julia(data, data->c, data->z);
	}
	else if (data->fractal == 3)
		mandelbrot(data, data->c, data->z);
	else if (data->fractal == 4)
		tricorn(data, data->c, data->z);
	else if (data->fractal == 5)
	{
		julia_set(data, data->c);
		first_julia(data, data->c, data->z);
	}
}

int	mouse_handle(int button, int x, int y, t_mlx *data)
{
	if (button == SCROLL_DOWN)
	{
		zoom(x, y, data);
		data->zoom *= 1.1;
	}
	else if (button == SCROLL_UP)
	{
		zoom(x, y, data);
		data->zoom /= 1.1;
	}
	short_cut(button, data);
	return (0);
}
