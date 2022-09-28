/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/28 23:22:45 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	complex_init(t_fractal *fractal, int argc, char **argv)
{
	fractal->complex->z_real = -fractal->coor_boundary;
	fractal->complex->z_imagin = -fractal->coor_boundary;
	if (argc != 4)
	{
		printf("Set default value.\nc_real: -0.5125, c_imagin: -0.5213\n");
		fractal->complex->c_real = -0.5125;
		fractal->complex->c_imagin = -0.5213;
	}
	else
	{
		fractal->complex->c_real = str_to_double(argv[2]);
		fractal->complex->c_imagin = str_to_double(argv[3]);
	}
}

static int	julia_calculation(t_fractal *fractal)
{
	double	x;
	double	y;
	int		n;

	x = 0;
	y = 0;
	n = -1;
	while (++n <= MAX_REPEAT)
	{
		x = pow(fractal->complex->z_real, 2) - pow(fractal->complex->z_imagin, 2) \
			+ fractal->complex->c_real;
		y = 2 * fractal->complex->z_real * fractal->complex->z_imagin + fractal->complex->c_imagin;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		fractal->complex->z_real = x;
		fractal->complex->z_imagin = y;
	}
	return (MAX_REPEAT);
}

void	julia_draw(t_fractal *fractal, int argc, char **argv)
{
	int		value;
	int		coor;
	double	tmp_real;
	double	tmp_imagin;

	complex_init(fractal, argc, argv);
	while (fractal->complex->z_imagin <= fractal->coor_boundary)
	{
		tmp_imagin = fractal->complex->z_imagin;
		while (fractal->complex->z_real <= fractal->coor_boundary)
		{
			tmp_real = fractal->complex->z_real;
			coor = (fractal->complex->z_imagin + fractal->coor_boundary) * (HEIGHT / 2.0 / fractal->coor_boundary) * WIDTH + \
				(fractal->complex->z_real + fractal->coor_boundary) * (WIDTH / 2.0 / fractal->coor_boundary);
			value = julia_calculation(fractal);
			if (fractal->color == 1)
				coloring_green(coor, value, fractal->img);
			else
				coloring_blue(coor, value, fractal->img);
			fractal->complex->z_real = tmp_real + (fractal->coor_boundary * 2.0 / WIDTH);
			fractal->complex->z_imagin = tmp_imagin;
		}
		fractal->complex->z_imagin = tmp_imagin + (fractal->coor_boundary * 2.0 / HEIGHT);
		fractal->complex->z_real = -fractal->coor_boundary;
	}
}
