/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myko <myko@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:07:48 by myko              #+#    #+#             */
/*   Updated: 2022/09/28 19:43:05 by myko             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	complex_init(t_complex *complex)
{
	complex->z_real = 0;
	complex->z_imagin = 0;
	complex->c_real = -COOR_BOUNDARY * complex->zoom;
	complex->c_imagin = -COOR_BOUNDARY * complex->zoom;
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
			+ complex->c_real * complex->zoom;
		y = 2 * complex->z_real * complex->z_imagin + complex->c_imagin;
		if ((pow(x, 2) + pow(y, 2)) > pow(BOUNDARY, 2))
			return (n);
		complex->z_real = x;
		complex->z_imagin = y;
	}
	return (MAX_REPEAT);
}

void	mandel_draw(t_complex *complex, t_img *img)
{
	int	value;
	int	coor;

	complex_init(complex);
	while (complex->c_imagin <= COOR_BOUNDARY * complex->zoom)
	{
		while (complex->c_real <= COOR_BOUNDARY * complex->zoom)
		{
			coor = (complex->c_imagin + COOR_BOUNDARY * complex->zoom) * (100.0 / complex->zoom) * WIDTH + \
				(complex->c_real + COOR_BOUNDARY * complex->zoom) * (100 / complex->zoom);
			value = mandelbrot_calculation(complex);
			if (img->color == 1)
				coloring_green(coor, value, img);
			else
				coloring_blue(coor, value, img);
			complex->c_real += 0.01 * complex->zoom;
			complex->z_real = 0;
			complex->z_imagin = 0;
		}
		complex->c_imagin += 0.01 * complex->zoom;
		complex->c_real = -COOR_BOUNDARY * complex->zoom;
	}
}
