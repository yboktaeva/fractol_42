/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:54:52 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 18:06:12 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	data;

	data.fractal = 0;
	if (check_input(&data, argc, argv) != 0)
	{
		ft_putendl(MSG_ARGS);
		exit (1);
	}
	if (param_julia(argc, argv, &data) != 0)
		return (1);
	if (init_img(&data, argv) == 1)
	{
		free_all(&data);
		exit (1);
	}
	render_fractal(&data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &key_press, &data);
	mlx_hook(data.win, DestroyNotify, 0, &red_cross, &data);
	mlx_mouse_hook(data.win, &mouse_handle, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
