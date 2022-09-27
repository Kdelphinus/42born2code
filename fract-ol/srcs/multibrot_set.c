/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/27 19:14:04 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	complex_init(t_complex *complex)
{
	complex->z_real = 0;
	complex->z_imagin = 0;
	complex->c_real = -COOR_BOUNDARY;
	complex->c_imagin = -COOR_BOUNDARY;
}

static int	multibrot_calculation(t_complex *complex)
{
	double	x;
	double	y;
	int		n;
	double	d;

	x = 0;
	y = 0;
	n = -1;
	d = 4;
	while (++n <= MAX_REPEAT)
	{
		x = pow(pow(complex->z_real, 2) + pow(complex->z_imagin, 2), d / 2.0) \
			* cos(d * atan2(complex->z_imagin, complex->z_real)) \
			+ complex->c_real;
		y = pow(pow(complex->z_real, 2) + pow(complex->z_imagin, 2), d / 2.0) \
			* sin(d * atan2(complex->z_imagin, complex->z_real)) \
			+ complex->c_imagin;
		if ((pow(x, d) + pow(y, d)) > pow(BOUNDARY, d))
			return (n);
		complex->z_real = x;
		complex->z_imagin = y;
	}
	return (n);
}

void	multibrot_draw(t_complex *complex, t_img *img)
{
	int	value;
	int	coor;

	complex_init(complex);
	while (complex->c_imagin <= COOR_BOUNDARY)
	{
		while (complex->c_real <= COOR_BOUNDARY)
		{
			coor = (complex->c_imagin + COOR_BOUNDARY) * 100 * WIDTH + \
				(complex->c_real + COOR_BOUNDARY) * 100;
			value = multibrot_calculation(complex);
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
