/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:40:02 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/29 14:06:36 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_set(t_mlx *data, t_set c)
{
	if (ft_atof(data->argv[2]) == 0.34 && ft_atof(data->argv[3]) == -0.05)
		c = (t_set){0.34, -0.05};
	if (ft_atof(data->argv[2]) == 0 && ft_atof(data->argv[3]) == 0.8)
		c = (t_set){0, 0.8};
	if (ft_atof(data->argv[2]) == 0.37 && ft_atof(data->argv[3]) == 0.1)
		c = (t_set){0.37, 0.1};
	if (ft_atof(data->argv[2]) == 0.355 && ft_atof(data->argv[3]) == 0.355)
		c = (t_set){0.355, 0.355};
	if (ft_atof(data->argv[2]) == -0.54 && ft_atof(data->argv[3]) == 0.54)
		c = (t_set){-0.54, 0.54};
	if (ft_atof(data->argv[2]) == -0.4 && ft_atof(data->argv[3]) == -0.59)
		c = (t_set){-0.4, -0.59};
	if (ft_atof(data->argv[2]) == 0.28 && ft_atof(data->argv[3]) == 0.08)
		c = (t_set){0.28, -0.59};
	if (ft_atof(data->argv[2]) == -0.835 && ft_atof(data->argv[3]) == -0.232)
		c = (t_set){-0.835, -0.232};
	if (ft_atof(data->argv[2]) == -0.7269 && ft_atof(data->argv[3]) == 0.1889)
		c = (t_set){-0.7269, 0.1889};
	if (ft_atof(data->argv[2]) == -0.8 && ft_atof(data->argv[3]) == 0.156)
		c = (t_set){-0.8, 0.156};
	if (ft_atof(data->argv[2]) == -1.3 && ft_atof(data->argv[3]) == 0.0)
		c = (t_set){-1.3, 0.0};
	else
		c = (t_set){ft_atof(data->argv[2]), ft_atof(data->argv[3])};
}
