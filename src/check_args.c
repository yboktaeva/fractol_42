/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:50:23 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 18:06:24 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	argc_2(t_mlx *data, char **argv)
{
	if (ft_strncmp(argv[1], "Julia", 6) == 0)
	{
		data->fractal = 1;
		init_julia(data);
	}
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		data->fractal = 2;
		init_julia(data);
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) == 0)
	{
		data->fractal = 3;
		init_mandelbrot(data);
	}
	else if (ft_strncmp(argv[1], "Tricorn", 8) == 0)
	{
		data->fractal = 4;
		init_tricorn(data);
	}
	else
		return (1);
	return (0);
}

int	check_input(t_mlx *data, int argc, char **argv)
{
	if (argc == 2)
	{
		if (argc_2(data, argv) != 0)
			return (1);
		return (0);
	}
	else if ((argc == 4) && ft_strncmp(argv[1], "Julia", 6) == 0)
	{
		data->fractal = 5;
		init_julia(data);
	}
	else
		return (1);
	return (0);
}

int	param_julia(int argc, char **argv, t_mlx *julia)
{
	if (argc == 4 && julia->fractal == 5)
	{
		if (is_float(argv[2]) == 0 || is_float(argv[3]) == 0)
		{
			ft_putendl(MSG_JULIA);
			return (1);
		}
		julia->c.r = ft_atof(argv[2]);
		julia->c.i = ft_atof(argv[3]);
	}
	return (0);
}
