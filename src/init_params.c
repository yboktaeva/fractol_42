/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:06:09 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 17:15:15 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_julia(t_mlx *data)
{
	data->offset_x = 0.0;
	data->offset_y = 0.0;
	data->z = (t_set){0.0, 0.0};
	data->julia_initial_c = (t_set){0.285, 0.01};
	data->c = (t_set){0.285, 0.01};
	data->max_iter = 100;
}

void	init_mandelbrot(t_mlx *data)
{
	data->offset_x = -0.3;
	data->offset_y = 0.0;
	data->c = (t_set){0.0, 0.0};
	data->z = (t_set){0.0, 0.0};
	data->max_iter = 100;
}

void	init_tricorn(t_mlx *data)
{
	data->offset_x = -0.2;
	data->offset_y = 0.0;
	data->c = (t_set){0.0, 0.0};
	data->z = (t_set){0.0, 0.0};
	data->max_iter = 100;
}
