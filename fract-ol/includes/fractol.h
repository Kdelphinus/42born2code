/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:38 by myko              #+#    #+#             */
/*   Updated: 2022/10/04 20:24:29 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include "../mlx_linux/mlx.h" // linux
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

// TODO KEY_UP, KEY_DOWN 값 다시 확인하기
// KEY_AR, KEY_A, KEY_B, KEY_G 값도 확인하여 고치기
// use mlx
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_UP				121
# define KEY_DOWN			122
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_AR				20
# define KEY_A				21
# define KEY_B				22
# define KEY_G				23
# define SCROLL_UP			4
# define SCROLL_DOWN		5

// use to calculate fractal
# define BOUNDARY			2
# define MAX_REPEAT			128
# define COOR_BOUNDARY		2
# define SIDE				1000

typedef struct s_complex
{
	double	z_r;
	double	z_i;
	double	c_r;
	double	c_i;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_frac
{
	void		*mlx_ptr;
	void		*win;
	t_img		*img;
	t_complex	*complex;
	double		c_bd;
	double		move_ud;
	double		move_rl;
	double		d;
	int			color;
	int			flag;
	int			multi;
	int			c_argc;
	char		**c_argv;
}				t_frac;

// main.c
int		main(int argc, char **argv);

// fractal draw
void	mandelbrot_draw(t_frac *frac);
void	julia_draw(t_frac *frac);
void	multibrot_draw(t_frac *frac);
void	mandelbox_draw(t_frac *frac);
void	multicron_draw(t_frac *frac);
void	burning_draw(t_frac *frac);
void	coloring(int coor, int value, t_frac *frac);

// utils_1.c
int		fractal_draw(t_frac *frac);
double	str_to_double(char *s);

// utils_2.c
int		ft_close(void);
int		ft_error(void);

#endif