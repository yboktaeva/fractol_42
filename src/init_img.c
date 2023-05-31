/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:21:44 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 14:45:36 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	init_img(t_mlx *data, char **argv)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fractol");
	if (!data->win)
	{
		free(data->win);
		return (1);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	data->argv = argv;
	data->keysym = -1;
	data->zoom = 0.7;
	data->pt = malloc(sizeof(struct s_pt));
	palette1(data);
	palette2(data);
	palette3(data);
	palette4(data);
	palette5(data);
	data->palette_num = 1;
	return (0);
}

void	render_fractal(t_mlx *data)
{
	if (data->fractal == 1 || data->fractal == 2 || data->fractal == 5)
		switch_julia(data, data->c, data->z);
	if (data->fractal == 3)
		mandelbrot(data, data->c, data->z);
	if (data->fractal == 4)
		tricorn(data, data->c, data->z);
}
