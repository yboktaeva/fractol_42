/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:51:20 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 15:39:29 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	color1(t_mlx *data, int i)
{
	int	palette_size;

	if (data->palette_num == 1)
	{
		palette_size = 9;
		return (data->pt->palette1[i % palette_size]);
	}
	else if (data->palette_num == 2)
	{
		palette_size = 9;
		return (data->pt->palette2[i % palette_size]);
	}
	else if (data->palette_num == 3)
	{
		palette_size = 4;
		return (data->pt->palette3[i % palette_size]);
	}
	return (0);
}

static int	color2(t_mlx *data, int i)
{
	int	palette_size;

	if (data->palette_num == 4)
	{
		palette_size = 11;
		return (data->pt->palette4[i % palette_size]);
	}
	else if (data->palette_num == 5)
	{
		palette_size = 11;
		return (data->pt->palette5[i % palette_size]);
	}
	return (0);
}

int	get_color(t_mlx *data, int i)
{
	int	j;

	if (data->palette_num == 1 || data->palette_num == 2
		|| data->palette_num == 3)
		j = color1(data, i);
	if (data->palette_num == 4 || data->palette_num == 5)
		j = color2(data, i);
	return (j);
}

int	get_iter(t_mlx *data, t_set z, t_set c)
{
	int		i;
	int		res;
	double	tmp;

	i = 0;
	while (z.r * z.r + z.i * z.i < 4 && i < data->max_iter)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		if (data->fractal == 4)
			z.i = -2 * z.i * tmp + c.i;
		else
			z.i = 2 * z.i * tmp + c.i;
		i++;
	}
	res = get_color(data, i);
	return (res);
}

void	my_pix_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
