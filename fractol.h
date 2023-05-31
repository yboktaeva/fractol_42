/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuboktae <yuboktae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:51:14 by yuboktae          #+#    #+#             */
/*   Updated: 2023/05/31 18:11:44 by yuboktae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 1280
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define MSG_ARGS "Please enter an argument:\nJulia julia Mandelbrot Tricorn"
# define MSG_JULIA "Please enter parameters for Julia:\nExemple: Julia 0 0.08"

typedef struct s_set
{
	double	r;
	double	i;
}			t_set;

typedef struct s_pt
{
	int	palette1[9];
	int	palette2[8];
	int	palette3[4];
	int	palette4[11];
	int	palette5[10];
}			t_pt;

typedef struct s_mlx
{
	void	*img;
	void	*mlx;
	void	*win;
	char	*addr;
	char	**argv;
	int		bpp;
	int		endian;
	int		max_iter;
	int		line_len;
	int		keysym;
	int		palette_num;
	int		fractal;
	double	zoom;
	double	offset_x;
	double	offset_y;
	t_set	c;
	t_set	z;
	t_set	julia_initial_c;
	t_pt	*pt;
}			t_mlx;

/*
 **INIT
 */
int		init_img(t_mlx *data, char **argv);
int		get_iter(t_mlx *data, t_set z, t_set c);
void	init_julia(t_mlx *data);
void	init_mandelbrot(t_mlx *data);
void	init_tricorn(t_mlx *data);
/*
 **IMAGE
 */
void	my_pix_put(t_mlx *data, int x, int y, int color);
int		mandelbrot(t_mlx *m, t_set c, t_set z);
int		tricorn(t_mlx *t, t_set c, t_set z);
int		first_julia(t_mlx *j, t_set c, t_set z);
void	render_fractal(t_mlx *data);
/*
 **COLORS
 */
void	palette1(t_mlx *data);
void	palette2(t_mlx *data);
void	palette3(t_mlx *data);
void	palette4(t_mlx *data);
void	palette5(t_mlx *data);
int		key_color(int keysym, t_mlx *data);
int		get_color(t_mlx *data, int i);
/*
 **EVENTS
 */
int		key_press(int keysym, t_mlx *data);
int		red_cross(t_mlx *data);
int		mouse_handle(int button, int x, int y, t_mlx *data);
int		key_move(int keysym, t_mlx *data);
t_set	change_julias(int keysym, t_set c, t_mlx *data);
void	short_cut(int keysym, t_mlx *data);
/*
 **FREE
 */
void	free_all(t_mlx *data);
/*
 **UTILS
 */
void	ft_putendl(char *s);
void	switch_julia(t_mlx *julia, t_set c, t_set z);
void	julia_set(t_mlx *data, t_set c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_input(t_mlx *data, int argc, char **argv);
int		is_float(const char *str);
int		param_julia(int argc, char **argv, t_mlx *data);
double	ft_atof(const char *str);

#endif
