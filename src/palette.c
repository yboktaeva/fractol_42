/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:53:33 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 15:41:03 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	palette1(t_mlx *data)
{
	data->pt->palette1[0] = 0x000066;
	data->pt->palette1[1] = 0x66CCFF;
	data->pt->palette1[2] = 0x000033;
	data->pt->palette1[3] = 0x336699;
	data->pt->palette1[4] = 0x6495ed;
	data->pt->palette1[5] = 0x4169e1;
	data->pt->palette1[6] = 0xf0ffff;
	data->pt->palette1[7] = 0xf0f8ff;
	data->pt->palette1[8] = 0xfff0f5;
}

void	palette2(t_mlx *data)
{
	data->pt->palette2[0] = 0xFF0000;
	data->pt->palette2[1] = 0xFFA500;
	data->pt->palette2[2] = 0xFFFF00;
	data->pt->palette2[3] = 0x00FF00;
	data->pt->palette2[4] = 0x0000FF;
	data->pt->palette2[5] = 0x00FFFF;
	data->pt->palette2[6] = 0x4B0082;
	data->pt->palette2[7] = 0x8A2BE2;
}

void	palette3(t_mlx *data)
{
	data->pt->palette3[0] = 0x000000;
	data->pt->palette3[1] = 0xFF0000;
	data->pt->palette3[2] = 0xFFFF00;
	data->pt->palette3[3] = 0xFFFFFF;
}

void	palette4(t_mlx *data)
{
	data->pt->palette4[0] = 0xFF0000;
	data->pt->palette4[1] = 0xFF7F00;
	data->pt->palette4[2] = 0xFFFF00;
	data->pt->palette4[3] = 0x00FF00;
	data->pt->palette4[4] = 0x00FFFF;
	data->pt->palette4[5] = 0x0000FF;
	data->pt->palette4[6] = 0x8B00FF;
	data->pt->palette4[7] = 0xFF00FF;
	data->pt->palette4[8] = 0xFF1493;
	data->pt->palette4[9] = 0xFF4500;
	data->pt->palette4[10] = 0x00FF7F;
}

void	palette5(t_mlx *data)
{
	data->pt->palette5[0] = 0xFFB6C1;
	data->pt->palette5[1] = 0xFFD700;
	data->pt->palette5[2] = 0x98FB98;
	data->pt->palette5[3] = 0xADD8E6;
	data->pt->palette5[4] = 0xFFA07A;
	data->pt->palette5[5] = 0x87CEFA;
	data->pt->palette5[6] = 0xFFC0CB;
	data->pt->palette5[7] = 0x00FF7F;
	data->pt->palette5[8] = 0xFFE4C4;
	data->pt->palette5[9] = 0xEEE8AA;
}
