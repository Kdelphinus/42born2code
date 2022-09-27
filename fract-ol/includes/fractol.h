/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:38 by myko              #+#    #+#             */
/*   Updated: 2022/09/27 19:26:19 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
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
# define COOR_BOUNDARY		5
# define WIDTH				1000
# define HEIGHT				1000

typedef struct s_complex
{
	double	z_real;
	double	z_imagin;
	double	c_real;
	double	c_imagin;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		color;
}			t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}			t_mlx;

// main.c
int		main(int argc, char **argv);

// fractal draw
void	mandel_draw(t_complex *complex, t_img *img);
void	julia_draw(t_complex *complex, t_img *img, int argc, char **argv);
void	multibrot_draw(t_complex *complex, t_img *img, int argc, char **argv);

// utils_1.c
int		kind_fractal(char *s);
double	str_to_double(char *s);
void	coloring_green(int coor, int value, t_img *img);
void	coloring_blue(int coor, int value, t_img *img);

// utils_2.c
int		close(void);
int		ft_error(void);

#endif