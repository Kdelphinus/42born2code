/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/28 23:22:29 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	complex_init(t_complex *complex, t_fractal *fractal)
{
	complex->z_real = 0;
	complex->z_imagin = 0;
	complex->c_real = -fractal->coor_boundary;
	complex->c_imagin = -fractal->coor_boundary;
}

static int	mandelbrot_calculation(t_complex *complex)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (++n <= MAX_REPEAT)
	{
		x = pow(complex->z_real, 2) - pow(complex->z_imagin, 2) \
			+ complex->c_real;
		y = 2 * complex->z_real * complex->z_imagin + complex->c_imagin;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		complex->z_real = x;
		complex->z_imagin = y;
	}
	return (MAX_REPEAT);
}

void	mandel_draw(t_fractal *fractal)
{
	int	value;
	int	coor;

	complex_init(fractal->complex, fractal);
	while (fractal->complex->c_imagin <= fractal->coor_boundary)
	{
		while (fractal->complex->c_real <= fractal->coor_boundary)
		{
			coor = (fractal->complex->c_imagin + fractal->coor_boundary) * (HEIGHT / 2.0 / fractal->coor_boundary) * WIDTH + \
				(fractal->complex->c_real + fractal->coor_boundary) * (WIDTH / 2.0 / fractal->coor_boundary);
			value = mandelbrot_calculation(fractal->complex);
			if (fractal->color == 1)
				coloring_green(coor, value, fractal->img);
			else
				coloring_blue(coor, value, fractal->img);
			fractal->complex->c_real += fractal->coor_boundary * 2.0 / WIDTH;
			fractal->complex->z_real = 0;
			fractal->complex->z_imagin = 0;
		}
		fractal->complex->c_imagin += fractal->coor_boundary * 2.0 / HEIGHT;
		fractal->complex->c_real = -fractal->coor_boundary;
	}
}
