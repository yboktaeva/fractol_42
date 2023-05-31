/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:30:48 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 17:15:38 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	red_cross(t_mlx *data)
{
	free_all(data);
	exit (0);
}

t_set	change_julias(int keysym, t_set c, t_mlx *data)
{
	if (data->fractal == 2)
	{
		if (keysym == XK_1)
			c = (t_set){0, 0.8};
		else if (keysym == XK_2)
			c = (t_set){0.37, 0.1};
		else if (keysym == XK_3)
			c = (t_set){0.355, 0.355};
		else if (keysym == XK_4)
			c = (t_set){-0.54, 0.54};
		else if (keysym == XK_5)
			c = (t_set){-0.4, -0.59};
		else if (keysym == XK_6)
			c = (t_set){0.28, -0.59};
		else if (keysym == XK_7)
			c = (t_set){-0.79, 0.15};
		else if (keysym == XK_8)
			c = (t_set){0.34, -0.05};
		else if (keysym == XK_9)
			c = (t_set){-0.8, 0.156};
	}
	return (c);
}

int	key_move(int keysym, t_mlx *data)
{
	if (keysym == LEFT)
		data->offset_x += 0.1 * data->zoom;
	else if (keysym == UP)
		data->offset_y += 0.1 * data->zoom;
	else if (keysym == RIGHT)
		data->offset_x -= 0.1 * data->zoom;
	else if (keysym == DOWN)
		data->offset_y -= 0.1 * data->zoom;
	short_cut(keysym, data);
	return (0);
}

int	key_color(int keysym, t_mlx *data)
{
	if (keysym == XK_z)
		data->palette_num = 1;
	else if (keysym == XK_x)
		data->palette_num = 2;
	else if (keysym == XK_c)
		data->palette_num = 3;
	else if (keysym == XK_v)
		data->palette_num = 4;
	else if (keysym == XK_b)
		data->palette_num = 5;
	short_cut(keysym, data);
	return (0);
}

int	key_press(int keysym, t_mlx *data)
{
	if (data->win == NULL)
		return (1);
	if (keysym == XK_Escape || keysym == XK_q || keysym == XK_Q)
	{
		free_all(data);
		exit (0);
	}
	key_move(keysym, data);
	key_color(keysym, data);
	change_julias(keysym, data->c, data);
	return (0);
}
