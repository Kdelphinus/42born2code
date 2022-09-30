/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:38 by myko              #+#    #+#             */
/*   Updated: 2022/09/30 16:59:47 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// # include "../mlx/mlx.h"
# include "../mlx_linux/mlx.h" // linux
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

// use mlx
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define SCROLL_UP			4
# define SCROLL_DOWN		5

// use to calculate fractal
# define BOUNDARY			2
# define MAX_REPEAT			256
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
	int			color;
	int			flag;
	int			c_argc;
	char		**c_argv;
}				t_frac;

// main.c
int		main(int argc, char **argv);

// fractal draw
void	mandelbrot_draw(t_frac *frac);
void	julia_draw(t_frac *frac);
void	multibrot_draw(t_frac *frac);
void	coloring(int coor, int value, t_frac *frac);

// utils_1.c
int		fractal_draw(t_frac *frac);
double	str_to_double(char *s);

// utils_2.c
int		ft_close(void);
int		ft_error(void);

#endif