/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/28 18:54:07 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	complex_init(t_complex *complex, int argc, char **argv)
{
	complex->z_real = 0;
	complex->z_imagin = 0;
	complex->c_real = -COOR_BOUNDARY;
	complex->c_imagin = -COOR_BOUNDARY;
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

void	multibrot_draw(t_complex *complex, t_img *img, int argc, char **argv)
{
	int		value;
	int		coor;
	double	d;

	d = complex_init(complex, argc, argv);
	while (complex->c_imagin <= COOR_BOUNDARY)
	{
		while (complex->c_real <= COOR_BOUNDARY)
		{
			coor = (complex->c_imagin + COOR_BOUNDARY) * 100 * WIDTH + \
				(complex->c_real + COOR_BOUNDARY) * 100;
			value = multibrot_calculation(complex, d);
			if (img->color == 1)
				coloring_green(coor, value, img);
			else
				coloring_blue(coor, value, img);
			complex->c_real += 0.01;
			complex->z_real = 0;
			complex->z_imagin = 0;
		}
		complex->c_imagin += 0.01;
		complex->c_real = -COOR_BOUNDARY;
	}
}
