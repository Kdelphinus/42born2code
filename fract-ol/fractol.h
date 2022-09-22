/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:38 by myko              #+#    #+#             */
/*   Updated: 2022/09/22 19:54:49 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <mlx.h>
# include "mlx_linux/mlx.h" // linux
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define SUCCESS			-1
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			53
# define BOUNDARY			4
# define MAX_REPEAT			64

# define WIDTH				500
# define HEIGHT				500

typedef struct s_complex
{
	int	z_real;
	int	z_imaginary;
	double	c_real;
	double	c_imaginary;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}			t_mlx;

void	mandel_draw(t_complex *complex, t_img *img);
int		main(int argc, char **argv);

#endif