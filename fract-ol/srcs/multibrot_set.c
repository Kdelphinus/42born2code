/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/28 23:23:17 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static double	complex_init(t_fractal *fractal, t_complex *complex, int argc, char **argv)
{
	complex->z_real = 0;
	complex->z_imagin = 0;
	complex->c_real = -fractal->coor_boundary;
	complex->c_imagin = -fractal->coor_boundary;
	if (argc == 3)
		return (str_to_double(argv[2]));
	printf("Set default value.\nd: 6\n");
	return (6);
}

static int	multibrot_calculation(t_complex *complex, double d)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (++n <= MAX_REPEAT)
	{
		x = pow(pow(complex->z_real, 2) + pow(complex->z_imagin, 2), d / 2.0) \
			* cos(d * atan2(complex->z_imagin, complex->z_real)) \
			+ complex->c_real;
		y = pow(pow(complex->z_real, 2) + pow(complex->z_imagin, 2), d / 2.0) \
			* sin(d * atan2(complex->z_imagin, complex->z_real)) \
			+ complex->c_imagin;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		complex->z_real = x;
		complex->z_imagin = y;
	}
	return (MAX_REPEAT);
}

void	multibrot_draw(t_fractal *fractal, int argc, char **argv)
{
	int		value;
	int		coor;
	double	d;

	d = complex_init(fractal, fractal->complex, argc, argv);
	while (fractal->complex->c_imagin <= fractal->coor_boundary)
	{
		while (fractal->complex->c_real <= fractal->coor_boundary)
		{
			coor = (fractal->complex->c_imagin + fractal->coor_boundary) * (HEIGHT / 2.0 / fractal->coor_boundary) * WIDTH + \
				(fractal->complex->c_real + fractal->coor_boundary) * (WIDTH / 2.0 / fractal->coor_boundary);
			value = multibrot_calculation(fractal->complex, d);
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
